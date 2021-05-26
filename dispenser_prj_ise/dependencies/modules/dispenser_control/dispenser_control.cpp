//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "dispenser_control.h"
#include <cstdint>


//=====[Declaration of private defines]======================================
#define POTENTIOMETER_TIME_LEVEL            5
//=====[Declaration of private data types]=====================================

DigitalOut outAlcohol(D0);
AnalogIn potentiometer(A0);
//=====[Declaration and initialization of public global objects]===============



//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============
float potentiometerReading = 0.0;
float timeGivingAlcohol = 0.0;
bool isDone = false;
Ticker timerAlcohol;
//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================
void setTimeAlcohol(float value);
float getTimeAlcohol();
void timeDispenser();

//=====[Implementations of public functions]===================================

void alcoholControlInit(){
    outAlcohol = ON;
    isDone = false;
    timerAlcohol.attach(&timeDispenser, 1.0);
}

void timeDispenser() {
   potentiometerReading = potentiometer.read(); 
   setTimeAlcohol(potentiometerReading);
}


void giveAlcoholControl(){
    outAlcohol = OFF;
    isDone = false;
    thread_sleep_for(uint32_t(getTimeAlcohol() * 1000));
    isDone = true;
    outAlcohol = ON;
}

void resetAlcoholControl(){
     outAlcohol = ON;
     isDone = false;
}


void setTimeAlcohol(float value){
    if (value != 0.0){
        timeGivingAlcohol = value * POTENTIOMETER_TIME_LEVEL;
    }else{
        timeGivingAlcohol = 1;
    }
    
}

float getTimeAlcohol(){
    return timeGivingAlcohol;
}

bool isAlcoholDone(){
    return isDone;
}