//=====[Libraries]=============================================================

#include "PinNames.h"
#include "mbed.h"
#include "arm_book_lib.h"

#include "buzzer_control.h"


//=====[Declaration of private defines]======================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

PwmOut buzzerPin(PE_10);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

static bool buzzerState = OFF;
static int currentStrobeTime = 0;

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void buzzerInit()
{
  buzzerPin.period(1.0f);
  buzzerPin.write(0.0f);
}

bool buzzerStateRead()
{
    return buzzerState;
}

void buzzerStateWrite( bool state )
{
    buzzerState = state;
}

void buzzerUpdate( int strobeTime )
{
    if( buzzerState ) {
        if (currentStrobeTime != strobeTime) {
          buzzerPin.period((float)strobeTime * 2 / 1000);
          buzzerPin.write(0.5f);
          currentStrobeTime = strobeTime;
        }
    } else {
      buzzerPin.write(0.0f);
      currentStrobeTime = 0;
    }
}

//=====[Implementations of private functions]==================================