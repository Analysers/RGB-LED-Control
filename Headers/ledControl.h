// ********************************************************************************************
//                                     RGB_LED_Control                                                      
// --------------------------------------------------------------------------------------------
//
// File  : ledControl.cpp
// Author: Gabriel da Silva Caetano <98gabrielSc@gmail.com>
//
// ********************************************************************************************

// ----------------------------------------------------------------------------------------- //

#ifndef _LED_CONTROL_H
#define _LED_CONTROL_H

// ----------------------------------------------------------------------------------------- //

#include <Arduino.h>

// ----------------------------------------------------------------------------------------- //

enum GPIORGBLedControl {

    GPIO_LED_RED = 25,
    GPIO_LED_BLUE,
    GPIO_LED_GREEN

};

enum ChannelRGBLedControl {

    CHANNEL_LED_RED = 0,
    CHANNEL_LED_BLUE,
    CHANNEL_LED_GREEN

};

struct __attribute__((packed)) RGBLedControl {

    uint8_t status = 1;
    uint8_t R = 127;
    uint8_t G = 127;
    uint8_t B = 127;

};

extern RGBLedControl ledControl;

// ----------------------------------------------------------------------------------------- //

void turnOffLed(void );
void manageLedStatus(void );
void initializeGPIOLed(void );
void updateRGBLedControl(void );

// ----------------------------------------------------------------------------------------- //

#endif

// ----------------------------------------------------------------------------------------- //
