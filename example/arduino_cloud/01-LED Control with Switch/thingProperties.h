#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char SSID[]     = SECRET_SSID;
const char PASS[]     = SECRET_OPTIONAL_PASS;

bool led_state;
void onLedStateChange();

void initProperties(){
  ArduinoCloud.addProperty(led_state, READWRITE, ON_CHANGE, onLedStateChange);
}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
