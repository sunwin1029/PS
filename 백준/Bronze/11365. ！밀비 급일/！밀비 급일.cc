#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(true) {
        string s;
        getline(cin, s);

        if(s == "END") return 0;

        reverse(s.begin(), s.end());
        cout << s << "\n";
    }

    return 0;
}