fib = [0,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269,2178309,3524578,5702887,9227465,14930352,24157817,39088169,63245986,102334155,165580141,267914296,433494437,701408733,1134903170,1836311903,2971215073,4807526976,7778742049,12586269025,20365011074,32951280099,53316291173,86267571272,139583862445,225851433717,365435296162,591286729879,956722026041,1548008755920,2504730781961,4052739537881,6557470319842,10610209857723,17167680177565,27777890035288,44945570212853,72723460248141,117669030460994,190392490709135,308061521170129,498454011879264,806515533049393,1304969544928657,2111485077978050,3416454622906707,5527939700884757,8944394323791464,14472334024676221,23416728348467685,37889062373143906,61305790721611591,99194853094755497,160500643816367088,259695496911122585,420196140727489673,679891637638612258]
r_fib = [679891637638612258, 420196140727489673, 259695496911122585, 160500643816367088, 99194853094755497, 61305790721611591, 37889062373143906, 23416728348467685, 14472334024676221, 8944394323791464, 5527939700884757, 3416454622906707, 2111485077978050, 1304969544928657, 806515533049393, 498454011879264, 308061521170129, 190392490709135, 117669030460994, 72723460248141, 44945570212853, 27777890035288, 17167680177565, 10610209857723, 6557470319842, 4052739537881, 2504730781961, 1548008755920, 956722026041, 591286729879, 365435296162, 225851433717, 139583862445, 86267571272, 53316291173, 32951280099, 20365011074, 12586269025, 7778742049, 4807526976, 2971215073, 1836311903, 1134903170, 701408733, 433494437, 267914296, 165580141, 102334155, 63245986, 39088169, 24157817, 14930352, 9227465, 5702887, 3524578, 2178309, 1346269, 832040, 514229, 317811, 196418, 121393, 75025, 46368, 28657, 17711, 10946, 6765, 4181, 2584, 1597, 987, 610, 377, 233, 144, 89, 55, 34, 21, 13, 8, 5, 3, 2, 1, 0]
def factorization(n,k):
    t = {}
    first = 0
    for i in r_fib[k:-2]:
        n = int(n)
        while n % i == 0:
            if first == 0:
                first = i
            if i in t:
                t[i] = t[i] + 1
            else:
                t[i] = 1
            n = int(n/i)
    return (t,first)

def main(m,k):
    if m == 1:
        return 1
    output = 0
    product = 1
    f,thresh = factorization(m,k)
    if thresh == 2:
        return "NIE"
    for i in f.keys():
        weight = fib.index(i)
        output += f[i] * weight + f[i]
        product = product * i**f[i]
    if output != 0:
        if product == m:
            return output - 1
        else:
            main(m,thresh)
    else:
        return "NIE"
    
with open ("testy2/dom.in","r") as i1:
    with open ("testy2/dom.out","r") as bf1:
        for l1,l3 in zip(bf1,i1):
            l2 = str(main(int(l3)))
            l1 = l1.split('\n')[0]
            if l1 != l2:
                print(l1,l2,l3)
                break