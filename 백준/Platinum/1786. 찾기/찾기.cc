#include <bits/stdc++.h>
using namespace std;

vector <int> pi(1000001);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string p, t;

    int res_amt = 0;
    vector <int> res;

    getline(cin, t);
    getline(cin, p);

    int j = 0;

    for(int i = 1; i < p.length(); i++) {
        while(j > 0 && p[i] != p[j]) {
            j = pi[j - 1];
        }
        if(p[i] == p[j]) j++;
        pi[i] = j;
    }    

    j = 0;
    for(int i = 0; i < t.length(); i++) {
        while(j > 0 && t[i] != p[j]) {
            j = pi[j - 1];
        }

        if(t[i] == p[j]) {
            if(j == p.length() - 1) {
                res_amt++;
                res.push_back(i - j + 1);

                j = pi[j];
            }
            else {
                j++;
            }
        }
    }

    cout << res_amt << "\n";
    for(int i = 0; i < res_amt; i++) {
        cout << res[i] << "\n";
    }

    return 0;
}