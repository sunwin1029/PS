#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    double res = 0;
    double credit = 0;

    for(int i = 0; i < 20; i++) {
        string s;
        double tmp;
        string grade;

        cin >> s >> tmp >> grade;

        if(grade == "P") continue;

        credit += tmp;


        if(grade == "A+") {
            res += 4.5 * tmp;
        }
        else if(grade == "A0") {
            res += 4.0 * tmp;
        }
        else if(grade == "B+") {
            res += 3.5 * tmp;
        }
        else if(grade == "B0") {
            res += 3.0 * tmp;
        }
        else if(grade == "C+") {
            res += 2.5 * tmp;
        }
        else if(grade == "C0") {
            res += 2.0 * tmp;
        }
        else if(grade == "D+") {
            res += 1.5 * tmp;
        }
        else if(grade == "D0") {
            res += 1.0 * tmp;
        }
        else {
            res += 0;
        }
    }

    cout << fixed << setprecision(6) << res / credit << "\n";

    return 0;
}