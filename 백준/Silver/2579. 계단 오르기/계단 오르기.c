#include <stdio.h>
int check = 0;
int stair[310] = {0,};
int dp[2][320] = {0,};

int cp(int a, int b) {
    return a>b?a:b;
}
int f(int num, int check) {
    if(num == 0) 
    return 0;
    if(num == 1)
    return stair[1];
    if(dp[0][num] > 0 && check == 0)
    return dp[0][num];
    if(dp[1][num] > 0 && check == 1)
    return dp[1][num];

    if(check == 1) {
        dp[1][num] = f(num - 2, 0) + stair[num];
        return dp[1][num];
    }

    return cp(f(num - 1, 1), f(num - 2, 0)) + stair[num];
}
int main() {
    int num_1;
    dp[0][0] = 0;
    scanf("%d", &num_1);
    for(int i = 1; i < num_1 + 1; i++) {
        scanf("%d", &stair[i]);

    }
 
    
    int res = f(num_1, 0);
    printf("%d", res);

    return 0;
}