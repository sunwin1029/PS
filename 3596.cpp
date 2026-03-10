#include <bits/stdc++.h>
using namespace std;

int n;
int dp[2020];

int mex(unordered_set <int> s) {
    int a = 0;
    while(true) {
        if(!s.count(a)) break;
        a++;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        unordered_set <int> s;

        for(int j = 1; j <= i; j++) {
            int left_size = j - 3;
            int right_size = i - j - 2;

            int grundy;

            if(left_size < 0 && right_size < 0) {
                grundy = 0;
            }

            if(left_size > 0 && right_size > 0) {
                grundy = dp[left_size] ^ dp[right_size];
            }
            else if(left_size > 0) {
                grundy = dp[left_size];
            }
            else if(right_size > 0) {
                grundy = dp[right_size];
            }

            s.insert(grundy);
        }

        dp[i] = mex(s);
    }

    if(dp[n]) {
        cout << "1\n";
    }
    else {
        cout << "2\n";
    }
    
    // debug
    /*
    for(int i = 1; i <= n; i++) {
        cout << dp[i] << " ";
    }
    cout << "\n";
    */
    
    return 0;
}