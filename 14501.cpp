#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    pair <int, int> day[20];
    vector <int> dp(20);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> day[i].first >> day[i].second;
    }

    for(int i = 1; i <= n + 1; i++) {
        dp[i] = max(dp[i], dp[i - 1]);
        int index = i + day[i].first;
        if(index > n + 1) continue;

        dp[index] = max(dp[index], dp[i] + day[i].second);
    }

    cout << dp[n + 1] << "\n";

    return 0;
}