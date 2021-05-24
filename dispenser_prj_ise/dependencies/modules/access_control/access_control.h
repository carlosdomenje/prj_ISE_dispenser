//=====[#include guards - begin]===============================================

#ifndef _ACCESS_CONTROL_H_
#define _ACCESS_CONTROL_H_

#include "mbed.h"
#include <cstdint>
//=====[Libraries]=============================================================
#include "DigitalOut.h"

//=====[Declaration of public defines]=======================================

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================

void giveAccessControl();
void resetAccessControl();
void accessControlInit();



//=====[#include guards - end]=================================================

#endif // _ACCESS_CONTROL_H_