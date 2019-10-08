import math

f = lambda x : -2.75* (x **3) + 18 * (x ** 2) - 21*x - 12
g = lambda x : x - 2 * math.log(x, math.exp(1)) - 5
h = lambda x : 2 * (x ** math.sqrt(x)) - 10 * x + 1

def bissection(function, a, b):
    step = 0
    while (abs(a - b) > 10**-5):
        step += 1
        xn = (a + b) / 2
        if (f(a) * f(xn) < 0):
            b = xn
        else:
            a = xn
    print(a, b)
    print(xn, step)
    print("\n")

def bissection(function, a, b):
    step = 0
    while (abs(a - b) > 10**-5):
        step += 1
        xn = (a + b) / 2
        if (f(a) * f(xn) < 0):
            b = xn
        else:
            a = xn
    print(a, b)
    print(xn, step)
    print("\n")

def corda(function, a, b):
    step = 1
    x = ((a* function(b) - b * function(a))/(function(b)-function(a)))    
    if (f(a) * f(x) < 0):
        b = x
    else:
        a = x
    xn = x
    x = ((a* function(b) - b * function(a))/(function(b)-function(a)))

    while (abs(x - xn) > 10**-5):
        step += 1
        x = ((a* function(b) - b * function(a))/(function(b)-function(a)))    
        if (f(a) * f(x) < 0):
            b = x
        else:
            a = x
        xn = x
        x = ((a* function(b) - b * function(a))/(function(b)-function(a)))
        
    print(a, b)
    print(xn, step)
    print("\n")

bissection(f, -2,0) 
bissection(f, 1,3)
bissection(f, 4,7)
"""
bissection(g, 0.01, 0.1)
bissection(g, 9, 10)

bissection(h, 0.01, 0.3)
bissection(h, 97, 100)
"""

corda(f, -2,0)
corda(f, 1,3)
corda(f, 4,7)











    





