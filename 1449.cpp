#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l;
    int res = 0;

    cin >> n >> l;

    priority_queue <int, vector<int>, greater<int>> pq;

    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        pq.push(tmp);
    }

    int possible_end = INT_MIN;

    while(!pq.empty()) {
        int tmp = pq.top();
        pq.pop();

        if(tmp <= possible_end + l - 1) {
            continue;
        }
        else {
            possible_end = tmp;
            res++;
        }
    }

    cout << res << "\n";

    return 0;
}