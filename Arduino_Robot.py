
import serial
from time import Sleep

ser = serial.Serial("com3", 9600, timeout=5)


def Forward():
    sleep(1)
    ser.write(b '1')
    return

def PivotLeft(): #turn left
    sleep(1)
    ser.write(b '2')
    return 

def PivotRight(): #turn right
    sleep(1)
    ser.write(b '3')
    return 

def FLeft(): #full forward turning left
    sleep(1)
    ser.write(b '4')
    return 
    
def FRight(): #full forward turning right
    sleep(1)
    ser.write(b '5')
    return 
    
def BLeft(): #full backward turning left
    sleep(1)
    ser.write(b '6')
    return 
    
def BRight(): #full backward turning right
    sleep(1)
    ser.write(b '7')
    return 
    
def Stop(): #stop
    sleep(1)
    ser.write(b '8')
    return 

def Backward(): # backward straight
    sleep(1)
    ser.write(b '9')
    return 

