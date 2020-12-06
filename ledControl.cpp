// ********************************************************************************************
//                                     RGB_LED_Control                                                      
// --------------------------------------------------------------------------------------------
//
// File  : ledControl.cpp
// Author: Gabriel da Silva Caetano <98gabrielSc@gmail.com>
//
// ********************************************************************************************

// ----------------------------------------------------------------------------------------- //

#include "Headers/serial.h"
#include "Headers/ledControl.h"

// ----------------------------------------------------------------------------------------- //

RGBLedControl ledControl;

// ----------------------------------------------------------------------------------------- //

// ########### ********************************************************************************
//
// Function   : initializeGPIOLed
//
// Parameters : void
// Return     : void
//
// Description: Initializes the GPIO of the led
//
// ########### ********************************************************************************

void initializeGPIOLed(void ) {

    pinMode(GPIO_LED_RED, OUTPUT);
    ledcAttachPin(GPIO_LED_RED, CHANNEL_LED_RED); // Connects the pin to channel 0
    ledcSetup(CHANNEL_LED_RED, 1000, 8); // Channel, Frequency, Resolution

    pinMode(GPIO_LED_BLUE, OUTPUT); 
    ledcAttachPin(GPIO_LED_BLUE, CHANNEL_LED_BLUE); // Connects the pin to channel 1
    ledcSetup(CHANNEL_LED_BLUE, 1000, 8); // Channel, Frequency, Resolution

    pinMode(GPIO_LED_GREEN, OUTPUT); 
    ledcAttachPin(GPIO_LED_GREEN, CHANNEL_LED_GREEN); // Connects the pin to channel 2
    ledcSetup(CHANNEL_LED_GREEN, 1000, 8); // Channel, Frequency, Resolution
    
}

// ########### ********************************************************************************
//
// Function   : turnOffLed
//
// Parameters : void
// Return     : void
//
// Description: Turn off the led
//
// ########### ********************************************************************************

void turnOffLed(void ) {

    ledcWrite(CHANNEL_LED_RED, 0);
    ledcWrite(CHANNEL_LED_BLUE, 0);
    ledcWrite(CHANNEL_LED_GREEN, 0);

}

// ########### ********************************************************************************
//
// Function   : updateRGBLedControl
//
// Parameters : void
// Return     : void
//
// Description: Turn on the led
//
// ########### ********************************************************************************

void updateRGBLedControl(void ) {

    ledcWrite(CHANNEL_LED_RED, ledControl.R);
    ledcWrite(CHANNEL_LED_BLUE, ledControl.B);
    ledcWrite(CHANNEL_LED_GREEN, ledControl.G);

}

// ########### ********************************************************************************
//
// Function   : manageLedStatus
//
// Parameters : void
// Return     : void
//
// Description: 
//
// ########### ********************************************************************************

void manageLedStatus(void ) {

    if(ledControl.status) {
        updateRGBLedControl();
    } else {
        turnOffLed();
    }

}