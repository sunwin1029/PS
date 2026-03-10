#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[10];

    for(int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    int res = 0;
    int sum = 0;

    for(int i = 0; i < 10; i++) {
        sum += arr[i];
        res = abs(100 - sum) <= abs(100 - res) ? sum : res;
    }

    cout << res << "\n";

    return 0;
}