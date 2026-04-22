#include <bits/stdc++.h>
using namespace std;

int n, m;

unordered_map <string, string> str; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        string site;
        cin >> site;
        string password;

        cin >> password;

        str.insert({site, password});
    }


    for(int i = 0; i < m; i++) {
        string site;
        cin >> site;

        cout << str[site] << "\n";
    }


    return 0;
}