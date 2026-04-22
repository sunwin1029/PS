// Online C compiler to run C program online
#include <stdio.h>


int main() {
    int len;
    char arr[110];
    scanf("%s", arr);
    for(int i = 0; arr[i] != 0; i++)
    len = i + 1;
    printf("%d", len);

    return 0;
}