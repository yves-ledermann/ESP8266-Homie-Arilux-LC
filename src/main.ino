/*
 *   Tested with "WiFi Smart Socket ESP8266 MQTT"
 *   and "Sonoff - WiFi Wireless Smart Switch ESP8266 MQTT"
 *
 *   The Relay could be toggeled with the physical pushbutton
*/
#include "version.h"
#include "defaults.h"
#include "debug.h"
#include "RGBWNode.h"
#include "LoggerNode.h"
#include <Homie.h>

const unsigned char NUMBER_OF_LED = 4;
const unsigned char LED_PINS[NUMBER_OF_LED] = { ARILUX_RED_PIN, ARILUX_GREEN_PIN, ARILUX_BLUE_PIN, ARILUX_WHITE_PIN };

RGBWNode rgbw("LED", 14,5,12,13);

// -----------------------------------------------------------------------------
// Hardware
// -----------------------------------------------------------------------------

void setupHardware() {
  for (int i = 0; i < NUMBER_OF_LED; i++) {
      pinMode(LED_PINS[i], OUTPUT);
      digitalWrite(LED_PINS[i], LOW);
  }
      Serial.begin(SERIAL_BAUDRATE);
      Serial.println();
      Serial.println();
      Serial << endl << endl;

}

// -----------------------------------------------------------------------------
// Homie
// -----------------------------------------------------------------------------

void setupHomie() {
  Homie_setFirmware(APP_NAME, APP_VERSION);
  Homie.disableResetTrigger();
	LN.setLoglevel(LoggerNode::DEBUG);
  Homie.setup();
}


// -----------------------------------------------------------------------------
// setup
// -----------------------------------------------------------------------------

void setup() {
  setupHardware();
  setupHomie();
  welcome();
  otaSetup();
}


// -----------------------------------------------------------------------------
// Loop
// -----------------------------------------------------------------------------

void loop() {
  Homie.loop();
  otaLoop();
}
