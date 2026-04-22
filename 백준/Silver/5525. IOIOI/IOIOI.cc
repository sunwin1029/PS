#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int m;
    string s;

    cin >> n >> m;
    cin >> s;


    int res = 0;
    int cnt = 0;

    for(int i = 0; i <= m - 2; i++) {
        if(s[i] == 'I' && s[i + 1] == 'O' && s[i + 2] == 'I') {
            cnt++;
            i++;
            if(cnt >= n) {
                res++;
            }
        } else {
            cnt = 0;
        }
    }

    cout << res << "\n";


    return 0;
}