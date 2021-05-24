//=====[#include guards - begin]===============================================

#ifndef _BUZZER_CONTROL_H_
#define _BUZZER_CONTROL_H_

#include "mbed.h"
#include <cstdint>
//=====[Libraries]=============================================================

//=====[Declaration of public defines]=======================================

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================



void sirenInit();
bool sirenStateRead();
void sirenStateWrite( bool state );
void sirenUpdate( int strobeTime );


//=====[#include guards - end]=================================================

#endif // _BUZZER_CONTROL_H_