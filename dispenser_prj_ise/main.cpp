/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "DigitalOut.h"
#include "mbed.h"
#include <cstdio>
#include "ultrasonic.h"
#include "SH1106.h"
#include "serial_com.h"

#define WAIT_TIME 1500 //msec

DigitalOut led1(LED1);
DigitalOut outAlcohol(D0);
DigitalOut outEntry(D1);
DigitalOut outBuzzer(D2);

SH1106 gOled2(I2C_,400000,0x78,D14,D15,D3,"oled",128,64);
float temp = 0;

void dist(int distance)
{
    //put code here to happen when the distance is changed
    if (distance > 20 && distance < 100){
        
        gOled2.cls();
        gOled2.locate(0, 0);
        
        gOled2.printf("Mantega su mano en esa posicion \r\n");
        gOled2.printf("Temperatura medida: %.1f ºC \r\n",getTempO());
        gOled2.printf("Aplicando dosis de alcohol en gel... \r\n");
    } else {
        gOled2.cls();
        gOled2.locate(0, 0);
        gOled2.printf("Temperatura Ambiente: %.1f ºC \r\n",getTempA());
        gOled2.printf("Aproxime su mano para verificar su temperatura \r\n");
       
    }
    
}


void level(int level){
    gOled2.cls();
    gOled2.locate(0, 0);
    gOled2.printf("Nivel de alcohol: %d \r\n", level);
}

ultrasonic mu(D8, D9, .1, .02, &dist);

ultrasonic liquidLevel(D7, D6, 100, .1, &level);

int main()
{
    gOled2.cls();

   
    mu.startUpdates();//start mesuring the distance.
    liquidLevel.startUpdates(); //Start measuring alcohol level.

    commTempInit();
    gOled2.printf("Aproxime su mano para verificar su temperatura \r\n");
    while (true)
    {
        
        led1 = !led1;
        thread_sleep_for(100);
        commGetTempCMD();
        mu.checkDistance();
        liquidLevel.checkDistance();
        
    }
}
