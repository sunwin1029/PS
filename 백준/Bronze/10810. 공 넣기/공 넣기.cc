#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    vector <int> arr(n + 1, 0);

    for(int x = 0; x < m; x++) {
        int i, j, k;
        cin >> i >> j >> k;

        for(int y = i; y <= j; y++) {
            arr[y] = k;
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}