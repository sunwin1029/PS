#include <stdio.h>
struct a{
    long long real_zero;
    long long fal_zero;
    long long one;
};
struct a a1[1000002];
int main() {
    int num;
    long long total = 0;
    scanf("%d", &num);
    a1[1].fal_zero = 1;
    a1[1].one = 1;
    a1[1].real_zero = 0;
    for(int i = 1; i < num; i++) 
    {
        a1[i + 1].fal_zero = (a1[i].real_zero + a1[i].one) % 15746;
        a1[i + 1].real_zero = a1[i].fal_zero % 15746;
        a1[i + 1].one = a1[i + 1].fal_zero % 15746;
    }
    total = (a1[num].real_zero + a1[num].one) % 15746;
    printf("%lld", total);
    // printf("\n%d %d %d", a1[num].fal_zero, a1[num].real_zero, a1[num].one);



    return 0;
}