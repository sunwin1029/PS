#include <bits/stdc++.h>
#define MOD 1'000'000'007
using namespace std;


long long n;

map <long long, long long> m;

long long fibo(long long n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 1;

    if(m.count(n)) return m[n] % MOD;

    if(n % 2 != 0) {
        long long prev = (fibo(n / 2) * fibo(n / 2)) % MOD;
        long long after = (fibo(n / 2 + 1) * fibo(n / 2 + 1)) % MOD;
        m.insert({n, (prev + after) % MOD});
        // return m[n];
    }
    else if(n % 2 == 0) {
        long long prev = fibo(n / 2 - 1) % MOD;
        long long after = fibo(n / 2 ) % MOD;
        m.insert({n, (((prev * 2 + after) * after) % MOD)});
        // return m[n];
    }
    return m[n] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cout << fibo(n) % MOD << "\n";

    return 0;
}