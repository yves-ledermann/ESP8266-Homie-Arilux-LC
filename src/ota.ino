#include "ArduinoOTA.h"

// -----------------------------------------------------------------------------
// OTA
// -----------------------------------------------------------------------------

void otaSetup() {

    ArduinoOTA.setPort(OTA_PORT);
		ArduinoOTA.setHostname(WiFi.hostname().c_str()); 	// Hostname defaults to esp8266-[ChipID]
		ArduinoOTA.setPassword((const char *) OTA_PASS);

    ArduinoOTA.onStart([]() {
        DEBUG_MSG("[OTA] Start\n");
    });

    ArduinoOTA.onEnd([]() {
        DEBUG_MSG("\n[OTA] End\n");
    });

    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
        DEBUG_MSG("[OTA] Progress: %u%%\r", (progress / (total / 100)));
    });

    ArduinoOTA.onError([](ota_error_t error) {
        #if DEBUG_PORT
            DEBUG_MSG("\n[OTA] Error[%u]: ", error);
            if (error == OTA_AUTH_ERROR) DEBUG_MSG("Auth Failed\n");
            else if (error == OTA_BEGIN_ERROR) DEBUG_MSG("Begin Failed\n");
            else if (error == OTA_CONNECT_ERROR) DEBUG_MSG("Connect Failed\n");
            else if (error == OTA_RECEIVE_ERROR) DEBUG_MSG("Receive Failed\n");
            else if (error == OTA_END_ERROR) DEBUG_MSG("End Failed\n");
        #endif
    });

    ArduinoOTA.begin();

}

void otaLoop() {
    ArduinoOTA.handle();
}
