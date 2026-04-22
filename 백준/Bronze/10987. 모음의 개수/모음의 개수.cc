#include <bits/stdc++.h>
using namespace std;

int main() { 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string a;
    cin >> a;
    
    int res = 0;
    
    for(int i = 0; i < a.length(); i++) {
        if(a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u') res++;
    }
    
    cout << res << "\n";
    
    return 0;
}