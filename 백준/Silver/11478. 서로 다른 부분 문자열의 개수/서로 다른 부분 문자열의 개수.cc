#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    unordered_set <string> us;
    int res = 0;

    cin >> s;

    for(int i = 0; i < s.length(); i++) {
        for(int j = i; j < s.length(); j++) {
            string tmp = s.substr(i, j - i + 1);
            if(us.count(tmp)) {
                continue;
            }
            else {
                us.insert(tmp);
                res++;
            }
        }
    }

    cout << res << "\n";

    return 0;
}