#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector <string> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int len = arr[0].length();
    string res = arr[0];

    for(int i = 0; i < len; i++) {
        char tmp = arr[0][i];
        for(int j = 0; j < n; j++) {
            if(arr[j][i] != tmp) {
                res[i] = '?';
                continue;
            }
        }
    }

    cout << res << "\n";

    return 0;
}