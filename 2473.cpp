#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    vector<long long> water;

    cin >> n;

    for(int i = 0; i < n; i++) {
        long long tmp;
        cin >> tmp;
        water.push_back(tmp);
    }

    sort(water.begin(), water.end());

    long long res = LLONG_MAX;
    long long left_res;
    long long right_res;
    long long middle_res;

    for(int i = 1; i < n - 1; i++) {
        int middle_index = i;
        int left_index = 0;
        int right_index = n - 1;

        while(left_index < middle_index && right_index > middle_index) {
            long long tmp =
                water[left_index] + water[middle_index] + water[right_index];
            if(abs(tmp) < res) {
                left_res = water[left_index];
                right_res = water[right_index];
                middle_res = water[middle_index];
                res = abs(tmp);
            }

            if(tmp < 0) {
                left_index++;
            } else {
                right_index--;
            }
        }
    }

    cout << left_res << " " << middle_res << " " << right_res << "\n";

    return 0;
}