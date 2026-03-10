#include <bits/stdc++.h>
using namespace std;

int n, s;
long long sum[100100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;

    for(int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;

        sum[i] = sum[i - 1] + tmp;
    }

    int res = INT_MAX;
    int left_ptr = 1;
    int right_ptr = 1;

    while(right_ptr <= n) {
        long long cur = sum[right_ptr] - sum[left_ptr - 1];
        if(cur >= s) {
            res = min(res, right_ptr - left_ptr + 1);
            left_ptr++;
        } else {
            right_ptr++;
        } 
    }

    cout << (res == INT_MAX ? 0 : res) << "\n";

    return 0;
}