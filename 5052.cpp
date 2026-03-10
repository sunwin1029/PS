#include <bits/stdc++.h>
using namespace std;

void program() {
    int n;
    cin >> n;
    bool possible = true;

    vector <string> v(n);

    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n - 1; i++) {
        if(v[i].length() > v[i + 1].length()) continue;

        if(v[i] == v[i + 1].substr(0, v[i].length())) {
            possible = false;
            break;
        }
    }

    cout << (possible ? "YES\n" : "NO\n");
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        program();
    }
    return 0;
}