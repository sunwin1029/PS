#include <bits/stdc++.h>
using namespace std;

bool compare(pair<long long, long long>a, pair<long long, long long>b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    pair<long long, long long> p[n];
    for(int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
    sort(p, p + n, compare);
    int cnt = 0;
    int end = 0;
    for(int i = 0; i < n; i++) {
        if(p[i].first < end) continue;
        cnt++;
        end = p[i].second;
    }
    cout << cnt;
    return 0;

}