#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    if(n % 10 != 0) {
        cout << "-1\n";
        return 0;
    }

    int min5 = 0;
    int min1 = 0;
    int sec10 = 0;

    while(n >= 300) {
        n -= 300;
        min5++;
    }
    while(n >= 60) {
        n -= 60;
        min1++;
    }

    while(n >= 10) {
        n -= 10;
        sec10++;
    }

    cout << min5 << " " << min1 << " " << sec10 << "\n";



    return 0;
}