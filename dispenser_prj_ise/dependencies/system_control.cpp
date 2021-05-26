//=====[Libraries]=============================================================

#include "Ticker.h"
#include "mbed.h"
#include "arm_book_lib.h"
#include "access_control.h"
#include "bottle_level_control.h"
#include "dispenser_control.h"
#include "distance_hand_control.h"
#include "screen.h"
#include "serial_com.h"
#include <cstdint>
#include <tuple>

//=====[Declaration of private defines]======================================

#define SYS_1_MS            10
#define SYS_10_MS           100
#define SYS_100_MS          1000
#define SYS_1000_MS         10000
#define MAX_TEMP_MEASURES   50
#define MAX_TEMP_BODY       37.5
//=====[Declaration of private data types]=====================================



//=====[Declaration and initialization of public global objects]===============

Ticker timerTask;

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============


//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================
void systemTask();

enum sysProcess{
    SYS_INIT            = 0,
    SYS_HAND_APROX      = 1,
    SYS_TEMP_MEASURE    = 2,
    SYS_ALCOHOL_EXP     = 3
} systemProcess;

    uint32_t _tsk_1_ms       = 0;
    uint32_t _tsk_10_ms      = 0;
    uint32_t _tsk_100_ms     = 0;
    uint32_t _tsk_1000_ms    = 0;

struct sysTasks {
    bool isProcess      = false; 
    bool isMeasuring    = false;     
    bool isDone         = false;
    bool isError        = false;
    bool alcoholDone    = false;
    uint8_t cntMeasures = 0;
    float finalTemp     = 0.0;
} _sysTask;

double accTempO = 0;
//=====[Implementations of public functions]===================================
DigitalOut led1(LED1);

void systemInit()
{
    accessControlInit();
    liquidControlInit();
    alcoholControlInit();
    handDistanceInit();
    commTempInit();
    screenInit();
    
    timerTask.attach_us(&systemTask, 100);
    screenClear();
    
}  


void systemTask(){
    _tsk_1_ms++;
    _tsk_10_ms++;
    _tsk_100_ms++;
    _tsk_1000_ms++;

}

void systemRun(){

    if (_tsk_1_ms > SYS_1_MS){
        _tsk_1_ms = 0;
    }

    if (_tsk_10_ms > SYS_10_MS){
        _tsk_10_ms = 0;
        
        if (_sysTask.isMeasuring){
            if (!getHandDistance()){
                _sysTask.isError = true;
                _sysTask.finalTemp = 0;
                _sysTask.cntMeasures = 0;
                accTempO = 0;
            }
        }
    }

    if (_tsk_100_ms > SYS_100_MS){
        _tsk_100_ms = 0;
        commGetTempCMD();
        if (getHandDistance()) {
            _sysTask.isProcess = true;
            _sysTask.isMeasuring = true;
            _sysTask.isError = false;
        }else {
            _sysTask.isProcess = false;
        }

        if (_sysTask.isProcess && _sysTask.isMeasuring && !_sysTask.isDone){
            _sysTask.cntMeasures ++;
            if (_sysTask.cntMeasures >= MAX_TEMP_MEASURES){
                _sysTask.cntMeasures = 0;
                _sysTask.finalTemp = accTempO / MAX_TEMP_MEASURES;
                _sysTask.isDone = true;
            }else{
                accTempO += getTempO();
            }
        }
    }

    if (_tsk_1000_ms > SYS_1000_MS){
        _tsk_1000_ms = 0;
        led1 = !led1;
        if (!_sysTask.isProcess && !_sysTask.isError){
            screenShowMainScreen(getTempO(), getLiquidLevel(), getTimeAlcohol());         
        }else {           
            if (_sysTask.isMeasuring && !_sysTask.isError) {
                screenShowMeasureScreen(getTempO());
            }

            if (_sysTask.isError && !_sysTask.isDone){
                screenShowErrorScreen();
                _sysTask.isMeasuring = false;
                _sysTask.isError = false;
                thread_sleep_for(5000);
            }

            if (_sysTask.isDone){
                screenShowDoneScreen(_sysTask.finalTemp);
                thread_sleep_for(5000);
                if (_sysTask.finalTemp > MAX_TEMP_BODY){
                    screenShowOverTempScreen();
                    thread_sleep_for(10000);
                    _sysTask.isMeasuring = false;
                    _sysTask.isError = false;
                    _sysTask.isDone = false;
                    _sysTask.isProcess = false;
                    _sysTask.finalTemp = 0;
                    accTempO = 0;
                    _sysTask.cntMeasures = 0;
                }else {
                    screenShowUnderTempScreen();
                    
                    giveAlcoholControl();
                    if (isAlcoholDone()){
                        _sysTask.alcoholDone = true;
                        _sysTask.isDone = false;
                    }
                    
                    //thread_sleep_for(10000);
                    //screenShowInScreen();
                    //giveAccessControl();
                    //thread_sleep_for(10000);
                }
            }

            if (_sysTask.alcoholDone){
                screenShowInScreen();
                thread_sleep_for(1000);
                giveAccessControl();
                _sysTask.isMeasuring = false;
                _sysTask.alcoholDone = false;
                _sysTask.isError = false;
                _sysTask.isDone = false;
                _sysTask.isProcess = false;
                _sysTask.finalTemp = 0;
                accTempO = 0;
                _sysTask.cntMeasures = 0;
            }
        }
        
    }
}