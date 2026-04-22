#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    long long res = 1;
    for(int i = 1; i <= n; i++) {
        res *= i;
    }

    cout << res << "\n";

    return 0;
}