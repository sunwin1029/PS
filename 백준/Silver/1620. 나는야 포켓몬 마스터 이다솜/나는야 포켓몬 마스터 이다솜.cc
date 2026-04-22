#include <bits/stdc++.h>
using namespace std;

int n, m;
unordered_map <int, string> integerToString;
unordered_map <string, int> stringToInteger;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        integerToString.insert({i, s});
        stringToInteger.insert({s, i});
    }

    for(int i = 0; i < m; i ++) {
        string tmp;
        cin >> tmp;

        if(isdigit(tmp[0])) {
            cout << integerToString[stoi(tmp)] << "\n";
        }
        else {
            cout << stringToInteger[tmp] << "\n";
        }
    }

    return 0;
}