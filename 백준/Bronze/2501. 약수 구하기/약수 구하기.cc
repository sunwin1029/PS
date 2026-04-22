#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    cin >> n >> k;

    int tmp = 1;
    int i = 0;

    while(tmp <= n) {
        if(n % tmp == 0) i++;

        if(i == k) {
            cout << tmp << "\n";
            return 0;
        }

        tmp++;
    }
    cout << "0\n";


    return 0;
}