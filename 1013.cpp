#include <bits/stdc++.h>
using namespace std;

void program() {
    string s;
    cin >> s;

    int n = s.length();
    int i = 0;
    bool impossible = false;

    while(i < n) {
        if(s[i] == '0') {
            if(i + 1 < n && s[i + 1] == '1') {
                i += 2;  
            } else {
                impossible = true;
                break;
            }
        } else if(s[i] == '1') {
            if(i + 2 < n && s[i + 1] == '0' && s[i + 2] == '0') {
                i += 3;

                while(i < n && s[i] == '0') i++;

                if(i >= n || s[i] != '1') {
                    cout << "NO\n";  
                    return;
                }
                i++;

                while(i < n && s[i] == '1') {
                    if(i + 2 < n && s[i + 1] == '0' && s[i + 2] == '0') {
                        break;  
                    }
                    i++;
                }
            } else {
                cout << "NO\n";
                return;
            }
        } else {
            impossible = true;
            break;
        }
    }

    cout << (impossible ? "NO\n" : "YES\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    while(n--) {
        program();
    }
    return 0;
}