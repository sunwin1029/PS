#include <iostream>
using namespace std;
int dp[50];

int fibo(int n) {
    if(dp[n] > 0) return dp[n];
    if(n == 0) return 0;
    if(n == 1 || n == 2) return 1;
    dp[n] = fibo(n - 1) + fibo(n -  2);
    
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << fibo(n) << "\n";

    return 0;
}