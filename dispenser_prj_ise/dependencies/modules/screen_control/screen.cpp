//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "screen.h"
//=====[Declaration of private defines]======================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============
SH1106 screenDisplay(I2C_,400000,0x78,D14,D15,D3,"oled",128,64);
//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void screenInit(){
    screenDisplay.cls();
    screenDisplay.locate(0, 0);
    screenDisplay.printf("Hola...");
}
