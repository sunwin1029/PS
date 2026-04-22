#include <stdio.h>
#include <string.h>

int main() {
    char num[6];
    int len;
    int check = 0;
    while(1) {
        check = 0;
        scanf("%s", &num);
        len = strlen(num);
        // printf("%d\n", len);
        // printf("%s\n", num);
        if(strcmp(num, "0") == 0) 
        break;
        for(int i = 0; i < len / 2; i++) {
                if(num[i] == num[len - i - 1])
                continue;
                if(num[i] != num[len - i - 1])
                check = 1;
            }
        if(check == 0)
        printf("yes\n");
        else
        printf("no\n");
    }
    
    return 0;
}