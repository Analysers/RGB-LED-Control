// ********************************************************************************************
//                                     RGB_LED_Control                                                      
// --------------------------------------------------------------------------------------------
//
// File  : buttonControl.cpp
// Author: Gabriel da Silva Caetano <98gabrielSc@gmail.com>
//
// ********************************************************************************************

// ----------------------------------------------------------------------------------------- //

#ifndef _BUTTON_CONTROL_H
#define _BUTTON_CONTROL_H

// ----------------------------------------------------------------------------------------- //

#include <Arduino.h>

// ----------------------------------------------------------------------------------------- //

#define GPIO_BUTTON             36
#define BASE_DEBOUNCE_TIME      100 // ms
#define DEBOUNCE_TIME           (100/BASE_DEBOUNCE_TIME)

enum StateButtonControl {

    _READING = 0,
    _IN_DEBOUNCE,

};

struct __attribute__((packed)) ButtonControl {

    uint8_t lastState = HIGH;
    uint8_t state = _READING;
    uint8_t debounceTime = 0;
    uint8_t currentState = HIGH;

};

extern ButtonControl buttonControl;

// ----------------------------------------------------------------------------------------- //

void taskButtonDebounce(void *);
void initializeGPIOButton(void );
void IRAM_ATTR interruptButtonControl();
void initializeTaskButtonDebounce(void );
void initializeInterruptButtonControl(void );

// ----------------------------------------------------------------------------------------- //

#endif

// ----------------------------------------------------------------------------------------- //
