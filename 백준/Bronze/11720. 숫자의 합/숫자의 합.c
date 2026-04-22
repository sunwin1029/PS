#include <stdio.h>
int main()
{
        char a[100];
        int b, c;
        int sum = 0;
        scanf("%d", &b);
        scanf("%s", a);
        for(int i = 0; i < b; i++)
        {
                c = (int)(a[i] - '0');
                sum += c;
        }
        printf("%d", sum);
        return 0;
}
