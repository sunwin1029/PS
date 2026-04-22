a = int(input())
b = list(map(int, input().split()))
big = b[0]
sml = b[0]
for i in range(a-1) :
    if big < b[i+1] :
        big = b[i+1]
    if sml > b[i+1] :
        sml = b[i+1]
print(sml, big)