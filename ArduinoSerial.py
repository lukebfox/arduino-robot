import serial
from time import sleep

ser = serial.Serial("com3", 9600, timeout=5)

def send_message(code):
    sleep(3)
    ser.write(code)

