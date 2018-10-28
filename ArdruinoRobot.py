# -*- coding: utf-8 -*-
"""
Created on Sat Oct 27 23:38:09 2018

@author: Asus FX553
"""

# forward == 3
# stop == 2
# backward == 1
# left value == left motor
# right value == right motor

f=3
s="2"
b="1"


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

