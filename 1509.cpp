#include <bits/stdc++.h>
using namespace std;

bool isPal[2550][2550];
vector <int> dp(2550, INT_MAX);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string origin;

    cin >> origin;
    int index = 0;

    for(int i = 0; i < origin.length(); i++) {
        int l, r;

        l = i;
        r = i;
        while(l >= 0 && r < origin.length() && origin[l] == origin[r]) {
            isPal[l][r] = true;
            l--;
            r++;
        }

        l = i;
        r = i + 1;
        while(l >= 0 && r < origin.length() && origin[l] == origin[r]) {
            isPal[l][r] = true;
            l--;
            r++;
        }
    }

    dp[0] = 1;

    for(int i = 0; i < origin.length(); i++) {
        if(i > 0) dp[i] = min(dp[i], dp[i - 1] + 1);
        for(int j = i; j < origin.length(); j++) {
            if(isPal[i][j]) dp[j] = min(dp[j], i == 0 ? 1 : dp[i - 1] + 1);
        }
    }

    cout << dp[origin.length() - 1] << "\n";

    return 0;
}