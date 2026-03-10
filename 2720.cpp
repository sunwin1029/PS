#include <bits/stdc++.h>
using namespace std;

void program(int cash) {
    int q = 0;
    int d = 0;
    int n = 0;
    int p = 0;

    while(cash >= 25) {
        cash -= 25;
        q++;
    }
    while(cash >= 10) {
        cash -= 10;
        d++;
    }
    while(cash >= 5) {
        cash -= 5;
        n++;
    }
    while(cash >= 1) {
        cash -= 1;
        p++;
    }

    cout << q << " " << d << " " << n << " " << p << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int tmp;
        cin >> tmp;
        program(tmp);
    }

    return 0;
}