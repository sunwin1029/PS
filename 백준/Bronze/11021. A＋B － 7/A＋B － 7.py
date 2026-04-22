a = int(input())
for i in range(a) :
    x, y = input().split()
    a = int(x)
    b = int(y)
    print('Case #%d: %d' % (i+1, a + b))