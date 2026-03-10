#include <bits/stdc++.h>
using namespace std;

long long ab(long long x) {
    return x > 0 ? x : -x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;
    cin >> a >> b;

    cout << ab(a - b) << "\n";

    return 0;
}