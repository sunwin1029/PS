#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    int res = 0;

    for(int i = 0; i < n; i++) {
        int a, b, c;
        int tmp = 0;

        cin >> a >> b >> c;

        if(a == b && b == c) {
            tmp = 10000 + a * 1000;
        }
        else if(a == b) {
            tmp = 1000 + a * 100;
        }
        else if(b == c) {
            tmp = 1000 + b * 100;
        }
        else if(a == c) {
            tmp = 1000 + a * 100;
        }
        else {
            tmp = max({a, b, c}) * 100;
        }

        res = max(res, tmp);
    }

    cout << res << "\n";

    return 0;
}