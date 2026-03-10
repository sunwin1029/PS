#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while(n--) {
        bool isD = false;
        string s;
        cin >> s;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == 'D') {
                cout << i << "\n";
                isD = true;
                break;
            }
        }
        if(!isD) cout << s.length() << "\n";
    }

    return 0;
}