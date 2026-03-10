#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    long long res = 0;
    vector <long long> accumulate_sum(n + 1, 0);
    vector <long long> remainder(m + 1, 0);

    for(int i = 1; i <= n; i++) {
        cin >> accumulate_sum[i];
        accumulate_sum[i] = accumulate_sum[i] + accumulate_sum[i - 1];

        remainder[accumulate_sum[i] % m]++;
    }

    for(int i = 0; i < m; i++) {
        if(remainder[i] < 2) continue;
        res += remainder[i] * (remainder[i] - 1) / 2;
    }
    res += remainder[0];

    

    cout << res << "\n";

    return 0;
}