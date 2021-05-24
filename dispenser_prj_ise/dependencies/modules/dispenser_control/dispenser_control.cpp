//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "dispenser_control.h"
#include <cstdint>


//=====[Declaration of private defines]======================================
#define POTENTIOMETER_TIME_LEVEL            2
//=====[Declaration of private data types]=====================================

DigitalOut outAlcohol(D0);
AnalogIn potentiometer(A0);
//=====[Declaration and initialization of public global objects]===============



//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============
float potentiometerReading = 0.0;
float timeGivingAlcohol = 0.0;
Ticker timerAlcohol;
//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================
void setTimeAlcohol(float value);
float getTimeAlcohol();
void timeDispenser();

//=====[Implementations of public functions]===================================

void alcoholControlInit(){
    outAlcohol = 0;
    timerAlcohol.attach(&timeDispenser, 5.0);
}

void timeDispenser() {
   potentiometerReading = potentiometer.read(); 
   setTimeAlcohol(potentiometerReading);
}


void giveAlcoholControl(){
    outAlcohol = 1;
    thread_sleep_for(uint32_t(getTimeAlcohol() * 1000));
    outAlcohol = 0;
}

void resetAlcoholControl(){
     outAlcohol = 0;
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