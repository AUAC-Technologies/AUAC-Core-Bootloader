#include "lib/ESP8266WiFi/src/ESP8266WiFi.h"
#include<stdint.h>
#include<stddef.h>
#include<stdlib.h>

#define NO_AP_ENCRYPTION 7

typdef char* StringType;

//Function gets number of APs
uint8_t scanAccessPoints(){
    //Return number of APs
    return WiFi.scanNetworks();
}

//Function gets AP Strength
uint8_t getAPStrength(uint8_t AP){
    //Get AP Strength
    return WiFi.RSSI(AP);
}

//Function gets AP_Name
StringType getAP_Name(uint8_t Nnum){
    //From the network number print the AP_Name
    return WiFi.SSID(Nnum);
}

// Function gets security type
uint8_t getEncryptionType(uint8_t AP){
    //Get security type
    return WiFi.encryptionType(AP);
}

//Function scans for APs without encryption
uint8_t SCAN_FOR_UNSECURE_APs(){
    uint8_t count;
    uint8_t iter = 0;
    while(iter != scanAccessPoints()){
        //Determine if AP is encryption free
        if(getEncryptionType(i) != NO_AP_ENCRYPTION){
            count++;
        }
        iter++;
    }
    return count;
}

char tochar(uint8_t num){
    return num + '0';
}

//Function returns array of all free networks and their corresponding RSSI
StringType compileAccessibleNetworkInformation(){
    //Array index count
    uint8_t indexCount;
    //Return Array
    char NetworkData[SCAN_FOR_UNSECURE_APs() * 2];
    //Iterate through all available networks
    for(size_t i = 0; i < scanAccessPoints();++i){
        //Determine if AP is encryption free
        if(getEncryptionType(i) != NO_AP_ENCRYPTION){
            //Get RSSI and convert to char
            //Add to Network Data array
            NetworkData[indexCount] = i;
            NetworkData[indexCount + 1] = tochar(getAPStrength());
            indexCount += 2;
        }
    }
    return NetworkData;
}