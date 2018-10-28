import serial
from Arduino_Robot import Forward

message = Forward()
#income = str.encode(income)
#arduinoData = serial.Serial("com3", 9600)
#arduinoData.write(income)
#print(income)
#arduinoData.close()
while True:
    ser = serial.Serial("com3")
    print (ser.name)
    ser.baudrate = 9600
    
    ser.write(message)
    ser.close()
