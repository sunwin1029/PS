#include <bits/stdc++.h>
using namespace std;

int k;

pair <int, int> dp[50];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k;

    dp[0] = {1, 0}; // {A amt, B amt}

    for(int i = 1; i <= k; i++) {
        dp[i] = {dp[i - 1].second, dp[i - 1].first + dp[i - 1].second};       
    }

    cout << dp[k].first << " " << dp[k].second << "\n";


    return 0;
}