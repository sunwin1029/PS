#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string s;
    cin >> n;
    cin >> s;

    int numA = 0;
    int numB = 0;

    for(int i = 0; i < n; i++) {
        if(s[i] == 'A') numA++;
        else numB++;
    }

    if(numA == numB) {
        cout << "Tie\n";
    }
    else if(numA > numB){
        cout << "A\n";
    }
    else {
        cout << "B\n";
    }

    return 0;
}