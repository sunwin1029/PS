#include <bits/stdc++.h>
using namespace std;

int get_gcd(int a, int b) {
    if(b == 0) return a;
    return get_gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    string board = "";
    string pattern = "";

    for(int i = 0; i < n; i++) {
        char c;
        cin >> c;
        board += c;
    }

    board += board;
    board.pop_back();

    for(int i = 0; i < n; i++) {
        char c;
        cin >> c;
        pattern += c;
    }

    vector <int> pi(1000001);

    int j = 0;
    for(int i = 1; i < pattern.length(); i++) {
        while(j > 0 && pattern[i] != pattern[j]) {
            j = pi[j - 1];
        }
        if(pattern[i] == pattern[j]) j++;
        pi[i] = j;
    }

    j = 0;
    int res_amt = 0;

    for(int i = 0; i < board.length(); i++) {
        while(j > 0 && board[i] != pattern[j]) {
            j = pi[j - 1];
        }

        if(board[i] == pattern[j]) {
            if(j == pattern.length() - 1) {
                res_amt++;
                j = pi[j];
            }
            else {
                j++;
            }
        }
    }

    cout << res_amt / get_gcd(res_amt, pattern.length()) << "/" << pattern.length() / get_gcd(res_amt, pattern.length()) << "\n";



    return 0;
}