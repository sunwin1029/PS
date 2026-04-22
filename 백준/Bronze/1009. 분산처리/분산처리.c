#include <stdio.h>
#include <math.h>
int main() {
    int num;
    int ar[1000];
    scanf("%d", &num);
    for(int i = 0; i < num; i++) {
        int a, b, tot, one;
        scanf("%d %d", &a, &b);
        one = 1;
        for(int j = 0; j < b; j++) {
            one = (one * a) % 10;
        }
        if(one == 0)
        ar[i] = 10;
        else
        ar[i] = one;
    }
    for(int i = 0; i < num; i++) {
        printf("%d\n", ar[i]);
    }
    return 0;
}