//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "SH1106.h"
#include "screen.h"
#include <cstdint>
//=====[Declaration of private defines]======================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============
SH1106 screenDisplay(I2C_,400000,0x78,D14,D15,D3,"oled",128,64);
//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void screenInit(){
    screenDisplay.cls();
    screenDisplay.set_orientation(3);
    screenDisplay.locate(0, 0);
    screenDisplay.set_font_zoom(1, 1);
    screenDisplay.printf("Iniciando...");
    screenDisplay.copy_to_lcd();
}

void screenClear(){
    screenDisplay.set_auto_up(false);
    screenDisplay.cls();
    screenDisplay.locate(0, 0);
}

void screenShowMainScreen(float ambT, float alcLevel, float timeOpen){
    screenDisplay.cls();
    screenDisplay.set_font_zoom(1, 1);
    screenDisplay.hline(0, 128, 0, 0xFFFF);
    //screenDisplay.printf("INGRESO PRINCIPAL\r\n");
    screenDisplay.locate(35, 5);
    screenDisplay.printf("BIENVENIDO\r\n");
    screenDisplay.locate(20, 15);
    screenDisplay.printf("ACERQUE SU MANO \r\n");

    screenDisplay.hline(0, 128, 26, 0xFFFF);
    screenDisplay.locate(0, 30);
    screenDisplay.printf("T amb: %.1f ºC\r\n",ambT);
    screenDisplay.locate(0, 42);
    screenDisplay.printf("Nivel Alc: %.1f %% \r\n",alcLevel);
    screenDisplay.locate(0, 52);
    screenDisplay.printf("T Alc: %.1f s \r\n\r",timeOpen);
    
    screenDisplay.copy_to_lcd();
}

void screenShowMeasureScreen(float tempO){
    screenDisplay.cls();
    screenDisplay.locate(0, 0);
    screenDisplay.hline(0, 128, 0, 0xFFFF);
    //screenDisplay.printf("INGRESO PRINCIPAL\r\n");
    screenDisplay.locate(40, 5);
    screenDisplay.printf("MIDIENDO\r\n");
    screenDisplay.locate(35, 15);
    screenDisplay.printf("TEMPERATURA \r\n");

    screenDisplay.hline(0, 128, 26, 0xFFFF);
    screenDisplay.locate(0, 30);
    screenDisplay.printf("Temp Instan: %.1f \r\n ",tempO);

    screenDisplay.hline(0, 128, 41, 0xFFFF);
    screenDisplay.locate(40, 43);
    screenDisplay.printf("POR FAVOR\r\n");
    screenDisplay.locate(15, 54);
    screenDisplay.printf("NO QUITE SU MANO \r\n");
    screenDisplay.copy_to_lcd();
}

void screenShowErrorScreen(){
    screenDisplay.cls();
    
    screenDisplay.hline(0, 128, 0, 0xFFFF);
    screenDisplay.locate(20, 5);
    screenDisplay.set_font_zoom(2, 2);
    screenDisplay.printf("ERROR!!! \r\n \r\n");
    screenDisplay.hline(0, 128, 25, 0xFFFF);
    screenDisplay.set_font_zoom(1, 1);
    screenDisplay.locate(20, 35);
    screenDisplay.printf("NO DEBE RETIRAR\r\n");
    screenDisplay.locate(25, 50);
    screenDisplay.printf("SU MANO ANTES\r\n");
    //screenDisplay.printf("NO retire su mano \r\n");
    //screenDisplay.printf("mientras esta \r\n \r\n");
    //screenDisplay.printf("Midiendo Temperatura");
    screenDisplay.copy_to_lcd();
}

void screenShowDoneScreen(float tempO){
    screenDisplay.cls();
    screenDisplay.locate(0,0);
    screenDisplay.hline(0, 128, 0, 0xFFFF);
    screenDisplay.locate(40,5);
    screenDisplay.set_font_zoom(2, 2);
    screenDisplay.printf("TEMP\r\n");
    screenDisplay.locate(20,25);
    screenDisplay.set_font_zoom(3, 3);
    screenDisplay.printf("%.1f C\r\n",tempO);
    screenDisplay.hline(0, 128, 50, 0xFFFF);
    screenDisplay.set_font_zoom(1, 1);
    screenDisplay.locate(0,55);
    screenDisplay.printf("No retire su mano... \r\n");
    screenDisplay.copy_to_lcd();
}

void screenShowOverTempScreen(){
    screenDisplay.cls();
    screenDisplay.locate(0,0);
    screenDisplay.hline(0, 128, 0, 0xFFFF);
    screenDisplay.locate(20,5);
    screenDisplay.set_font_zoom(2, 2);
    screenDisplay.printf("INGRESO\r\n");
    screenDisplay.locate(10,25);
    screenDisplay.set_font_zoom(2, 2);
    screenDisplay.printf("PROHIBIDO\r\n");
    screenDisplay.hline(0, 128, 40, 0xFFFF);
    screenDisplay.set_font_zoom(1, 1);
    screenDisplay.locate(0,52);
    screenDisplay.printf("VAYA A ADMINISTACION \r\n");
    screenDisplay.copy_to_lcd();
    
}

void screenShowUnderTempScreen(){
    screenDisplay.cls();
    screenDisplay.locate(0,0);
    screenDisplay.hline(0, 128, 0, 0xFFFF);
    screenDisplay.locate(40,5);
    screenDisplay.set_font_zoom(2, 2);
    screenDisplay.printf("TEMP\r\n");
    screenDisplay.locate(25,25);
    screenDisplay.set_font_zoom(2, 2);
    screenDisplay.printf("NORMAL\r\n");
    screenDisplay.hline(0, 128, 40, 0xFFFF);
    screenDisplay.set_font_zoom(1, 1);
    screenDisplay.locate(0,52);
    screenDisplay.printf("ENTREGANDO ALCOHOL... \r\n");
    screenDisplay.copy_to_lcd();
}

void screenShowInScreen(){
    screenDisplay.cls();
    screenDisplay.locate(0,0);
    screenDisplay.set_font_zoom(3, 3);
    screenDisplay.printf("INGRESE\r\n");
    screenDisplay.hline(0, 128, 26, 0xFFFF);
    screenDisplay.set_font_zoom(2, 2);
    screenDisplay.locate(15,30);
    screenDisplay.printf("ABRIENDO\r\n");
    screenDisplay.locate(25,48);
    screenDisplay.printf("PUERTA");
    screenDisplay.copy_to_lcd();
    // screenDisplay.cls();
    // screenDisplay.locate(0,0);

    // screenDisplay.printf("Abra la puerta \r\n");
    // screenDisplay.printf("Por favor \r\n");
    
    
    // screenDisplay.copy_to_lcd();
}

void screenShowAlcoholScreen(){
    screenDisplay.cls();
    screenDisplay.locate(0,0);

    screenDisplay.printf("Entregando Alcohol \r\n");
    screenDisplay.printf("Por favor \r\n");
    screenDisplay.printf("No Retire \r\n");
    screenDisplay.printf("SU MANO \r\n");
    screenDisplay.copy_to_lcd();
}