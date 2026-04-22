#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    cin >> n >> k;
    map<long long, long long> m;
    m[0] = 0;
    
    long long sum = 0;
    long long cnt = 0;
    
    for (long long i = 1; i <= n; i++) {
        long long num;
        cin >> num;
        sum += num;
        
        if (sum == k) cnt++;
        cnt += m[sum - k];
        m[sum]++;
    }
    
    cout << cnt;
    return 0;
}