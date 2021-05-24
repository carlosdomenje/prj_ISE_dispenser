//=====[#include guards - begin]===============================================

#ifndef _BUZZER_CONTROL_H_
#define _BUZZER_CONTROL_H_

#include "mbed.h"
#include <cstdint>
//=====[Libraries]=============================================================

//=====[Declaration of public defines]=======================================

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================



void buzzerInit();
bool buzzerStateRead();
void buzzerStateWrite( bool state );
void buzzerUpdate( int strobeTime );


//=====[#include guards - end]=================================================

#endif // _BUZZER_CONTROL_H_