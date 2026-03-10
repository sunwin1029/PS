#include <bits/stdc++.h>
using namespace std;

int n, m;

void f(int current, int num_amt, string s) {
    if(num_amt > m) {
        cout << s;
        cout << "\n";
        return;
    }
    for(int i = current; i <= n; i++) {
        // cout << i << " ";
        f(i, num_amt + 1, (s + to_string(i) + " "));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    f(1, 1 , "");
    return 0;
}