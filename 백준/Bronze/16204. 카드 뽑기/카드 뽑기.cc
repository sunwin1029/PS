#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;

    cin >> n >> m >> k;

    if(m >= k) {
        cout << k + n - m;
    }
    else {
        cout << m + n - k;
    }

    return 0;
}