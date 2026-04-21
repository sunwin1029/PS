#include <bits/stdc++.h>
using namespace std;

vector <int> height;
vector <pair <int, int>> leftRightHighest;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int h, w;
    cin >> h >> w;

    height.resize(w + 2);
    leftRightHighest.resize(w + 2);

    for(int i = 1; i <= w; i++) {
        cin >> height[i];
    }

    int lmax = 0;
    int rmax = 0;
    for(int i = 1; i <= w; i++) {
        leftRightHighest[i].first = lmax;
        lmax = max(lmax, height[i]);
    }

    for(int i = w; i >= 1; i--) {
        leftRightHighest[i].second = rmax;
        rmax = max(rmax, height[i]);
    }

    int res = 0;

    for(int i = 1; i <= w; i++) {
        int curHeight = height[i];

        int canIncludeAmt = min(leftRightHighest[i].first, leftRightHighest[i].second);

        int finalAmt = canIncludeAmt - curHeight;

        if(finalAmt > 0) {
            res += finalAmt;
        }
    }

    cout << res << "\n";

    return 0;
}