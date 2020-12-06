// ********************************************************************************************
//                                     RGB_LED_Control                                                      
// --------------------------------------------------------------------------------------------
//
// File  : buttonControl.cpp
// Author: Gabriel da Silva Caetano <98gabrielSc@gmail.com>
//
// ********************************************************************************************

// ----------------------------------------------------------------------------------------- //

#include "Headers/serial.h"
#include "Headers/ledControl.h"
#include "Headers/buttonControl.h"

// ----------------------------------------------------------------------------------------- //

ButtonControl buttonControl;
TaskHandle_t handleButtonDebounce;

// ----------------------------------------------------------------------------------------- //

// ########### ********************************************************************************
//
// Function   : initializeGPIOButton
//
// Parameters : void
// Return     : void
//
// Description: Initializes the GPIO of the button
//
// ########### ********************************************************************************

void initializeGPIOButton(void ) {

    pinMode(GPIO_BUTTON, INPUT_PULLUP);
    
}

// ########### ********************************************************************************
//
// Function   : initializeInterruptButtonControl
//
// Parameters : void
// Return     : void
//
// Description: 
//
// ########### ********************************************************************************

void initializeInterruptButtonControl(void ) {

    attachInterrupt(GPIO_BUTTON, interruptButtonControl, FALLING);
    
}

// ########### ********************************************************************************
//
// Function   : interruptButtonControl
//
// Parameters : void
// Return     : void
//
// Description: 
//
// ########### ********************************************************************************

void IRAM_ATTR interruptButtonControl() {

    if(buttonControl.state == _READING && buttonControl.debounceTime == 0) {
        buttonControl.state = _IN_DEBOUNCE;
        buttonControl.debounceTime = DEBOUNCE_TIME;
        vTaskResume(handleButtonDebounce);
    }
    
}

// ########### ********************************************************************************
//
// Function   : taskButtonDebounce
//
// Parameters : void
// Return     : void
//
// Description: 
//
// ########### ********************************************************************************

void initializeTaskButtonDebounce(void ) {

    xTaskCreatePinnedToCore(taskButtonDebounce,    // Callback
                            "TaskButtonDebounce",  // Name of the task
                            2000,                  // Stack size
                            NULL,                  // Parameters 
                            1,                     // Priority
                            &handleButtonDebounce, // Handle
                            PRO_CPU_NUM);          // CPU - core

    vTaskSuspend(handleButtonDebounce);

}

// ########### ********************************************************************************
//
// Function   : taskButtonDebounce
//
// Parameters : void
// Return     : void
//
// Description: 
//
// ########### ********************************************************************************

void taskButtonDebounce(void * pvParameters) {

    while(1) {

        detachInterrupt(GPIO_BUTTON);

        vTaskDelay( BASE_DEBOUNCE_TIME / portTICK_PERIOD_MS );
        if(buttonControl.state == _IN_DEBOUNCE && buttonControl.debounceTime != 0) {
            buttonControl.debounceTime--;
            if(buttonControl.debounceTime == 0) {

                buttonControl.state = _READING;
                if(digitalRead(GPIO_BUTTON) == LOW) {
                    ledControl.status = !ledControl.status;
                    manageLedStatus();
                }

                initializeInterruptButtonControl();
                vTaskSuspend(handleButtonDebounce);
            }
        }
    }
}