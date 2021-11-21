import numpy as np

def factorial(n):
    w = 1
    for i in range(1,n+1):
        w *= i
    return w

def modulo(n):
    return n%1000000007

def certainties(n,t):
    if n == 3 and t[0] != t[2]:
        return False
    
    w = np.zeros(n)
    z = np.zeros(n)
    occ = np.zeros(n+1)
    w[1] = t[0]
    w[-2] = t[-1]
    z[0] = 1
    z[-1] = 1
    
    for i in range(1,n-1):
        if i == 1:
            occ[t[0]] += 1
            occ[t[n-1]] += 1
        occ[t[i]] += 1
        a = t[i-1]
        b = t[i+1]
        c = w[i]
        if a == b:
            if w[i] != a and w[i] != 0:
                return False
            w[i] = a
            z[i+1] = 1
            z[i-1] = 1
        elif a == c:
            try:
                if w[i+2] != 0 and w[i+2] != b:
                    return False
                w[i+2] = b
                z[i+1] = 1
            except IndexError:
                pass
        elif b == c:
            try:
                if w[i-2] != 0 and w[i-2] != a:
                    return False
                w[i-2] = a
                z[i-1] = 1
            except IndexError:
                pass   
    for i in range(n-2,0,-1):
        a = t[i-1]
        b = t[i+1]
        c = w[i]
        if a == b:
            w[i] = a
            z[i+1] = 1
            z[i-1] = 1
        elif a == c:
            try:
                w[i+2] = b
                z[i+1] = 1
            except IndexError:
                pass
        elif b == c:
            try:
                w[i-2] = a
                z[i-1] = 1
            except IndexError:
                pass  
    if max(occ) > 2:
        return False
    return w,z
    
def daszki(n,z):
    w = []
    m = np.zeros(n)
    total = 0
    for i in range(n):
        cnt = 0
        if z[i] == 0 and m[i] != 1:
            m[i] = 1
            cnt = 1
            total += 1
            try:
                for j in range(i+2,n,2):
                    if z[j] == 0:
                        m[j] = 1
                        cnt += 1
                        total += 1
                    else:
                        break
            except IndexError:
                pass
            w.append(cnt)
 
    return w,total

def main(n,t):
    c = certainties(n,t)
    if c == False:
        return 0
    else:
        w,z = c
    d,total = daszki(n,z)
    q = np.count_nonzero(w==0)
    scale = 1
    increment = 1
    last_factorial = factorial(q-total)
    for i in d:
        for j in range(0,i):
            scale += increment
        increment = scale
    output = modulo(modulo(scale) * modulo(last_factorial))
    return modulo(output)

n = int(input())
t = input().split(" ")
t = [int(x) for x in t]
print(main(n,t))