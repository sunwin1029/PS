#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    cin >> s;

    for(int i = 0; i < s.length(); i++) {
        int n = s[i] - '0';
        string tmp;

        switch (n)
        {
        case 0:
            tmp = "000";
            break;
        case 1:
            tmp = "001";
            break;
        case 2:
            tmp = "010";
            break;
        case 3:
            tmp = "011";
            break;
        case 4:
            tmp = "100";
            break;
        case 5:
            tmp = "101";
            break;
        case 6:
            tmp = "110";
            break;
        case 7:
            tmp = "111";
            break;
        default:
            break;
        }

        if(i == 0) {
            cout << stoi(tmp);
        }
        else {
            cout << tmp;
        }
    }
    cout << "\n";

    return 0;
}