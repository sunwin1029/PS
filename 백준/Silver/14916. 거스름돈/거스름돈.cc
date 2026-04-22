#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int num5 = 0;
    int num2 = 0;

    while(n >= 15) {
        n -= 5;
        num5++;
    }

    while(n >= 2) {
        if(n % 5 == 0 && n >= 5) {
            n -= 5;
            num5++;
        }
        else {
            n -= 2;
            num2++;
        }
    }

    if(n > 0) cout << "-1\n";
    else cout << num5 + num2 << "\n";

    return 0;
}