// ********************************************************************************************
//                                     RGB_LED_Control                                                      
// --------------------------------------------------------------------------------------------
//
// File  : frontEnd_web.cpp
// Author: Gabriel da Silva Caetano <98gabrielSc@gmail.com>
//
// ********************************************************************************************

// ----------------------------------------------------------------------------------------- //

#include "Headers/serial.h"
#include "Headers/ledControl.h"
#include "Headers/FrontEnd_Web/frontEnd.h"

// ----------------------------------------------------------------------------------------- //

AsyncWebServer server(80);

// ----------------------------------------------------------------------------------------- //

// ########### ********************************************************************************
//
// Function   : initializeFrontEndWeb
//
// Parameters : void
// Return     : void
//
// Description: Inicializa o servidor que possibilitará o acesso ao frontend web
//
// ########### ********************************************************************************

void initializeFrontEndWeb(void ) {

    initializeRouters();
    server.begin();

}

// ########### ********************************************************************************
//
// Function   : initializeRouters
//
// Parameters : void
// Return     : void
//
// Description: Inicializa as rotas
//
// ########### ********************************************************************************

void initializeRouters(void ) {

    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        servePage(request, htmlPageRGBLedControl, 200);
    });

    server.on("/getDataLed", HTTP_GET, [](AsyncWebServerRequest *request) {
        if(ON_AP_FILTER(request)) {
            AsyncJsonResponse *response = new AsyncJsonResponse();
            JsonObject jsonObject = response->getRoot();
            jsonObject[F("status")] = ledControl.status;
            jsonObject[F("R")] = ledControl.R;
            jsonObject[F("G")] = ledControl.G;
            jsonObject[F("B")] = ledControl.B;
            response->setLength();
            request->send(response);
        } else {
            request->send(400, F("text/html"), "");
        }
    });

    AsyncCallbackJsonWebHandler* handlerSetDataLed = new AsyncCallbackJsonWebHandler("/setDataLed", [](AsyncWebServerRequest *request, JsonVariant &jsonData) {
        if(ON_AP_FILTER(request)) {

            JsonObject jsonLedControl = jsonData.as<JsonObject>();
            
            ledControl.status = jsonLedControl[F("status")].as<uint8_t>();
            ledControl.R = jsonLedControl[F("R")].as<uint8_t>();
            ledControl.G = jsonLedControl[F("G")].as<uint8_t>();
            ledControl.B = jsonLedControl[F("B")].as<uint8_t>();
            
            request->send(200, F("text/html"), F(""));
            
            manageLedStatus();

        } else {
            request->send(400, F("text/html"), "");
        }
    });
    server.addHandler(handlerSetDataLed);

}

// ########### ********************************************************************************
//
// Function   : servePage
//
// Parameters : AsyncWebServerRequest *request -> ponteiro para a requisição do 'browser'
//              const char *page -> página à ser 'servida'
//              register uint16_t status -> status da requisição
// Return     : void
//
// Description: Serve uma página HTML ao 'browser'
//
// ########### ********************************************************************************

void servePage(AsyncWebServerRequest *request, const char *page, register uint16_t status) {

    if(ON_AP_FILTER(request)) {
        request->send_P(status, F("text/html"), page);
    } else {
        request->send(400, F("text/html"), F(""));
    }

}