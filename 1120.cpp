#include <bits/stdc++.h>
using namespace std;

int main() { 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;

    cin >> a >> b;
    int differ_min = INT_MAX;

    for(int i = 0; i <= b.length() - a.length(); i++) {
        int tmp = 0;
        for(int j = 0; j < a.length(); j++) {
            if(a[j] != b[i + j]) tmp++;
        }
        differ_min = min(differ_min, tmp);
        
    }

    cout << differ_min << "\n";

    return 0;
}