#include <stdio.h>
#include <string.h>
char ar[1000003];
int main() {
    scanf("%[^\n]s", ar);
    int len = 0;
    len = strlen(ar);
    int num = 1;
 
        for(int i = 0; i < len - 1; i++)
        {
            if(ar[i] == 32)
            num++;
        }
    if(ar[0] == 32)
        num--;
    if(len == 0)
    num = 0;
    printf("%d", num);
    
    return 0;
}