#include <bits/stdc++.h>
using namespace std;

bool compare(pair<long long, long long> a, pair<long long, long long> b) {
    return a.second < b.second;
}

pair <long long, long long> p[300300];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    long long n, m;
    long long left, right;
    bool check = false;
    left = 0;
    right = 0;
    long long sum = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p, p + n, compare);
    /*
    cout << "check\n";
    for(int i = 0; i < n; i++) {
        cout << p[i].first << " " << p[i].second << "\n";
    }
    */
    for(int i = 0; i < n; i++) {
        if(p[i].first < p[i].second) continue;
        if(check == false) {
            left = p[i].second;
            sum += left;
            right = p[i].first;
            check = true;
        }
        if(p[i].second <= right) {
            if(p[i].first > right)
            right = p[i].first;
        }
        if(p[i].first <= right && p[i].second >= left) continue;
        else {
            sum += (right - left) * 3;
            sum += p[i].second - right;
            right = p[i].first;
            left = p[i].second;
        }

    }
    sum += (right - left) * 3;
    sum += m - right;
    cout << sum;
    return 0;
}