#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string n;
    vector <int> tmp;
    cin >> n;

    int sum = 0;
    bool containZero = false;

    for(int i = 0; i < n.length(); i++) {
        if(n[i] - '0' == 0) containZero = true;
        sum += (n[i] - '0');
        tmp.push_back(n[i] - '0');
    }

    if(sum % 3 != 0 || !containZero) {
        cout << "-1\n";
        return 0;
    }

    sort(tmp.begin(), tmp.end(), greater<int>());

    for(int i = 0; i < tmp.size(); i++) {
        cout << tmp[i];
    }
    cout << "\n";


    return 0;
}