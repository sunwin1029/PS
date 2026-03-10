#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector <int> arr (n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), greater<int>());


    int res = 0;

    for(int i = 0; i < n; i++) {
        long long tmp = (i + 1) * arr[i];
        // cout << tmp << "\n";

        res = res > tmp ? res : tmp;
    }

    cout << res << "\n";

    return 0;
}