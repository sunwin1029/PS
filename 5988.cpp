#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    while(n--) {
        string s;

        cin >> s;

        if(((s[s.length() - 1] - '0') % 2) == 0) {
            cout << "even\n";
        }
        else {
            cout << "odd\n";
        }
    }

    return 0;
}