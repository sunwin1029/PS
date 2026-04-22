#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int l, p, v;
    int index = 1;

    while(true) {
        cin >> l >> p >> v;

        if(l == 0 && p == 0 && v == 0) break;

        cout << "Case " << index << ": " << (v / p) * l + (v % p < l ? v % p : l) << "\n";
        index++;
    }

    return 0;
}