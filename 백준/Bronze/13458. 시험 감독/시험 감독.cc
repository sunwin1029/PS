#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, b, c;
    vector <int> applicant;

    cin >> n;

    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        applicant.push_back(tmp);
    }

    cin >> b >> c;

    for(int i = 0; i < n; i++) {
        applicant[i] -= b;
    }

    long long res = n;

    for(int i = 0; i < n; i++) {
        if(applicant[i] < 1) continue;
        
        if(applicant[i] % c == 0) {
            res += applicant[i] / c;
        }
        else {
            res += applicant[i] / c + 1;
        }
    }
    cout << res << "\n";

    return 0;
}