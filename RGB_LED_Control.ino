// ********************************************************************************************
//                                     RGB_LED_Control                                                      
// --------------------------------------------------------------------------------------------
//
// File  : RGB_LED_Control.ino
// Author: Gabriel da Silva Caetano <98gabrielSc@gmail.com>
//
// ********************************************************************************************

// ----------------------------------------------------------------------------------------- //

#include "Headers/serial.h"
#include "Headers/ledControl.h"
#include "Headers/buttonControl.h"
#include "Headers/wifi_accessPoint.h"
#include "Headers/FrontEnd_Web/frontEnd.h"

// ----------------------------------------------------------------------------------------- //

// ----------------------------------------------------------------------------------------- //

// ########### ********************************************************************************
//
// Function   : setup
//
// Parameters : void
// Return     : void
//
// Description: General system setup
//
// ########### ********************************************************************************

void setup(void ) {

    initializeSerial();
    initializeWiFiAccessPoint();
    initializeFrontEndWeb();

    initializeGPIOLed();
    manageLedStatus();

    initializeGPIOButton();
    initializeTaskButtonDebounce();
    initializeInterruptButtonControl();
}

// ########### ********************************************************************************
//
// Function   : loop
//
// Parameters : void
// Return     : void
//
// Description: General system loop
//
// ########### ********************************************************************************

void loop(void ) {

}