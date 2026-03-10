#include <bits/stdc++.h>
using namespace std;

// vector<vector<int>> dp_max(100100, vector<int>(3, -1));
// vector<vector<int>> dp_min(100100, vector<int>(3, -1));

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    vector<int> storeMinVal(3, 0);
    vector<int> storeMaxVal(3, 0);

    vector<int> currentMinVal(3, 0);
    vector<int> currentMaxVal(3, 0);

    for(int i = 0; i < n; i++) {
        cin >> currentMinVal[0] >> currentMinVal[1] >> currentMinVal[2];
        for(int j = 0; j < 3; j++) currentMaxVal[j] = currentMinVal[j];

        currentMinVal[0] += min(storeMinVal[0], storeMinVal[1]);
        currentMinVal[1] +=
            min({storeMinVal[0], storeMinVal[1], storeMinVal[2]});
        currentMinVal[2] += min(storeMinVal[1], storeMinVal[2]);

        currentMaxVal[0] += max(storeMaxVal[0], storeMaxVal[1]);
        currentMaxVal[1] +=
            max({storeMaxVal[0], storeMaxVal[1], storeMaxVal[2]});
        currentMaxVal[2] += max(storeMaxVal[1], storeMaxVal[2]);

        for(int j = 0; j < 3; j++) {
            storeMaxVal[j] = currentMaxVal[j];
            storeMinVal[j] = currentMinVal[j];
        }
    }

    cout << max({storeMaxVal[0], storeMaxVal[1], storeMaxVal[2]}) << " "
         << min({storeMinVal[0], storeMinVal[1], storeMinVal[2]}) << "\n";

    return 0;
}