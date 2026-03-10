#include <bits/stdc++.h>
using namespace std;

char board[8][8];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int res = 0;

    for(int i = 0; i < 8; i++) {
        string s;
        cin >> s;

        for(int j = 0; j < 8; j++) {
            if(s[j] == 'F' && (i + j) % 2 == 0) {
                res++;
            }
        }
    }

    cout << res << "\n";


    return 0;
}