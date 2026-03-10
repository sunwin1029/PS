#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    cin >> a >> b;

    cout << (a.length() < b.length() ? "no\n" : "go\n");

    return 0;
}