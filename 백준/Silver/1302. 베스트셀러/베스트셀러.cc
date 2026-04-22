#include <bits/stdc++.h>
using namespace std;

bool Compare (pair<string, int> &a, pair<string, int> &b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    map <string, int> word;

    cin >> n;

    for(int i = 0; i < n; i++) {
        string s;

        cin >> s;

        if(word.count(s)) {
            word[s] = word[s] + 1;
        }
        else {
            word[s] = 1;
        }
    }

    vector <pair<string, int>> arr(word.begin(), word.end());

    sort(arr.begin(), arr.end(), Compare);

    cout << arr[0].first << "\n";


    return 0;
}