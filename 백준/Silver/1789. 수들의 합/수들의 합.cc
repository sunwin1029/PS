#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long s;
    long long sum = 0;

    cin >> s;

    int n = 1;

    while(sum + n <= s) {
        sum += n;
        //cout << "*" << sum << "\n";
        n++;
    }

    cout << n - 1 << "\n";
    


    return 0;
}