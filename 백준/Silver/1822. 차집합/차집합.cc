#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b;
    int n;
    cin >> a >> b;
    set <int> s;
    set <int> s_2;
    set <int>::iterator iter;
    for(int i = 0; i< a; i++) {
        cin >> n;
        s.insert(n);
    }
    for(int i = 0; i < b; i++) {
        cin >> n;
        iter = s.find(n);
        if(iter == s.end()) continue;
        else s.erase(n);
    }
    if(s.size() == 0) {
        cout << "0";
        return 0;
    }
    cout << s.size() << "\n";
    for(iter = s.begin(); iter != s.end(); ++iter) {
        cout << *iter << " ";
    }

    return 0;
}