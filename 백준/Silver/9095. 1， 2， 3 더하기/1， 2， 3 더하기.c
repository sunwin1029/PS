#include <stdio.h>
int cal(int n)
{
    if(n == 1)
    return 1;
    if(n == 2)
    return 2;
    if(n == 3)
    return 4;
    return cal(n - 1) + cal(n - 2) + cal(n - 3);
    
}
int main() {
    int man;
    int num;
    scanf("%d", &man);
    for(int i = 0; i < man; i++) 
    {
        scanf("%d", &num);
        int a = cal(num);
        printf("%d\n", a);
    }
    return 0;
}