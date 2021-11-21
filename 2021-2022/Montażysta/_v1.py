def main(n,t):
    t.sort(key = lambda x:x[1])
    d = []
    s_value = 0
    for i in range(len(t)):
        space = t[i][1] - s_value
        if t[i][0] <= space:
            d.append((t[i][0],t[i][2]))
            s_value += t[i][0]
        else:
            a = max(d,key=lambda x:x[0],default=0)
            if a != 0:
                if t[i][0] < a[0]:
                    s_value = s_value - a[0] + t[i][0]
                    del(d[d.index(a)])
                    d.append((t[i][0],t[i][2]))
    print(len(d))
    day_count = 1
    for i in d:
        print(i[1],day_count)
        day_count = day_count + i[0]
    
n = int(input())
t = []
cnt = 1
for i in range(n):
    inp = input()
    a,b = inp.split(" ")
    if a <= b:
        t.append([int(a),int(b),cnt])
    cnt += 1
print("START")
print(len(t),n)
main(n,t)