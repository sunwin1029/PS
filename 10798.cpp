#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string arr[5];
    int max_len = 0;

    for(int i = 0; i < 5; i++) {
        cin >> arr[i];
        max_len = max(max_len, (int)arr[i].length());
    }

    for(int i = 0; i < max_len; i++) {
        for(int j = 0; j < 5; j++) {
            if(i >= arr[j].length()) continue;
            else cout << arr[j][i];
        }
    }
    cout << "\n";

    return 0;
}