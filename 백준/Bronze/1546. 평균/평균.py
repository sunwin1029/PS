n = int(input())
grade = list(map(int, input().split()))
big = 0
su = 0
for i in range(n) :
    if int(grade[i]) > big :
        big = int(grade[i])
for i in range(n) :
    tmp = grade[i]
    grade[i] = tmp / big * 100
for i in range(n) :
    su += grade[i]
avr = su / n
print(avr)
