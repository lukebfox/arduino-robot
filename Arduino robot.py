#returns the string that is hopefully recieved by the arduino
def Forward():
    return "1111"

def PivotLeft():
    return "1101"

def PivotRight():
    return "0111"

def FLeft():
    return "1011"
    
def FRight():
    return "1110"
    
def BLeft():
    return "1001"
    
def BRight():
    return "0110"
    
def Stop():
    return "1010"

def Backward():
    return "0101"

#can we move this to the arduino?
def Dist(time):
    speed = 343
    distance = speed * time
    mindist = 30
    if distance < mindist:
        Stop()
        
#testing code
command = PivotRight()
print(command)

