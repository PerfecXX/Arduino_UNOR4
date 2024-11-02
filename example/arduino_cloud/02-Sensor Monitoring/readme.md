# Sensor Monitoring with Arduino Cloud
To monitor your light, temperature, and humidity using a sensor and send the data to Arduino Cloud, we need to prepare hardware and software by doing the following:

- Hardware
  - Arduino UNO R4 WiFi
  - USB Type-C
  - DHT11 or DHT22
  - LDR Module
  - Wiring Jumper
  - Bread Board
- Software
  - Arduino Cloud Account
  - Arduino Create Agent
  - Arduino IDE or Arduino Cloud Editor

## Instruction
0. Connect your sensor to your Arduino UNO R4 WiFi by doing the following:
1. Install Arduino IDE on your computer: https://www.arduino.cc/en/software.
2. Install Arduino Create Agent on your computer: https://cloud.arduino.cc/download-agent/.
3. Connect your Arduino UNO R4 WiFi to your computer.
4. Sign in or register your Arduino account at: https://app.arduino.cc/
5. Create your new "things".
6. Associated your device using Arduino UNO R4.
7. Set up your network with your SSID and password.
8. Create a cloud variable by following the setting:
   
   | Cloud Variable Name | Variable Type | Variable Permission | Update Policy        |
   |---------------------|---------------|---------------------|-----------------------|
   | humidity           | float          | Read & Write        | On change      |
   | temperature           | float          | Read & Write        | On change      |
   | light_percentage           | int          | Read & Write        | On change      |

10. Upload your code to your board using this [file](https://github.com/PerfecXX/Arduino_UNOR4/blob/main/example/arduino_cloud/02-Sensor%20Monitoring/main.ino) as your source code.
    - If your using Arduino IDE, please download both the [main.ino](https://github.com/PerfecXX/Arduino_UNOR4/blob/main/example/arduino_cloud/02-Sensor%20Monitoring/main.ino) file and [thingProperties.h](https://github.com/PerfecXX/Arduino_UNOR4/blob/main/example/arduino_cloud/02-Sensor%20Monitoring/thingProperties.h) and make sure these two files are in the same directory.
    - If your using Arduino Cloud Editor, just replace the code to your sketch.
11. Open Serial Monitor when you successfully upload your code and wait until it shows your things ID.Your device should be online
    - If it is not, try to refresh the Things tab or check the connection with Serial Monitor.
13. Go to the Dashboard option in Arduino Cloud and create a new dashboard.
14. Add the following widget and link the cloud variable to the widget by this following:
    
   | Widget Name         | Link Variable       | 
   |---------------------|---------------------|
   | Gauge               | temperature         |
   | Percentage          | humidity            |
   | Percentage          | light_percentage    |
   | Chart               | temperature         |
   | Chart               | humidity            |
   | Chart               | light_percentage    |

15. Test your sensor and monitor the changes with your dashboard.
    - LDR : Use flash light to add more light and use your hand to cover the sensor to add more shadow.
    - DHT : Use your mouth to blow into the sensor; the temperature and humidity should be changed.
   
