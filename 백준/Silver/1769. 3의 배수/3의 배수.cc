#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int tmp = 0;
    int n = 1;

    for(int i = 0; i < s.length(); i++) {
        tmp += s[i] - '0';
    }

    while(tmp >= 10) {
        n++;
        string str_tmp = to_string(tmp);

        tmp = 0;
        for(int i = 0; i < str_tmp.length(); i++) {
            tmp += str_tmp[i] - '0';
        }
    }
    if(s.length() > 1) {
        cout << n << "\n";
    } else {
        cout << "0\n";
    }
    if(tmp % 3 == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}