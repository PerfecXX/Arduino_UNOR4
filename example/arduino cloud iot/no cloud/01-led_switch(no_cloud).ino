/*
Author : Teeraphat Kullanankanjana
Date : 22/07/2024
Description : LED control with Arduino Cloud IoT (Without using Arduino Cloud Edtior)
*/
#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

// Set the network to connect to the Arduino Cloud IoT.
const char SSID[]     = "REPLACE_YOUR_SSID";    // Network SSID
const char PASS[]     = "REPLACE_YOUR_PASSWORD";    // Network password 
WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);

/* 
Cloud Variable
The name, type, permission, and update policy must be the same as the cloud variable declaration on the Arduino IoT Cloud.
Since led_state is a READ_WRITE variable, you need to declare onLedStateChange() to act as the callback function.
onLedStateChange() is executed every time a new value is received from the IoT Cloud.
*/          
bool led_state;
void onLedStateChange();

void setup() {

  // Set the built-in LED pin to output mode.
  pinMode(LED_BUILTIN,OUTPUT);

  // Initialize the serial communication at 9600 baud rate
  Serial.begin(9600);

  // Set cloud variables and their properties in the Arduino IoT Cloud.
  //                       Name      Permission  UpdatePolicy   CallBack Function. 
  ArduinoCloud.addProperty(led_state, READWRITE, ON_CHANGE, onLedStateChange);

  // Connect to Arduino IoT Cloud.
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  // Use ArduinoCloud.update() to sync the value between the board and Arduino IoT Cloud.
  ArduinoCloud.update();
}

/*
  Since led_state is READ_WRITE variable, onLedStateChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onLedStateChange()  {

  Serial.println("Recieve Data from Arduino IoT Cloud!");
  Serial.print("led_state:");
  Serial.println(led_state);

  if (led_state == true){
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else{
    digitalWrite(LED_BUILTIN, LOW);
  }
}
