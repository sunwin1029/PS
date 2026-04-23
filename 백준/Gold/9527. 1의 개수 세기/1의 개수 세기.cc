#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;
    long long aOne = 0;
    long long bOne = 0;

    cin >> a >> b;
    b++;

    long long loc = 1;
    long long oneCycle = 2;

    while(true) {
        aOne += a / oneCycle * loc;

        if(a % oneCycle - loc > 0) {
            aOne += a % oneCycle - loc;
        }

        loc = loc << 1;
        oneCycle = oneCycle << 1;

        if(loc >= a) break;
    }

    loc = 1;
    oneCycle = 2;

    while(true) {
        bOne += b / oneCycle * loc;

        if(b % oneCycle - loc > 0) {
            bOne += b % oneCycle - loc;
        }

        loc = loc << 1;
        oneCycle = oneCycle << 1;

        if(loc >= b) break;
    }

    cout << bOne - aOne << "\n";

    return 0;
}