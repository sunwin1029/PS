#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string str;
    cin >> n >> str;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(str[i]  == '1') cnt++;
    }
    cout << cnt;
    return 0;
}