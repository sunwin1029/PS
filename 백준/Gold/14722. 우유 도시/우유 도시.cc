#include <bits/stdc++.h>
#define STRAWBERRY 0
#define CHOCO 1
#define BANANA 2
using namespace std;

int area[1010][1010]; 
int dp[1010][1010][3];  // row, column, eating_flavor
int n;

bool isMilkConnect(int a_type, int b_type);

bool isMilkConnect(int a_type, int b_type) {
    if((b_type - 1 + 3) % 3 == a_type) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
        cin >> area[i][j];
    }

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j < 3; j++) {
            dp[0][i][j] = INT_MIN;
            dp[i][0][j] = INT_MIN;
        }   
    }

    dp[0][1][BANANA] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j][BANANA] = max(dp[i - 1][j][BANANA], dp[i][j - 1][BANANA]);
            dp[i][j][CHOCO] = max(dp[i - 1][j][CHOCO], dp[i][j - 1][CHOCO]);
            dp[i][j][STRAWBERRY] = max(dp[i - 1][j][STRAWBERRY], dp[i][j - 1][STRAWBERRY]);

            int current_flavor = area[i][j];

            dp[i][j][current_flavor] = max(dp[i][j][current_flavor], dp[i][j][(current_flavor - 1 + 3) % 3] + 1);
        }
    }

    int res = max({dp[n][n][STRAWBERRY], dp[n][n][CHOCO], dp[n][n][BANANA]});
    
    cout << res << "\n";


    return 0;
}