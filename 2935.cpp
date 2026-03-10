#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b, c;
    cin >> a >> b >> c;

    if(a.length() < c.length()) swap(a, c);

    if(b == "*") {
        for(int i = 0; i < c.length() - 1; i++) {
            a += "0";
        }
    }
    else {
        if(a.length() == c.length()) {
            a[0] = '2';
        }
        else {
            a[a.length() - c.length()] = '1';
        }
    }

    cout << a << "\n";

    return 0;
}