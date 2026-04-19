#include <bits/stdc++.h>
using namespace std;
int dp[10100];

int t;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    dp[0] = 1;

    for(int i = 1; i <= 10050; i++) {
        dp[i] = 1;
    }

    for(int i = 2; i <= 10050; i++) {
        
        dp[i] += dp[i - 2];

    }


    for(int i = 3; i <= 10050; i++) {
        dp[i] += dp[i - 3];
    }



    cin >> t;

    while(t--) {
        int tmp;
        cin >> tmp;
        cout << dp[tmp] << "\n";
    }


    return 0;
}