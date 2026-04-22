#include <bits/stdc++.h>
using namespace std;
int LCS[1010][1010];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string a;
    string b;
    cin >> a;
    cin >> b;
    for(int i = 1; i <= a.length(); i++) {
        for(int j = 1; j <= b.length(); j++) {
            if(a[i - 1] == b[j - 1]) LCS[i][j] = LCS[i - 1][j - 1] + 1;
            else {
                LCS[i][j] = LCS[i - 1][j] > LCS[i][j - 1] ? LCS[i - 1][j] : LCS[i][j - 1]; 
            }
        }
    }
    cout << LCS[a.length()][b.length()] << "\n";
    if(LCS[a.length()][b.length()] == 0) return 0;
    
    stack <char> s;
    int i = a.length();
    int j = b.length();
    while(true) {
    if(i == 0 || j == 0) break;
    if(LCS[i][j] == 0) break;
    int pivot = LCS[i][j];
    if(a[i - 1] == b[j - 1]) {
        s.push(a[i - 1]);
        i--;
        j--;
        continue;
    }
    if(LCS[i - 1][j] >= LCS[i][j - 1]) {
        i--;
    } else {
        j--;
    }
}
    //cout << "check";

    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }

    
    return 0;
}