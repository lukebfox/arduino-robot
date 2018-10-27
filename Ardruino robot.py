def Forward():
    return(100,100)

def Left():
    return (100,0)

def Right():
    return (0,100)

def Stop():
    return(50,50)

def Backward():
    return(0,0)

def Dist(time):
    speed = 343
    distance = speed * time
    mindist = 30
    if distance < mindist:
        Stop()
        
    
output = []

output = Forward()


print(output)