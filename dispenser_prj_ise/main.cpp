/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "system_control.h"



int main()
{

    systemInit();
    
    while (true)
    {
        systemRun();
    }
}
