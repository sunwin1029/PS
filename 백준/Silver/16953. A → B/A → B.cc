#include <bits/stdc++.h>
using namespace std;

int a, b;

int f(int x, int operation) {
    if(x == a) return operation;
    int res = INT_MAX;
    if(x < a) return -1;
    if(x % 2 == 0) res = f(x / 2, operation + 1);
    if(x > 10 && x % 10 == 1) res = min(res, f(x / 10, operation + 1));

    if(res == INT_MAX) return -1;

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;

    cout << f(b, 1) << "\n";

    return 0;
}