#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    string res(s.length(), ' ');
    bool impossible = false;

    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '.') {
            res[i] = '.';
            continue;
        }
        if(s[i] == 'X') {
            if(i + 1 == s.length()|| s[i + 1] != 'X') {
                impossible = true;
                break;
            }
            if(i + 2 == s.length() || s[i + 2] != 'X') {
                s[i] = '.';
                s[i + 1] = '.';
                res[i] = 'B';
                res[i + 1] = 'B';
                i++;
                continue;
            }
            if(s[i + 3] != 'X') {
                impossible = true;
                break;
            }
            for(int j = 0; j < 4; j++) {
                s[i + j] = '.';
                res[i + j] = 'A';
            }
            i += 3;
        }
    }

    if(impossible) {
        cout << "-1\n";
    }
    else {
        cout << res << "\n";
    }


    return 0;
}