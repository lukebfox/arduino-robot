# forward == 12
# stop == 10
# backward == 8
# left value == left motor
# right value == right motor

f="12"
s="10"
b="08"


def Forward():
    return f+f

def PivotLeft():
    return (f+b)

def PivotRight():
    return (b+f)

def Left():
    return(f+s)
    
def Right():
    return(s+f)
    
def Stop():
    return(s+s)

def Backward():
    return(b+b)

def Dist(time):
    speed = 343
    distance = speed * time
    mindist = 30
    if distance < mindist:
        Stop()
        
# 
Motor = PivotRight()

print(Motor)

