#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string str;

    cin >> n;
    cin >> str;

    vector <int> pi(n);

    int j = 0;
    for(int i = 1; i < n; i++) {
        while(j > 0 && str[i] != str[j]) {
            j = pi[j - 1];
        }
        if(str[i] == str[j]) {
            j++;
        }
        pi[i] = j;
    }

    cout << n - pi[n - 1] << "\n";

    return 0;
}