#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int maxRes = 0;
    
    cin >> n;

    vector <int> arr(n);
    vector <int> dp(n + 1);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++) {
        dp[arr[i]] = dp[arr[i] - 1] + 1;
        maxRes = max(maxRes, dp[arr[i]]);
    }


    cout << n - maxRes << "\n";


    return 0;
}