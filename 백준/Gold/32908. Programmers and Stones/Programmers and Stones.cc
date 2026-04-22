#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int sum = 0;
    bool Alice = false;

    cin >> n;

    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if(tmp % 2 == 1) Alice = true;
    }

    if(Alice) cout << "Alice\n";
    else cout << "Dmitry\n";


    return 0;
}