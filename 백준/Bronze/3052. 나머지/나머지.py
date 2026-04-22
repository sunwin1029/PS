a = [0] * 10
b = [0] * 10
cnt = 10
for i in range(10) :
    a[i] = int(input())
for i in range(10) :
    b[i] = a[i] % 42
for i in range(10) :
    cmp = b[i]
    for j in range(i+1, 10) :
        if b[j] == cmp :
            cnt -= 1
            b[j] = -j
print(cnt)