#include <bits/stdc++.h>
#define Pair pair<int, int>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l, p;
    cin >> n;
    priority_queue <int> pq;
    vector <Pair> arr(n);
    int total = 0;

    
    for(int i = 0; i < n; i++) {
        Pair tmp;
        cin >> tmp.first >> tmp.second;

        arr[i] = tmp;
    }

    sort(arr.begin(), arr.end());

    cin >> l >> p;

    int index = 0;
    while(p < l) {
        while(index < n && arr[index].first <= p) {
            pq.push(arr[index++].second);
        }

        if(pq.empty()) {
            cout << "-1\n";
            return 0;
        }
        p += pq.top();
        pq.pop();
        total++;
    }

    cout << total << "\n";

    return 0;
}