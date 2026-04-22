#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    deque<pair<int, int>> d;
    int n, l;
    cin >> n >> l;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        while(!d.empty() && d.front().second < i - l + 1) d.pop_front();
        while(!d.empty() && d.back().first >= x) d.pop_back();
        d.push_back(make_pair(x, i));
        cout << d.front().first << " ";
    }
    return 0;
}