#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long t;
    cin >> t;

    while(t--) {
        long long x, y;
        cin >> x >> y;

        long long tmp = y - x;
        long long max_num = (int)sqrt(tmp);
        bool complete = false;

        while(max_num * max_num < tmp) {
            if(max_num * max_num + max_num >= tmp) {
                cout << max_num * 2 << "\n";
                complete = true;
                break;
            }
            max_num++;
        }

        if(!complete) {
            cout << max_num * 2 - 1 << "\n";
        }
    }

    return 0;
}