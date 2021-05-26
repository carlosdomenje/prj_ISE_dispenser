//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "access_control.h"


//=====[Declaration of private defines]======================================

//=====[Declaration of private data types]=====================================



//=====[Declaration and initialization of public global objects]===============

DigitalOut outEntry(D1);


//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============


//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================



//=====[Implementations of public functions]===================================



void accessControlInit()
{
    outEntry = ON;
}

void giveAccessControl(){
    outEntry = OFF;
    thread_sleep_for(2000);
    outEntry = ON;
}

void resetAccessControl(){
    outEntry = ON;
}