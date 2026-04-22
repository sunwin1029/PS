#include <bits/stdc++.h>
using namespace std;

int dp[4040][4040];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    cin >> a >> b;
    int res = 0;

    for(int i = 1; i <= a.length(); i++) {
        for(int j = 1; j <= b.length(); j++) {
            if(a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                res = max(res, dp[i][j]);
            }
            else {
                dp[i][j] = 0;
            }
        }
    }

    cout << res << "\n";


    return 0;
}