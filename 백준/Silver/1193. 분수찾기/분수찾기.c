#include <stdio.h>

int main() {
    int n;
    int start = 0;
    int x = 1; // x = increased_num
    int a, b; // a는 분모 b는 분자
    int dis; // 몇칸 가야하는지
    scanf("%d", &n);
    
    while(1) {
        if(start + x >= n)
        break;
        
        start += x;
        x++;
    }
    
    // printf("%d\n", x);
    dis = n - start - 1;
    if(x % 2 == 0) {
        a = x;
        b = 1;
        a -= dis;
        b += dis;
    }
    else {
        a = 1;
        b = x;
        a += dis;
        b -= dis;
    }
    printf("%d/%d", b, a);
    
    

    return 0;
}