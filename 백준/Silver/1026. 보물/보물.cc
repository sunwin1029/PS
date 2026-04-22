#include <bits/stdc++.h>
using namespace std;

int n;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    vector<int> arr1(n);
    vector<int> arr2(n);

    for(int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> arr2[i];
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end(), greater<int>());

    long long res = 0;

    for(int i = 0; i < n; i++) {
        res += arr1[i] * arr2[i];
    }

    cout << res << "\n";

    return 0;
}