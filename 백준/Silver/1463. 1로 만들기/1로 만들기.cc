#include <bits/stdc++.h>
using namespace std;
int dp[1000100];

int cp_3(int a, int b, int c) {
    if(a <= b && a <= c) return a;
    else if(b <= a && b <= c) return b;
    else return c;
}
int cp_2(int a, int b) {
    return a < b ? a : b;
}
int f(int n) {
    if(n == 1) return 0;
    if(n == 2 || n == 3) return 1;
    if(dp[n] > 0) return dp[n];
    if(n % 2 == 0 && n % 3 == 0) {
        dp[n] = cp_3(f(n / 2), f(n / 3), f(n - 1)) + 1;
        return dp[n];
    }
    else if(n % 2 == 0 && n % 3 != 0) {
        dp[n] = cp_2(f(n / 2), f(n - 1)) + 1;
        return dp[n];
    }
    else if(n % 2 != 0 && n % 3 == 0) {
        dp[n] = cp_2(f(n / 3), f(n - 1)) + 1;
        return dp[n];
    }
    else dp[n] = f(n - 1) + 1;
    return dp[n];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    cout << f(n);
    return 0;
}