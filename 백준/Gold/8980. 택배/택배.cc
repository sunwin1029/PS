#include <bits/stdc++.h>
#define info tuple<int, int, int>
#define p pair<int, int>  // {end_point, weight}
using namespace std;

struct Compare {
    bool operator()(const p& a, const p& b) { return a.first > b.first; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c, m;

    cin >> n >> c >> m;

    vector<info> arr(m);

    for(int i = 0; i < m; i++) {
        cin >> get<0>(arr[i]) >> get<1>(arr[i]) >> get<2>(arr[i]);
    }
    sort(arr.begin(), arr.end());

    multiset<p> ms;

    int currentCapacity = c;
    int res = 0;
    for(int i = 0; i < m; i++) {
        int startPoint = get<0>(arr[i]);
        int endPoint = get<1>(arr[i]);
        int boxAmt = get<2>(arr[i]);
        // 하차
        while(!ms.empty() && ms.begin()->first <= startPoint) {
            res += ms.begin()->second;
            currentCapacity += ms.begin()->second;
            ms.erase(ms.begin());
        }

        ms.insert({endPoint, boxAmt});
        currentCapacity -= boxAmt;

        while(currentCapacity < 0) {
            auto it = prev(ms.end());
            int farEnd = it->first;
            int farWeight = it->second;

            ms.erase(it);

            int overflow = -currentCapacity;

            if(farWeight > overflow) {
                ms.insert({farEnd, farWeight - overflow});
                currentCapacity += overflow;  
            } else {
                currentCapacity += farWeight;
            }
        }
    }

    while(!ms.empty()) {
        res += ms.begin()->second;
        ms.erase(ms.begin());
    }

    cout << res << "\n";

    return 0;
}