#include <bits/stdc++.h>
using namespace std;

int n;
int cloth[6];
int t, p;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < 6; i++) cin >> cloth[i];
    cin >> t >> p;

    int shirt_sum = 0;

    for(int i = 0; i < 6; i++) {
        shirt_sum += (cloth[i] + t - 1) / t;
    }

    cout << shirt_sum << "\n" << n / p << " " << n % p << "\n";




    return 0;
}