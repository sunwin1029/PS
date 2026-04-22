#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string a;
    string b;

    cin >> a;
    cin >> b;

    while(b.length() > a.length()) {
        if(b[b.length() - 1] == 'A') {
            b.pop_back();
        }
        else if(b[b.length() - 1] == 'B') {
            b.pop_back();
            reverse(b.begin(), b.end());
        }
    }

    cout << ((a == b) ? "1\n" : "0\n");



    return 0;
}