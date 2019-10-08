import math


def makina(x1, x2, step1, step2):
    """
    Utilizar numeros máquina
    """
    while x1 < 20:
        x1 = x1 + step1
        y1 = math.exp(x1)
        print("{:.1f} = {}".format(x1,y1))
    
    while x2 < 20:
        x2 = x2 + step2
        y2 = math.exp(x2)
        print("{:.1f} = {}".format(x2, y2))
        
    
    print(x1 - x2)
    print(y1 - y2)
    
x1 = 1
x2 = 1
step1 = 1
step2 = 1/32

#makina(x1, x2, step1, step2)


def sqrt(n):
    """
    Raiz quadrada sem raiz quadrada
    """
    for i in range(n):
        if(i*i <= n < (i+1)*(i+1)):
            square1 = i
            square2 = i +1
            if (i*i == n):
                return i
    
    
    div = (square1 + square2) / 2  
    for i in range(10):
         result = n / div
         div = (result + div) / 2
    return result

def sqrt2(n):
    step = 1/1024
    i = 1
    for _ in range(n*1000):
        i += step
        if (abs(i*i - n)< 0.01):
            return i


n = int(input("Escreve o número aqui: "))
print(sqrt(n))
