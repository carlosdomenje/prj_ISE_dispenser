//=====[#include guards - begin]===============================================

#ifndef _DISPENSER_CONTROL_H_
#define _DISPENSER_CONTROL_H_

#include "mbed.h"
#include <cstdint>
#include "DigitalOut.h"
//=====[Libraries]=============================================================

//=====[Declaration of public defines]=======================================

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================



void alcoholControlInit();

void giveAlcoholControl();
void resetAlcoholControl();



//=====[#include guards - end]=================================================

#endif // _DISPENSER_CONTROL_H_