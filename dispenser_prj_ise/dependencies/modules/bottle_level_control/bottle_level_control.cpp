//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "ultrasonic.h"
#include "bottle_level_control.h"
#include <cstdint>


//=====[Declaration of private defines]======================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============



//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============
ultrasonic liquid(D7, D6, 100, .1);
uint8_t liquidLevel = 0;
Ticker timerLevel;
//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================
void refreshLevel();
void setLiquidLevel(uint16_t liquid);
//=====[Implementations of public functions]===================================

void liquidControlInit(){
    liquid.startUpdates(); //Start measuring alcohol level.
    timerLevel.attach(&refreshLevel, 5.0);
}

void refreshLevel(){
    setLiquidLevel(liquid.getCurrentDistance());
}

void setLiquidLevel(uint16_t liquid){
    if (liquid >= 1000){
        liquidLevel = 100;
    }else if (liquid <=100){
        liquidLevel = 1;
    }else {
        liquidLevel = liquid * 0.01;
    }
    
}

uint8_t getLiquidLevel(){
    return liquidLevel;
}
