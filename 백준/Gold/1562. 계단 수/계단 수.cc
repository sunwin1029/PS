#include <bits/stdc++.h>
#include <bitset>
#define MOD 1'000'000'000
using namespace std;

int n;

map <tuple <int, int, int>, long long> m;

long long dp(int index, int digit, bitset<10> bs) {
    bs.set(digit);
    int mask = (int)bs.to_ulong();
    if(index == 1) {
        if(bs.all()) return 1;
        else return 0;
    }
    if(m.find({index, digit, mask}) != m.end()) {
        return m[{index, digit, mask}] % MOD;
    }

    if(digit == 0) {
        // bs.set(0);
        m[{index, digit, mask}] = dp(index - 1, 1, bs) % MOD;
    }
    else if(digit == 9) {
        // bs.set(9);
        m[{index, digit, mask}] = dp(index - 1, 8, bs) % MOD;
    }
    else {
        // bs.set(digit);
        m[{index, digit, mask}] = (dp(index - 1, digit + 1, bs) + dp(index - 1, digit - 1, bs)) % MOD;
    }

    return m[{index, digit, mask}];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    long long res = 0;

    bitset<10> bs;
    for(int i = 1; i <= 9; i++) {
        res += dp(n, i, bs);
        res %= MOD;
    }

    cout << res << "\n";

    return 0;
}