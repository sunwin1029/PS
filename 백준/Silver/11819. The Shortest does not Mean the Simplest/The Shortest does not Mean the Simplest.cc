#include <iostream>
#define ll long long
using namespace std;
ll sum(ll a, ll b, ll c) {
    return (a + b) % c;
}
ll mul(ll a, ll b, ll c) {
    ll res = 0;
    while(b > 0) {
        if(b % 2 == 1) res = sum(a, res, c);
        b /= 2;
        a = sum(a, a, c);
    }
    return res;
}
ll pow(ll a, ll b, ll c) {
    ll res = 1;
    while(b > 0) {
        if(b % 2 == 1) res = mul(a, res, c);
        b /= 2;
        a = mul(a, a, c);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll a, b, c;
    cin >> a >> b >> c;
    cout << pow(a, b, c);
    return 0;
}
