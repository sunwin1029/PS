#include <bits/stdc++.h>
using namespace std;

bool Compare(const string &a, const string &b) {
    return a + b > b + a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector <string> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), Compare);

    string res = "";

    for(int i = 0; i < n; i++) {
        res += arr[i];
    }

    if(res[0] == '0') {
        cout << 0 << "\n";
        return 0;
    }

    cout << res << "\n";

    return 0;
}