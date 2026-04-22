a = []
for i in range(9) :
    a.insert(i, int(input()))
big = a[0]
big_num = 1
for i in range(8) :
    if big < a[i+1] :
        big = a[i+1]
        big_num = i+2
print(big)
print(big_num)