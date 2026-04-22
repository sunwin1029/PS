#include <stdio.h>
#include <string.h>
int cp(int a, int b) {
    return a < b ? a : b;
}
int cp_3(int a, int b, int c) {
    return cp(cp(a, b), c);
}

int house[3][1002] = {0,};
int dp[3][1002] = {0,};
int main() {
    
    int house_num, res;
    int tmp = 0;
    scanf("%d", &house_num);
    for(int i = 0; i < house_num; i++) {
        for(int j = 0; j < 3; j++)
        scanf("%d", &house[j][i]);
    }
    dp[0][0] = house[0][0];
    dp[1][0] = house[1][0];
    dp[2][0] = house[2][0];
    int minimum = 1000001;
    for(int x = 0; x < 3; x++) {
        memset(dp, 0, sizeof(dp));
        tmp = house[x][house_num - 1];
        house[x][house_num - 1] = 1000001;
        switch(x) {
            case 0 : 
                    dp[0][1] = 1000001;
                    dp[1][1] = house[1][1] + house[0][0];
                    dp[2][1] = house[2][1] + house[0][0];
                    break;
            case 1 :
                    dp[1][1] = 1000001;
                    dp[0][1] = house[0][1] + house[1][0];
                    dp[2][1] = house[2][1] + house[1][0];
                    break;
            case 2 :
                    dp[2][1] = 1000001;
                    dp[0][1] = house[0][1] + house[2][0];
                    dp[1][1] = house[1][1] + house[2][0];
                    break;
        }
        for(int i = 2; i < house_num; i++) {
            
            for(int j = 0; j < 3; j++) {
                switch(j) {
                    case 0 : 
                            dp[j][i] = cp(dp[1][i - 1], dp[2][i - 1]) + house[j][i];
                            break;
                    case 1 :
                            dp[j][i] = cp(dp[0][i - 1], dp[2][i - 1]) + house[j][i];
                            break;
                    case 2 :
                            dp[j][i] = cp(dp[0][i - 1], dp[1][i - 1]) + house[j][i];
                            break;
                }
            }
        }
        
        res = cp_3(dp[0][house_num - 1], dp[1][house_num - 1], dp[2][house_num - 1]);
        minimum = cp(res, minimum);
        house[x][house_num - 1] = tmp;
    }
    printf("%d", minimum);
    
    return 0;
}