#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char SSID[]     = SECRET_SSID;    // Network SSID (name)
const char PASS[]     = SECRET_OPTIONAL_PASS;    // Network password (use for WPA, or use as key for WEP)

void onWaterLevelChange();
void onSchedulerChange();
void onRelayStateChange();

int water_level;
CloudSchedule scheduler;
bool relay_state;

void initProperties(){

  ArduinoCloud.addProperty(water_level, READWRITE, ON_CHANGE, onWaterLevelChange);
  ArduinoCloud.addProperty(scheduler, READWRITE, ON_CHANGE, onSchedulerChange);
  ArduinoCloud.addProperty(relay_state, READWRITE, ON_CHANGE, onRelayStateChange);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
