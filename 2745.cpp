#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int b;

    cin >> s >> b;

    long long res = 0;

    int index = 0;
    for(int i = s.length() - 1; i >= 0; i--) {
        long long multiple = index == 0 ? 1 : pow(b, index);
        if(s[i] >= '0' && s[i] <= '9') {
            res += multiple * (s[i] - '0');
        }
        else if(s[i] >= 'A' && s[i] <= 'Z') {
            res += multiple * (s[i] - 'A' + 10);
        }
        index++;
    }

    cout << res << "\n";

    return 0;
}