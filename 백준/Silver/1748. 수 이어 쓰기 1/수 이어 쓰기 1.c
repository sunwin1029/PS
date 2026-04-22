#include <stdio.h>
int main()
{
    int num;
    int check;
    int ara = 1;
    int ans = 0;
    scanf("%d", &num);
    check = num;
    while(check / 10 != 0)
    {
        check = check / 10;
        ara++;
    }
    int a = 9;
    int c = 9;
    for(int i = 1; i < ara; i++)
    {
        ans += a;
        c *= 10; 
        a = c * (i + 1);
    }
    int b = 1;
    for(int i = 1; i < ara; i++)
    {
        b *= 10;
    }

    int num_2 = num - b + 1;
    ans += num_2 * ara;
    
    printf("%d", ans);
    return 0;
}