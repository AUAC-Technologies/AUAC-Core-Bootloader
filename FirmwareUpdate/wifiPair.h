#ifndef WIFI_PAIR
#define WIFI_PAIR

#include "lib/ESP8266WiFi/src/ESP8266WiFi.h"
#include<stdint.h>
#include<stddef.h>
#include<stdlib.h>

#define NO_AP_ENCRYPTION 7

typdef char* StringType;

class PAIR {
    private:
        char tochar(uint8_t num);

    public:
        uint8_t scanAccessPoints();

        int8_t getAPStrength(uint8_t AP);

        StringType getAP_Name(uint8_t Nnum);

        uint8_t getEncryptionType(uint8_t AP);

        uint8_t SCAN_FOR_UNSECURE_APs();

        StringType compileAccessibleNetworkInformation();

        uint8_t determine_best_network_RSSI();

        uint8_t CONNECT_TO_AP();


};

#endif