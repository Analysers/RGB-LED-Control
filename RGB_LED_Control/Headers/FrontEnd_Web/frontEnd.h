// ********************************************************************************************
//                                     RGB_LED_Control                                                      
// --------------------------------------------------------------------------------------------
//
// File  : frontEnd.h
// Author: Gabriel da Silva Caetano <98gabrielSc@gmail.com>
//
// ********************************************************************************************

// ----------------------------------------------------------------------------------------- //

#ifndef _FRONT_END_WEB_H
#define _FRONT_END_WEB_H

// ----------------------------------------------------------------------------------------- //

#include <AsyncTCP.h>
#include <AsyncJson.h>
#include <ArduinoJson.h>
#include <ESPAsyncWebServer.h>

#include "HTML_Pages/rgbLedControl.h"

// ----------------------------------------------------------------------------------------- //

extern AsyncWebServer server;

// ----------------------------------------------------------------------------------------- //

void initializeRouters(void );
void initializeFrontEndWeb(void );
void pageNotFound(AsyncWebServerRequest *);
void servePage(AsyncWebServerRequest *, const char * , register uint16_t status = 200);

// ----------------------------------------------------------------------------------------- //

#endif

// ----------------------------------------------------------------------------------------- //
