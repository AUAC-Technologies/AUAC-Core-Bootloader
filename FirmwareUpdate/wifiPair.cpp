#include"wifiPair.h"

//Function gets number of APs
uint8_t PAIR::scanAccessPoints(){
    //Return number of APs
    return WiFi.scanNetworks();
}

//Function gets AP Strength
int8_t PAIR::getAPStrength(uint8_t AP){
    //Get AP Strength
    return WiFi.RSSI(AP);
}

//Function gets AP_Name
StringType PAIR::getAP_Name(uint8_t Nnum){
    //From the network number print the AP_Name
    return WiFi.SSID(Nnum);
}

// Function gets security type
uint8_t PAIR::getEncryptionType(uint8_t AP){
    //Get security type
    return WiFi.encryptionType(AP);
}

//Function scans for APs without encryption
uint8_t PAIR::SCAN_FOR_UNSECURE_APs(){
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

//Convert int to char
char PAIR::tochar(uint8_t num){
    return num + '0';
}

//Function returns array of all free networks and their corresponding RSSI
StringType PAIR::compileAccessibleNetworkInformation(){
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

uint8_t PAIR::determine_best_network_RSSI(){
    //Get all free networks along with corresponding RSSI
    StringType networks = compileAccessibleNetworkInformation();
    //Determine network with highest RSSI and connect
    uint8_t array_size;
    //Array to hold RSSI values to determine best RSSI
    int8_t *RSSI_ARRAY = (uint8_t*)malloc(array_size / 2);
    uint8_t tempLoopCount;
    for(size_t i = 0;i < array_size;i += 2){
        RSSI_ARRAY[tempLoopCount] = atoi(networks[i]);
        tempLoopCount++;
    }
    //Calculate best RSSI

}

//Connect to AP
uint8_t PAIR::CONNECT_TO_AP(){
    uint8_t MAX_TRIES;
    while(MAX_TRIES != 10){
        uint8_t bestNetworkNum = determine_best_network_RSSI();
        char* bestNetworkSSID = getAP_Name(bestNetworkNum);
        Wifi.mode(WIFI_STA);
        WiFi.begin(bestNetworkSSID,NULL);
        if(WiFi.status() != WL_CONNECTED){
            MAX_TRIES++;
        }else{
            break;
        }
    }

}