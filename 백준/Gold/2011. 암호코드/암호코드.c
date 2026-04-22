#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct q {
    int a; // 한자리로 끝남
    int b; // 두자리로 끝남
};
int main() {
    struct q str[5002];
    str[0].a = 1;
    str[0].b = 0;
    char code[5002];
    int dp[5002] = {0,};
    scanf("%s", code);
    int len = strlen(code);
    int error = 0;
    for(int i = 0; i < len - 1; i++) {
        if(code[i] == 49) {
            if(code[i + 1] == 48) {
                str[i + 1].b = str[i].a % 1000000 ;
                str[i + 1].a = 0;
                continue;
            }
            str[i + 1].a = str[i].a % 1000000 + str[i].b % 1000000;
            str[i + 1].b = str[i].a % 1000000;
            continue;
        }
        if(code[i] == 50 && code[i + 1] < 55 && code[i + 1] > 40) {
            if(code[i + 1] == 48) {
                str[i + 1].b = str[i].a % 1000000;
                str[i + 1].a = 0;
                continue;
            }
            str[i + 1].a = str[i].a  % 1000000+ str[i].b % 1000000;
            str[i + 1].b = str[i].a % 1000000;
            continue;
        }
        if(code[i + 1] == 48 && i + 1 < len)
        error = 1;
        str[i + 1].a = str[i].a  % 1000000 + str[i].b  % 1000000;
        str[i + 1].b = 0;
        
    }
    if(error == 1 || code[0] == 48)
    printf("0");
    else
    printf("%d", (str[len - 1].a+ str[len - 1].b) % 1000000) ;
    
    return 0;
}