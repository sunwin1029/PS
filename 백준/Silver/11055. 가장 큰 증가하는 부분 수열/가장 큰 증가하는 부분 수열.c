#include <stdio.h>

int arr[1010];
int dp[1010];

int cp(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n;
    int max = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        dp[i] = arr[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= i; j++) {
            if(arr[i] > arr[j]) { // 증가하는 부분 수열인 경우
                if(dp[i] < arr[i] + dp[j]) // j까지의 최대 증가부분합 + i번째 값 > 기존 i번째의 최대
                dp[i] = dp[j] + arr[i];
                max = cp(max, dp[i]);
            }
        }
    }
    printf("%d", max);

    return 0;
}