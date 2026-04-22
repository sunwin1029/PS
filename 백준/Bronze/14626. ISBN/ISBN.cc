#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    cin >> s;
    int star;
    int sum = 0;

    for(int i = 0; i < 13; i++) {
        if(s[i] == '*') {
            star = i;
            continue;
        }
        if(i % 2 == 0) sum += s[i] - '0';
        else sum += (s[i] - '0') * 3;
    }


    int r = (10 - (sum % 10)) % 10;
    int m;

    if(star % 2 == 0) m = r;
    else {
        m = (7 * r) % 10;
    }


    cout << m << "\n";


    return 0;
}