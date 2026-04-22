#include <stdio.h>

int main() {
    char ar[51];
    int num;
    long long each_hash = 1;
    long long hash = 0;
    scanf("%d", &num);
    scanf("%s", ar);
    
    for(int i = 0; i < num; i++) {
        each_hash = 1;
        for(int j = 0; j < i; j++) {
            each_hash *= 31;
            each_hash %= 1234567891;
        }
        hash += (each_hash * (ar[i] - 96)) % 1234567891;
    }
    
    printf("%lld", hash % 1234567891);
    

    return 0;
}