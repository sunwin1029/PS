x,y = input().split()
H = int(x)
M = int(y)
if H != 0 :
    if 45 <= M <= 59 :
        print(H, M-45)
    elif M < 45 :
        print(H-1, 60-45+M)
elif H == 0 :
    if 45 <= M <= 59 :
        print(H, M-45)
    elif M < 45 :
        print(23, 60-45+M)
