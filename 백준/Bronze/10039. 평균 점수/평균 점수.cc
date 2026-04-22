#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int total = 0;

    for(int i = 0; i < 5; i++) {
        int tmp;

        cin >> tmp;

        if(tmp >= 40) total += tmp;
        else total += 40;
    }


    cout << total / 5 << "\n";

    return 0;
}