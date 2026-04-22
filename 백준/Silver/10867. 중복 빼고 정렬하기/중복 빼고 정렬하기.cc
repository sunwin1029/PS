#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    set <int> arr;

    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        arr.insert(tmp);
    }

    for(int x : arr) {
        cout << x << " ";
    }


    return 0;
}