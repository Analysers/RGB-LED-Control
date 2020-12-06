// ********************************************************************************************
//                                     RGB_LED_Control                                                      
// --------------------------------------------------------------------------------------------
//
// File  : wifi_accessPoint.h
// Author: Gabriel da Silva Caetano <98gabrielSc@gmail.com>
//
// ********************************************************************************************

// ----------------------------------------------------------------------------------------- //

#include "Headers/serial.h"
#include "Headers/wifi_accessPoint.h"

// ----------------------------------------------------------------------------------------- //

// ########### ********************************************************************************
//
// Function   : initializeWiFiAccessPoint
//
// Parameters : void
// Return     : void
//
// Description: Initializes the wifi access point
//
// ########### ********************************************************************************

void initializeWiFiAccessPoint(void ) {

    WiFi.disconnect(true, true); 
    WiFi.mode(WIFI_OFF);

    delay(1000);
    
    WiFi.disconnect(true, true); 
    WiFi.mode(WIFI_AP_STA);
    WiFi.setSleep(false);

    WiFi.softAP("rgbLedControl", // SSID
                "admin@123",     // password
                1,  // -> channel 
                0,  // -> ssid_hidden
                1); // -> max_connection    

    #ifdef SERIAL_ENABLED
    IPAddress IP = WiFi.softAPIP();
    Serial.print(F(" ## Access Point IP address: "));
    Serial.println(IP);
    #endif

}
