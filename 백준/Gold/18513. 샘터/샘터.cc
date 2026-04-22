#include <bits/stdc++.h>
using namespace std;

int n, k;
queue <pair<int, int>> water;
unordered_set <int> used;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    long long res = 0;
    int build_house = 0;

    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        water.push({tmp, 0});
        used.insert(tmp);
    }

    while(build_house < k) {
        pair <int, int> tmp = water.front();
        water.pop();

        if(!used.count(tmp.first - 1)) {
            res += tmp.second + 1;
            water.push({tmp.first - 1, tmp.second + 1});
            used.insert(tmp.first - 1);
            build_house++;
        }
        if(build_house >= k) break;

        if(!used.count(tmp.first + 1)) {
            res += tmp.second + 1;
            water.push({tmp.first + 1, tmp.second + 1});
            used.insert(tmp.first + 1);
            build_house++;
        }

        
    }

    cout << res << "\n";
 
    return 0;
}