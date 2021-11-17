import numpy as np
from datetime import datetime

def letter_check(l,c):
    lc = {}
    for i in c:
        try:
            lc[i] += 1
        except:
            lc.update({i:1})
    s = 0
    for i in l.keys():
        if s == 0:
            s = l[i]/lc[i]
        else:
            try:
                if l[i]/lc[i] != s:
                    return False
            except KeyError:
                return False
    return True

def count(t,T,c):
    w = 0 
    l = len(c)
    for i in range(0,len(t),1):
        j = 0
        while j <= len(t[i])-l:
            if t[i][j:j+l] == c:
                w += 1
                j += l-1
            j = j+1
    for i in range(0,len(T),1):
        j = 0
        while j <= len(T[i])-l:
            if T[i][j:j+l] == c:
                w += 1
                j += l-1
            j = j+1
    return w

def check(t,T,p,i,l):
    target = int(p/i)
    c = t[0][0:i]
    if letter_check(l,c):
        cnt = count(t,T,c)
        if target <= cnt:
            return True
    return False
        
def main(n,m,t):
    start = datetime.now()
    w = []
    temp = [list(x) for x in t]
    T = np.asarray(temp).T.tolist()
    T = ["".join(x) for x in T]
    l = {}
    for i in t:
        for j in i:
            try:
                l[j] += 1
            except:
                l.update({j:1})
    if len(l.keys()) == 1:
        s = set()
        ma = n if n > m else m
        for i in range (1,int(ma/2)+1):
            if n%i == 0:
                s.add(i)
            elif m%i == 0:
                s.add(i)
        s.add(n)
        s.add(m)
        s = list(s)
        s.sort()
        end = datetime.now()
        return len(s),s,end-start
    else:
        p = m*n
        ma = n if n>m else m
        for i in range(2,ma+1):
            if p%i == 0:
                if i <= n and i <= m:
                    if check(t,T,p,i,l) == True:
                        w.append(i)
                    elif check(T,t,p,i,l) == True:
                        w.append(i)
                elif i <= n and i > m:
                    if check(T,t,p,i,l) == True:
                        w.append(i)
                elif i > n and i <= m:
                    if check(t,T,p,i,l) == True:
                        w.append(i)
    end = datetime.now()
    return len(w),w,end-start

inp1 = input()
n,m = inp1.split(" ")
n = int(n)
m = int(m)
t = []
for i in range(n):
    a = input()
    t.append(a)
    
s,t,time = main(n,m,t)
print(s,time)
for i in range(0,s,1):
    print(t[i],end = " ")