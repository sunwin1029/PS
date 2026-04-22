#include <bits/stdc++.h>
#define ll unsigned long long   
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll left, right;
    left = 0;
    right = (1LL << 32) - 1;
    while (left < right) {
        ll mid = (left + right) / 2;
        if(mid * mid >= n) right = mid;
        else left = mid + 1;
    }
    cout << left;

    return 0;
}