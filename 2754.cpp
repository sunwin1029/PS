#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int res = 0;
    cin >> s;

    if(s[0] == 'F') {
        cout << "0.0\n";
        return 0;
    }

    switch(s[0]) {
        case 'A':
            res += 40;
            break;
        case 'B':
            res += 30;
            break;
        case 'C':
            res += 20;
            break;
        case 'D':
            res += 10;
    }

    switch(s[1]) {
        case '+':
            res += 3;
            break;
        case '-':
            res -= 3;
            break;
        default:
            break;
    }

    cout << res / 10 << '.' << res % 10 << "\n";


    return 0;
}