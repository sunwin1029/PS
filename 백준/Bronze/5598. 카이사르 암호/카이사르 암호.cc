#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    for(int i = 0; i < s.length(); i++) {
       char c;
       c = s[i] - 3;

       if(c < 'A') c = (c + 26);
       cout << c;
    }

    cout << "\n";

    return 0;
}