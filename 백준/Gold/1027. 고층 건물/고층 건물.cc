#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector <int> arr(n);

    for(int i = 0; i < n; i++) cin >> arr[i];

    int res = 0;

    for(int i = 0; i < n; i++) {
        int view_possible = 0;
        double slope = numeric_limits<double>::lowest();
        for(int j = i + 1; j < n; j++) {
            if(slope < (double)(arr[j] - arr[i]) / (j - i)) {
                view_possible++;
                slope = (double)(arr[j] - arr[i]) / (j - i);
            }
        }

        slope = numeric_limits<double>::max();

        for(int j = i - 1; j >= 0; j--) {
            if(slope > (double)(arr[i] - arr[j]) / (i - j)) {
                view_possible++;
                slope = (double)(arr[i] - arr[j]) / (i - j);
            }
        }

        res = max(res, view_possible);
    }

    cout << res << "\n";

    return 0;
}

