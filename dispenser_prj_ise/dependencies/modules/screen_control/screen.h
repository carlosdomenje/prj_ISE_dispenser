//=====[#include guards - begin]===============================================

#ifndef _SCREEN_H_
#define _SCREEN_H_

#include "mbed.h"
#include "SH1106.h"
#include <cstdint>
//=====[Libraries]=============================================================

//=====[Declaration of public defines]=======================================

//=====[Declaration of public data types]======================================
SH1106 screen(I2C_,400000,0x78,D14,D15,D3,"oled",128,64);
//=====[Declarations (prototypes) of public functions]=========================


void screenInit();



//=====[#include guards - end]=================================================

#endif // _SCREEN_H_