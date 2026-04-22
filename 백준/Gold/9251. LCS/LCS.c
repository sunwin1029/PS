#include <stdio.h>
#include <string.h>

int dp[1001][1001] = {0,};
char arr_1[1001];
char arr_2[1001];
int cp(int a, int b) {
    return a > b ? a : b;
}
int main() {
    int len_1, len_2;
    int res = 0;
    scanf("%s", arr_1);
    scanf("%s", arr_2);
    len_1 = strlen(arr_1);
    len_2 = strlen(arr_2);
    // printf("** %s \n %s", arr_1, arr_2);
    // printf("//%d %d \n", len_1, len_2);
    
    for(int i = 1; i <= len_1; i++) {
        for(int j = 1; j <= len_2; j++) {
            if(arr_1[i - 1] == arr_2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }    
            else {
                dp[i][j] = cp(dp[i - 1][j], dp[i][j - 1]);
            }
 
        }
    }
    
    printf("%d", dp[len_1][len_2]);
    return 0;
}