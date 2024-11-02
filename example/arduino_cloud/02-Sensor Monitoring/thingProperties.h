#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char SSID[]     = SECRET_SSID;
const char PASS[]     = SECRET_OPTIONAL_PASS;

void onHumidityChange();
void onTemperatureChange();
void onLightPercentageChange();

float humidity;
float temperature;
int light_percentage;

void initProperties(){

  ArduinoCloud.addProperty(humidity, READWRITE, ON_CHANGE, onHumidityChange);
  ArduinoCloud.addProperty(temperature, READWRITE, ON_CHANGE, onTemperatureChange);
  ArduinoCloud.addProperty(light_percentage, READWRITE, ON_CHANGE, onLightPercentageChange);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
