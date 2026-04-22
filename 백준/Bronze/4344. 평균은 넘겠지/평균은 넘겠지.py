c = int(input())
for i in range(c) :
    a = list(map(int, input().split()))
    n = a[0]
    su = 0
    wlgh = 0
    for i in range (n) :
        a[i] = a[i+1]
    a[n] = 0
    for i in range (n) :
        q = int(a[i])
        su += q
        avr = su / n
    for i in range (n) :
        if a[i] > avr :
            wlgh += 1
    result = float(wlgh / n * 100)
    print("%.3f%%" % result)