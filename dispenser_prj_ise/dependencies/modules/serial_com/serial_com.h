//=====[#include guards - begin]===============================================

#ifndef _SERIAL_COM_H_
#define _SERIAL_COM_H_

#include "mbed.h"
#include <cstdint>
//=====[Libraries]=============================================================

//=====[Declaration of public defines]=======================================

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================


void commTempInit();
void commStringWrite( const char* str );
void commGetTempCMD();
void commTempUpdate();


float getTempA();
float getTempO();



//=====[#include guards - end]=================================================

#endif // _SERIAL_COM_H_