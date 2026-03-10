#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    string res;

    for(int i = 0; i < n; i++) {
        string tmp;

        cin >> tmp;

        for(int j = 0; j < tmp.length(); j++) {
            if(tmp[j] == 'S') {
                res = tmp;
            }
        }
    }

    cout << res;
    return 0;
}