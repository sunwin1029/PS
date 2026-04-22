#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;
    set<string, greater<string>> s;

    while(n--) {
        string tmp;
        string operation;

        cin >> tmp >> operation;

        if(operation == "enter") {
            s.insert(tmp);
        }
        if(operation == "leave") {
            s.erase(tmp);
        }
    }

    for(auto &str : s) {
        cout << str << "\n";
    }
    

    return 0;
}