from math import factorial
import numpy as np
def add(a,b,m):
    return (a%m + b%m)%m
def substract(a,b,m):
    return (a%m - b%m)%m
def multiply(a,b,m):
    return (a%m * b%m)%m

def main(n,m):
    t = np.ones(n)
    for i in range(1,n):
        tc = t
        t = multiply(t,i,m)
        t[n-i]=tc[n-i]%m
    w = np.zeros(n)
    cnt = 1
    cnt_s = (n-1)
    for i in range (1,n-1):
        w[i] = w[i-1]
        x = t[i]
        x2 = substract(x,cnt,m)
        w[i] += x
        w[n-1] += x2
        cnt = cnt * cnt_s
        cnt_s -= 1
    out = 0
    for i in range(len(w)):
        out = add(out,multiply(i,w[i],m),m)
    r = substract(factorial(n),factorial(n-1),m)
    s1 = multiply(out,n,m)
    d = (2 + (n-2))/2*(n-1)
    s2 = multiply(r,d,m)
    return int(add(s1,s2,m))

inp = input().split(" ")
n = int(inp[0])
m = int(inp[1])

print(main(n,m))