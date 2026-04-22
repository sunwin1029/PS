#include <stdio.h>
#include <string.h>
int main() {
    char ar[51][51];
    int a, b;
    int check_wid = 0;
    int check_ver = 0;
    int wid = 0;
    int ver = 0;
    scanf("%d %d", &a, &b);
    for(int i = 0; i < a; i++) {
        scanf("%s", ar[i]);
    }
    for(int i = 0; i < a; i++) {
        check_wid = 0;
        for(int j = 0; j < b; j++) {
            if(ar[i][j] == '.')
            check_wid++;
        }
        if(check_wid == b)
        wid++;
    }
    for(int i = 0; i < b; i++) {
        check_ver = 0;
        for(int j = 0; j < a; j++) {
            if(ar[j][i] == '.') {
                check_ver++;
            }
        }
        if(check_ver == a)
        ver++;
    }
    if(wid >= ver)
    printf("%d", wid);
    else
    printf("%d", ver);
    return 0;
    
}