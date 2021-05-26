//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "ultrasonic.h"
#include "distance_hand_control.h"
//=====[Declaration of private defines]======================================

//=====[Declaration of private data types]=====================================


void checkDistance();
void setHandDistance(uint16_t dist);
//=====[Declaration and initialization of public global objects]===============



//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============
void refreshDistance(int dist){
    setHandDistance(dist);
}

ultrasonic handDistance(D8, D9, .5, .1, &refreshDistance);
bool distLevel = false;
Ticker timer;
//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void handDistanceInit(){
    handDistance.startUpdates(); //Start measuring hand distance
    timer.attach(&checkDistance, 0.01);
}

void checkDistance(){
    handDistance.checkDistance();
}

void setHandDistance(uint16_t dist){
    if (dist < 100){
        distLevel = true;
    }else {
        distLevel = false;
    }
    
}

bool getHandDistance(){
    return distLevel;
}