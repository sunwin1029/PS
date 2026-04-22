#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
    string sa, sb, sc;

    cin >> sa >> sb >> sc;

    a = stoi(sa);
    b = stoi(sb);
    c = stoi(sc);

    string s = sa + sb;


    cout << a + b - c << "\n";

    cout << stoi(s) - c << "\n";

    return 0;
}