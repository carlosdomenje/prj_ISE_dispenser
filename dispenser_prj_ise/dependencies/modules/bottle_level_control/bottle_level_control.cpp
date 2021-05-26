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

float liquidLevel = 0.0;
Ticker timerLevel;

//=====[Declaration and initialization of private global variables]============
void setLiquidLevel(uint16_t liquid){
    if (liquid >= 200){
        liquidLevel = 100;
    }else if (liquid <= 30){
        liquidLevel = 1;
    }else {
        liquidLevel = (liquid * 100) / 200;
    }
    
}

void refreshLevel(int level){
    setLiquidLevel(level);
}
//=====[Declarations (prototypes) of private functions]========================
void refreshLevel();
void checkLevel();
void setLiquidLevel(uint16_t liquid);
//=====[Implementations of public functions]===================================

ultrasonic liquid(D7, D6, 1, .1, &refreshLevel);

void liquidControlInit(){
    
    liquid.startUpdates(); //Start measuring alcohol level.
    timerLevel.attach(&checkLevel, 0.1);
}

void checkLevel(){
    liquid.checkDistance();
}


float getLiquidLevel(){
    return liquidLevel;
}
