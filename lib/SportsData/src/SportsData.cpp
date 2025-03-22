
#include "SportsData.hpp"
#include <HTTPClient.h>
#include <ArduinoJson.h>


SportsData::SportsData() {
    // nothing for now
}

SportsData::SportsData(etl::string_view aAPIEndpoint) : mUrl(aAPIEndpoint) {}

void SportsData::getData() {
    HTTPClient client;
    Serial.println("trying to connect to: ");
    Serial.println(mUrl.data());
    client.setTimeout(10000);
    client.setInsecure();
    client.begin(mUrl.data());
    int httpCode = client.GET();
    if (httpCode > 0) {
        String payload = client.getString();
        Serial.println("Received JSON:");
        Serial.println(payload);  // Print raw JSON

        // Parse JSON
        StaticJsonDocument<1024> doc;
        DeserializationError error = deserializeJson(doc, payload);

        if (error) {
          Serial.print("JSON Deserialization failed: ");
          Serial.println(error.f_str());
          return;
        }

        // Access fields (adjust keys based on your JSON structure)
        const char* value = doc["key"];  // Replace "key" with the JSON key you're accessing
        Serial.print("Value for 'key': ");
        Serial.println(value);
      } else {
        Serial.print("HTTP request failed with error code: ");
        Serial.println(httpCode);
      }

    client.end();  // Close connection
    Serial.flush();
    delay(10000);
}



