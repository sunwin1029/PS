#include <bits/stdc++.h>
using namespace std;

int dp[1010];
int arr[1010];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];

    dp[0] = 0;
    arr[0] = 0;
    int max = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i]) {
                if(dp[j] >= dp[i]) dp[i] = dp[j] + 1;
            }
        }
        max = max > dp[i] ? max : dp[i];
    }
    cout << max << "\n";
    stack <int> s;
    for(int i = n; i >= 1; i--) {
        if(dp[i] == max) {
            s.push(arr[i]);
            max--;
        }
    }
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}