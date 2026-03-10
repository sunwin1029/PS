#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int e, s, m;

    cin >> e >> s >> m;

    e %= 15;
    s %= 28;
    m %= 19;


    int res = 1;

    while(true) {
        if(res % 15 == e && res % 28 == s && res % 19 == m) break;
        res++;
    }

    cout << res << "\n";

    return 0;

}