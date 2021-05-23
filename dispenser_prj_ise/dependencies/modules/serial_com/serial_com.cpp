//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "serial_com.h"

#include <cstdint>
#include <cstring>
#include <mutex>



//=====[Declaration of private defines]======================================
#define BUFFER_SIZE 50
//=====[Declaration of private data types]=====================================

typedef enum{
    PC_SERIAL_COMMANDS,
    PC_SERIAL_GET_CODE,
    PC_SERIAL_SAVE_NEW_CODE,
} pcSerialComMode_t;

//=====[Declaration and initialization of public global objects]===============

Serial pc(SERIAL_TX, SERIAL_RX);
Serial uartComm(PD_1, PD_0);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============


//=====[Declaration and initialization of private global variables]============

static pcSerialComMode_t pcSerialComMode = PC_SERIAL_COMMANDS;
static bool dataReady = false;
static int numberOfCodeChars = 0;
static char auxBuffer[BUFFER_SIZE];
static char buffer[BUFFER_SIZE];
static int indexBuffer = 0;

static float varTempA = 0.0;
static float varTempO = 0.0;
//=====[Declarations (prototypes) of private functions]========================


void commTempInit();
void commStringWrite( const char* str );
void commTempUpdate();
void commGetData(char* buff);
void getSubStr(char* str, char init, char end, char *strOut);
void setTempA(float ambient);
float getTempA();
float getTempO();
void setTempO(float body);
//=====[Implementations of public functions]===================================

/* 
    Funcion de callback para la interrupcion por puerto serie
    Se esperan que los datos lleguen cuando se envia el cmd de pedido de temp.
*/
void callback(){
    commTempUpdate();
        
}


void commTempInit()
{
    pc.printf("Inicio de serial");
    uartComm.attach(&callback);
}


void commGetTempCMD()
{
    uartComm.puts("GETtC");
    
}

void commTempUpdate()
{
    /* Leo un caracter y observo que sea la respuesta del sensor MLX */
    /* La respuesta esperada es del tipo >TA:00,0-TO:00,0; */
    //pc.printf("buff: %s",buff);
    
    
    char receivedChar = '\0';
          
    
    
    while (uartComm.readable()) {
        receivedChar = uartComm.getc();
        auxBuffer[indexBuffer++] = receivedChar;
        //pc.putc(receivedChar);
    }
    

    // Caracter de finalizacion de trama
    if (receivedChar == ';'){
        //pc.printf("char : receive\r\n");
        //
        //pc.printf("buff: %s \r\n",auxBuffer);
        memset(buffer,0,sizeof(buffer));
        memcpy(buffer, auxBuffer, sizeof(auxBuffer));
        memset(auxBuffer,0,sizeof(auxBuffer));
        indexBuffer = 0;
        commGetData(buffer);
    }
        
}


void commGetData(char* buff){
    int initPos = 0;
    int endPos = 0;
    char auxStr[BUFFER_SIZE];
    int length = 0;

    memset(auxBuffer,0,sizeof(auxBuffer));
    // Obtengo la temperatura ambiente
    getSubStr(buff, ':', '-', auxStr);
    setTempA(stof(auxStr));
    // Obtengo la temperatura del cuerpo
    memset(auxBuffer,0,sizeof(auxBuffer));
    getSubStr(buff, ':', ';', auxStr);
    setTempO(stof(auxStr));
    pc.printf("Temp Amb: %.1f - Temp Obj: %.1f\r\n",getTempA(),getTempO());

}

void getSubStr(char* str, char init, char end, char *strOut){
    int initPos = 0;
    int endPos = 0;
    for (int i=0; i<strlen(str); i++){
        if (str[i] == init){
            initPos = i+1;
        }
        if (str[i] == end){
            endPos = i-1;
            break;
        }
    }
    if (endPos != 0){
        strncpy(strOut, &str[initPos], (endPos - initPos));
    }

}

void setTempA(float ambient){
    varTempA = ambient;
}

void setTempO(float body){
    varTempO = body;
}


float getTempA(){
    return varTempA;
}

float getTempO(){
    return varTempO;
}

