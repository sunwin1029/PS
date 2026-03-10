#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;

    cin >> a >> b;

    vector <int> arr(a + b);

    for(int i = 0; i < a + b; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    for(int i = 0; i < a + b; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}