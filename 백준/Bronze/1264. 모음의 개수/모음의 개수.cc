#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(true) {
        string s;
        int res = 0;
        getline(cin, s);

        if(s == "#") {
            break;
        }

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'i' ||
               s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'O' ||
               s[i] == 'I' || s[i] == 'U') {
                res++;
            }
        }

        cout << res << "\n";
    }

    return 0;
}