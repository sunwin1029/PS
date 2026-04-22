#include <stdio.h>
int main()
{
        char a[100] = {0};
        int cnt = 0;
        scanf("%s", a);
        for(int i = 0; i < 100; i++)
        {
                if(a[i] == 'c' && (a[i+1] == '=' || a[i+1] == '-') )
                        i++;
                else if(a[i] == 'd' && a[i+1] == 'z' && a[i+2] == '=')
                        i += 2;
                else if(a[i] == 'd' && a[i+1] == '-')
                        i++;
                else if((a[i] == 'l' || a[i] == 'n') && a[i+1] == 'j')
                        i++;
                else if((a[i] == 's' || a[i] == 'z') && a[i+1] == '=')
                        i++;
                else if(a[i] == 0)
                        break;
                cnt++;
        }
        printf("%d", cnt);
        return 0;
}