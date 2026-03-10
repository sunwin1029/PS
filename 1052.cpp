#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    long long water_min = LLONG_MAX;
    int max_pow = 1;

    cin >> n >> k;

    while(true) {
        if(pow(2, max_pow) >= n) {
            break;
        }
        max_pow++;
    }

    // cout << max_pow << " ?" << (int)pow(2, max_pow) << "\n";

    long long tmp = 0;
    while(tmp < n && k > 0) {
        long long tmp_recover = tmp;

        tmp += (long long)pow(2, max_pow);
        //cout << k << "?" << tmp << "\n";

        if(tmp >= n) {
            water_min = min(water_min, tmp - n);
            // cout << "!" << water_min << "\n";
            // k++; 이런!
            max_pow--;
            tmp = tmp_recover;
            continue;
        }
        k--;
    }

    cout << water_min << "\n";

    return 0;
}