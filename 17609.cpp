#include <bits/stdc++.h>
using namespace std;

int pseduo_pelindrome(int l, int r, string s) {
    while(l < r) {
        if(s[l] != s[r]) {
            return 2;
        }
        l++;
        r--;
    }
    return 1;
}


void program() {
    string s;
    cin >> s;

    int l = 0;
    int r = s.length() - 1;
    int res = 0;

    while(l < r) {
        if(s[l] != s[r]) {
            res = min(pseduo_pelindrome(l + 1, r, s), pseduo_pelindrome(l, r - 1, s));
            break;
        }
        l++;
        r--;
    }

    cout << res << "\n";
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        program();
    }

    return 0;
}