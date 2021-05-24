//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "ultrasonic.h"
#include "distance_hand_control.h"
//=====[Declaration of private defines]======================================

//=====[Declaration of private data types]=====================================


void refreshDistance();
void setHandDistance(uint16_t dist);
//=====[Declaration and initialization of public global objects]===============



//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============
ultrasonic handDistance(D8, D9, .5, .1);
bool distLevel = false;
Ticker timer;
//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void handDistanceInit(){
    handDistance.startUpdates(); //Start measuring hand distance
    timer.attach(&refreshDistance, 0.5);
}

void refreshDistance(){
    setHandDistance(handDistance.getCurrentDistance());
}

void setHandDistance(uint16_t dist){
    if (dist > 20 && dist < 100){
        distLevel = true;
    }else {
        distLevel = false;
    }
    
}

bool getHandDistance(){
    return distLevel;
}