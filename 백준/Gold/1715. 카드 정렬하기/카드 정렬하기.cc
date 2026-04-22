#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int res = 0;
    cin >> n;
    priority_queue <int, vector<int>, greater<int>> pq;

    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }

    while(pq.size() > 1) {
        int a, b;
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();

        res += a + b;
        pq.push(a + b);
    }

    cout << res << "\n";

    return 0;
}