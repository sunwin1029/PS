#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;


    vector <int> arr(n);
    vector <vector <int>> dp(n, vector<int>(3, 1)); // down, same, up
    int res = 0;



    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if(n == 1) {
        cout << "1\n";
        return 0;
    }

    for(int i = 1; i < n; i++) {
        if(arr[i] == arr[i - 1]) {
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = dp[i - 1][1] + 1;
            dp[i][2] = dp[i - 1][2] + 1;
        }
        else if(arr[i] < arr[i - 1]) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
            dp[i][1] = 1;
            dp[i][2] = 1;
        }
        else if(arr[i] > arr[i - 1]) {
            dp[i][0] = 1;
            dp[i][1] = 1;
            dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]) + 1;
        }

        res = max({res, dp[i][0], dp[i][1], dp[i][2]});
    }

    
    cout << res << "\n";

    return 0;
}