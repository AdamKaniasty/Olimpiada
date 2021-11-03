import numpy as np
from itertools import permutations

def perm(n,a,indexes):
    cnt=0
    for i in indexes:
        a[i] = n[cnt]
        cnt = cnt+1
    return a

def lc(n,t):
    for i in range(len(t)):
        if i == 0:
            if t[i] != n[i+1]:
                return False
        if i == len(t)-1:
            if t[i] != n[i-1]:
                return False
        else:
            if t[i] != n[i-1] and t[i] != n[i+1]:
                return False
    return True
def brute (n,t):
    w = np.zeros(n)
    w[1]=t[0]
    w[-2]=t[-1]
    for i in range(0,n):
        if w[i] == 0:
            if i != 0 and i != n-1:
                if t[i-1] == t[i+1]:
                    w[i] = t[i-1]
                elif w[i+2] != 0 and w[i+2] != t[i+1]:
                    w[i] = t[i+1]
                elif w[i-2] != 0 and w[i-2] != t[i-1]:
                    w[i] = t[i-1]
            if i == n-1:
                if w[i-2] != 0 and w[i-2] != t[i-1]:
                    w[i] = t[i-1]
    for i in range(n-1,-1,-1):
        if w[i] == 0:
            if i != 0 and i != n-1:
                if t[i-1] == t[i+1]:
                    w[i] = t[i-1]
                elif w[i+2] != 0 and w[i+2] != t[i+1]:
                    w[i] = t[i+1]
                elif w[i-2] != 0 and w[i-2] != t[i-1]:
                    w[i] = t[i-1]
            if i == n-1:
                if w[i-2] != 0 and w[i-2] != t[i-1]:
                    w[i] = t[i-1]
    arr = np.arange(1,n+1)
    for element in w:
        if element in arr:
            arr = np.delete(arr,np.argwhere(arr == int(element)))
    cnt = 0
    indexes = np.argwhere(w == 0)

    for i in permutations(arr):
        p = perm(i,w,indexes)
        if lc(p,t):
            cnt += 1
    print(cnt)
    
n = input()
a = input()
n = int(n)
t = a.split()
t =[int(x) for x in t]
brute(n,t)
