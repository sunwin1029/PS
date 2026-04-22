#include <bits/stdc++.h>
using namespace std;

multiset<long long> nSet;
unordered_set<long long> mSet;
unordered_map<long long, long long> mMap;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long t, n, m;
    cin >> t;
    cin >> n;

    vector<long long> nArr(n + 1, 0);

    for(int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;

        nArr[i] = nArr[i - 1] + tmp;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            nSet.insert(nArr[i] - nArr[j - 1]);
        }
    }

    cin >> m;
    vector<long long> mArr(m + 1, 0);

    for(int i = 1; i <= m; i++) {
        int tmp;
        cin >> tmp;

        mArr[i] = mArr[i - 1] + tmp;
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= i; j++) {
            int tmp = mArr[i] - mArr[j - 1];
            if(!mSet.count(tmp)) {
                mSet.insert(tmp);
                mMap[tmp] = 1;
            } else {
                mMap[tmp] = mMap[tmp] + 1;
            }
        }
    }

    long long res = 0;

    for(int i : nSet) {
        if(mSet.count(t - i)) {
            res += mMap[t - i];
        }
    }

    cout << res << "\n";

    return 0;
}