//=====[#include guards - begin]===============================================

#ifndef _SCREEN_H_
#define _SCREEN_H_

#include "mbed.h"
//#include "SH1106.h"
#include <cstdint>
//=====[Libraries]=============================================================

//=====[Declaration of public defines]=======================================

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================


void screenInit();
void screenClear();
void screenShowMainScreen(float ambT, float alcLevel, float timeOpen);
void screenShowMeasureScreen(float tempO);
void screenShowDoneScreen(float tempO);
void screenShowErrorScreen();
void screenShowOverTempScreen();
void screenShowUnderTempScreen();
void screenShowInScreen();
void screenShowAlcoholScreen();

//=====[#include guards - end]=================================================

#endif // _SCREEN_H_