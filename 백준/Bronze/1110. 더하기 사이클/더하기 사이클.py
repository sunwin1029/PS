x = int(input())
end = x
cnt = 0
while True :
    
    if x < 10 :
        x_new = x * 10 + x
    else :
        a = int(x / 10)
        b = int(x % 10)
        add = a+b
        a_new = b
        b_new = add % 10
        x_new = a_new * 10 + b_new
    cnt += 1
    if x_new == end :
        break
    x = x_new
print(cnt)