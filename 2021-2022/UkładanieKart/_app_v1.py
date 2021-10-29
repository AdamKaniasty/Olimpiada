n,m = input().split(" ")
n = int(n)
m = int(m)
def factorial(n):
    t = [1]
    for i in range(1,n+1):
        t.append((t[i-1]*i))
    return t
w = 0
cnt = n-2
t = factorial(n)
a = t[n-2]
for i in range(1,n-1):
    for j in range(i,n):
        if j != n-1:
            w += a * j
        if j == n-1:
            w += (a-a/t[cnt]) * j
    a = a + (a/cnt)
    cnt = cnt - 1
r = t[n] - t[n-1]
s = (2*w +(n-1)*r)/2 * n
print(int(s%m))