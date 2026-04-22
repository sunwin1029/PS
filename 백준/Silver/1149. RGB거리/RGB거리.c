#include <stdio.h>

int house[3][1001] = {0,};
int dp[3][1001] = {0,};
int cp(int a, int b) {
    return a<b?a:b;
}
int cp_3(int a, int b, int c) {
    return cp(cp(a, b), c);
}

int f(int num, int col) {
    if(dp[col][num] > 0)
    return dp[col][num];
    if(col == 0) {
        dp[col][num] = cp(f(num - 1, 1), f(num - 1, 2)) + house[col][num];
        return dp[col][num];
    }
    if(col == 1) {
        dp[col][num] = cp(f(num - 1, 0), f(num - 1, 2)) + house[col][num];
        return dp[col][num];
    }
    if(col == 2) {
        dp[col][num] = cp(f(num - 1, 0), f(num - 1, 1)) + house[col][num];
        return dp[col][num];
    }
}

int main() {
    int house_num;
    scanf("%d", &house_num);
    for(int i = 0; i < house_num; i++) {
        for(int j = 0; j < 3; j++)
        house[j][i] = 1000;
    }
    for(int i = 0; i < house_num; i++) {
        for(int j = 0; j < 3; j++)
        scanf("%d", &house[j][i]);
    }
    dp[0][0] = house[0][0];
    dp[1][0] = house[1][0];
    dp[2][0] = house[2][0];
    int res = cp_3(f(house_num, 0), f(house_num, 1), f(house_num, 2));
    printf("%d", res);

    return 0;
}