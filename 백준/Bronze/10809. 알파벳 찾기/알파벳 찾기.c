#include <stdio.h>
#include <string.h>

int main() {
    char ar[101];
    int num[30];
    for(int i = 0; i < 27; i++)
    {
        num[i] = -1;
    }
    int asci;
    scanf("%s", ar);
    int len = strlen(ar);
    for(int i = len - 1; i > -1; i--)
    {
        asci = ar[i] - 97;
        num[asci] = i;
    }
    for(int i = 0; i < 25; i++)
    {
        printf("%d ", num[i]);
        
    }
    printf("%d", num[25]);
    return 0;
    
}