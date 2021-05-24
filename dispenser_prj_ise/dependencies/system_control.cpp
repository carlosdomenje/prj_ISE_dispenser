//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "access_control.h"
#include "bottle_level_control.h"
#include "buzzer_control.h"
#include "dispenser_control.h"
#include "distance_hand_control.h"
#include "screen.h"
#include "serial_com.h"

//=====[Declaration of private defines]======================================

//=====[Declaration of private data types]=====================================



//=====[Declaration and initialization of public global objects]===============



//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============


//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================



//=====[Implementations of public functions]===================================


void systemInit()
{
    accessControlInit();
    liquidControlInit();
    buzzerInit();
    alcoholControlInit();
    handDistanceInit();
    commTempInit();
    screenInit();
}
