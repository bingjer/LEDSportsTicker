#include <WiFi.h>

#include "Wifi.hpp"

namespace Wifi {
bool Wifi::connect(const char* aSSID, const char* aPassword) {
    uint8_t WIFI_STATUS = WL_IDLE_STATUS;
    while(WIFI_STATUS != WL_CONNECTED) {
        Serial.print("Attempting to connect to network, SSID: ");
        Serial.print(aSSID);
        WIFI_STATUS = WiFi.begin(aSSID, aPassword);
    }
    Serial.print("Connected to Wifi");
    return true;
}
}// end Wifi