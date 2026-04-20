#include <bits/stdc++.h>
using namespace std;

void program() {
    string s;
    int k;
    cin >> s >> k;

    int shortestString = INT_MAX;
    int longestString = -1;

    vector<vector<int>> alphabetLoc(26);

    for(int i = 0; i < s.length(); i++) {
        alphabetLoc[s[i] - 'a'].push_back(i);
    }

    for(int i = 0; i < 26; i++) {
        if(alphabetLoc[i].size() < k) continue;

        for(int j = 0; j + k - 1 < alphabetLoc[i].size(); j++) {
            int len = alphabetLoc[i][j + k - 1] - alphabetLoc[i][j] + 1;
            shortestString = min(shortestString, len);
            longestString = max(longestString, len);
        }
    }

    if(shortestString == INT_MAX) {
        cout << -1 << "\n";
    } else {
        cout << shortestString << " " << longestString << "\n";
    }
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