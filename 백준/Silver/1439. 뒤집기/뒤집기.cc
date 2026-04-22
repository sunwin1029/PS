#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int zero_group = 0;
    int one_group = 0;

    int check = s[0] - '0';

    for(int i = 0; i < s.length(); i++) {
        if(check != s[i] - '0') {
            if(check == 0) {
                zero_group++;
                check = 1;
            }
            else if(check == 1) {
                one_group++;
                check = 0;
            }
        }
    }
    if(check == 0) {
        zero_group++;
    }
    else {
        one_group++;
    }

    cout << min(zero_group, one_group) << "\n";

    return 0;
}