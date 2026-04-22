#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string a;
    string b;

    cin >> a;
    cin >> b;

    string min_a = a;
    string min_b = b;
    string max_a = a;
    string max_b = b;

    for(int i = 0; i < a.length(); i++) {
        if(min_a[i] == '6') min_a[i] = '5';
        if(min_b[i] == '6') min_b[i] = '5';
        if(max_a[i] == '5') max_a[i] = '6';
        if(max_b[i] == '5') max_b[i] = '6';
    }

    cout << stoi(min_a) + stoi(min_b) << " " << stoi(max_a) + stoi(max_b) << "\n";

    
    return 0;
}