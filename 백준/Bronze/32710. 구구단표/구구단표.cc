#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int res = 0;

    for(int i = 2; i <= 9; i++) {
        for(int j = 1; j <= 9; j++) {
            if(i * j == n || j == n) res = 1;
        }
    }

    cout << res << "\n";

    return 0;
}