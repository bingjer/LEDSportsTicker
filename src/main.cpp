#include <Arduino.h>
#include <FastLED.h>
#include "Wifi.hpp"
#include "Secrets.hpp"
#include "SportsData.hpp"

void setup() {
  Serial.begin(11520);
  while(!Serial) {}


}

void loop() {
  Wifi::Wifi wifi;
  wifi.connect(WIFI_HOST, WIFI_PWD);
  delay(3000);
  while(true) {

  SportsData sportsData("https://site.api.espn.com/apis/site/v2/sports/basketball/nba/scoreboard");
  sportsData.getData();
  }
}
