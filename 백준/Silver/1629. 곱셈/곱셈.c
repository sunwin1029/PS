#include <stdio.h>
long long a, b, c;
int f(long long num) {
    int cnt = 0;
    int cnt_2 = 0;
    if(num == 1)
    return a % c;
    else {
        if(num % 2 == 0) 
            return ((f(num / 2) % c) * (f(num / 2) % c)) % c;
        else
        return ((f(num - 1) % c) * (a % c)) % c;
    }
    
    
}
int main() {
    scanf("%lld %lld %lld", &a, &b, &c);
    int res = f(b);
    printf("%d", res);
    
    return 0;
}