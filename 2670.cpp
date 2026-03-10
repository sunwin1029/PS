#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector <double> arr(n);
    vector <double> dp(n, 0);
    double res = 0;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dp[0] = arr[0];

    for(int i = 1; i < n; i++) {
        if(dp[i - 1] < 1) {
            dp[i] = arr[i];
        }
        else {
            dp[i] = dp[i - 1] * arr[i];
        }
        res = max(res, dp[i]);
    }

    cout.precision(3);
    cout << fixed << res << "\n";


    return 0;
}