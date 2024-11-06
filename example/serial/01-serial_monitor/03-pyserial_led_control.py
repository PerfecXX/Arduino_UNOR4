"""
Use this file with 02-serial_led_control.ino
"""

import serial
import time

arduino_port = 'COM18'  # Change this port according to your serial port
baud_rate = 9600

print('Connect to {} with {} baudrate'.format(arduino_port,baud_rate))
ser = serial.Serial(arduino_port, baud_rate)
time.sleep(2)

try:
    while True:
        user_input = input("Enter command (on/off) or 'quit' to exit: ").strip().lower()
        
        if user_input == 'quit':
            print("Exiting...")
            break
        elif user_input in ["on", "off"]:
            ser.write((user_input + '\n').encode())
            time.sleep(0.1)
            while ser.in_waiting > 0:
                response = ser.readline().decode().strip()
                print("Arduino:", response)
        else:
            print("Invalid command. Please enter 'on', 'off', or 'quit'.")
finally:
    ser.close()

