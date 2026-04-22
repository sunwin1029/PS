#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cin.ignore();

    vector<string> arr(n + 1);

    for(int i = 1; i <= n; i++) {
        getline(cin, arr[i]);
    }

    for(int i = 1; i <= n; i++) {
        cout << i << ". " << arr[i] << "\n";
    }

    return 0;
}