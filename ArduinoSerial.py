import serial
from time import Sleep

ser = serial.Serial("com3", 9600, timeout=5)

def send_message(code):
    sleep(1)
    ser.write(code)

    

