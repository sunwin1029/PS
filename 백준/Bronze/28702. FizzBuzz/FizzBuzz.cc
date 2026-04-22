#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    bool isDigit = false;
    int x = 0;

    for(int i = 0; i < 3; i++) {
        string s;
        cin >> s;

        if(isdigit(s[0])) {
            x = stoi(s) + (3 - i);
        }
    }

    if(x % 3 == 0 && x % 5 == 0) {
        cout << "FizzBuzz\n";
    }
    else if(x % 3 == 0) {
        cout << "Fizz\n";
    }
    else if(x % 5 == 0) {
        cout << "Buzz\n";
    }
    else {
        cout << x << "\n";
    }

    return 0;
}