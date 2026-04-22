#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n * n);
    for(int i = 0; i < n * n; i++)
    cin >> v[i];
    
    nth_element(v.begin(), v.begin() + (n * n) - n, v.end());
    cout << v[n * n - n];
    return 0;
}
