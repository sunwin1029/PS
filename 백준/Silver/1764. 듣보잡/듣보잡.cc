#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_set <string> not_listen;
    cin >> n >> m;
    vector <string> res;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        not_listen.insert(s);
    }

    for(int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if(not_listen.count(s)) {
            res.push_back(s);
        }
    }

    sort(res.begin(), res.end());

    cout << res.size() << "\n";
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << "\n";
    }


    return 0;
}