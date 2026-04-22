a = int(input())
plus = 1
score = 0
for i in range (a) :
    b = list(input())
    for i in b :
        if i == 'O' :
            score += plus
            plus += 1
        if i == 'X' :
            plus = 1
    print(score)
    plus = 1
    score = 0