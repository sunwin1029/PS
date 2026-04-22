#include <bits/stdc++.h>
using namespace std;

void f(int n, int k) {
    queue <pair <int, string>> q;
    vector <bool> dp(20200);
    fill(dp.begin(), dp.end(), false);

    q.push({n, ""});


    while(!q.empty()) {
        pair <int, string> tmp;
        tmp = q.front();
        q.pop();

        if(tmp.first == k) {
            cout << tmp.second << "\n";
            break;
        }

        if(dp[(tmp.first * 2 % 10000)] == false) {
            dp[(tmp.first * 2 % 10000)] = true;
            q.push({tmp.first * 2 % 10000, tmp.second + "D"});
        }
        int afterS;
        afterS = tmp.first == 0 ? 9999 : tmp.first - 1;
        if(dp[afterS] == false) {
            dp[afterS] = true;
            q.push({afterS, tmp.second + "S"});
        }
        int afterL;
        afterL = (tmp.first % 1000 * 10) + tmp.first / 1000;
        if(dp[afterL] == false) {
            dp[afterL] = true;
            q.push({afterL, tmp.second + "L"});
        }

        int afterR;
        afterR = tmp.first % 10 * 1000 + tmp.first / 10;
        if(dp[afterR] == false) {
            dp[afterR] = true;
            q.push({afterR, tmp.second + "R"});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    int n, k;
    cin >> t;

    for(int i = 0; i < t; i++) {
        cin >> n >> k;
        f(n, k);
    }


    return 0;
}