#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    n = 1000 - n;
    int res = 0;

    while(n - 500 >= 0) {
        n -= 500;
        res++;
    }
    while(n - 100 >= 0) {
        n -= 100;
        res++;
    }
    while(n - 50 >= 0) {
        n -= 50;
        res++;
    }
    while(n - 10 >= 0) {
        n -= 10;
        res++;
    }
    while(n - 5 >= 0) {
        n -= 5;
        res++;
    }
    while(n - 1 >= 0) {
        n -= 1;
        res++;
    }

    cout << res << "\n";

    return 0;
}