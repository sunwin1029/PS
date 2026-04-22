#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    char c;

    cin >> c;

    if(c == 'M') {
        cout << "MatKor\n";
    }
    else if(c == 'W') {
        cout << "WiCys\n";
    }
    else if(c == 'C') {
        cout << "CyKor\n";
    }
    else if(c == 'A') {
        cout << "AlKor\n";
    }
    else {
        cout << "$clear\n";
    }

    return 0;
}