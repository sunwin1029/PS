#include <bits/stdc++.h>
using namespace std;

int t, n;

void f() {
    cin >> n;

    unordered_map <string, int> m;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        cin >> s;

        m[s]++;
    }

    int res = 1;
    
    for(const auto& pair : m) {
        res *= (pair.second + 1);
    }
    res--;

    cout << res << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for(int i = 0; i < t; i++) {
        f();
    }

    return 0;
}