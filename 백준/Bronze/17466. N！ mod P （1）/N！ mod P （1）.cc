#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, p;
    long long res = 1;
    cin >> n >> p;

    for(int i = 1; i <= n; i++) {
        res *= i;
        res %= p;
    }
    cout << res;
}