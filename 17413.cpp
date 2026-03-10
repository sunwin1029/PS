#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    getline(cin, s);
    string res = "";
    string tmp = "";
    bool tag = false;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '<') {
            reverse(tmp.begin(), tmp.end());
            res += tmp;
            tmp = "";
            tag = true;
            res += s[i];
            continue;
        }
        else if(s[i] == '>') {
            tag = false;
            res += s[i];
            continue;
        }
        else if(tag) {
            res += s[i];
        }
        else {
            if(s[i] == ' ') {
                reverse(tmp.begin(), tmp.end());
                res += tmp;
                res += " ";
                tmp = "";
            }
            else {
                tmp += s[i];
            }
        }
    }

    reverse(tmp.begin(), tmp.end());
    res += tmp;

    cout << res << "\n";


    return 0;
}