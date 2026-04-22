#include <stdio.h>
#include <string.h>

int main() {
    char arr[101];
    int len;
    scanf("%s", arr);
    len = strlen(arr);
    
    for(int i = 0; i < len; i++) {
        printf("%c", arr[i]);
        if(i != 0 && i % 10 == 9) {
            printf("\n");
        }
    }
    
    return 0;
}