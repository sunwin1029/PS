#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    vector<int> A(n);
    vector<int> B(n);
    vector<int> C(n);
    vector<int> D(n);

    for(int i = 0; i < n; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    vector<int> AB(n * n);
    vector<int> CD(n * n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            AB[i * n + j] = A[i] + B[j];
            CD[i * n + j] = C[i] + D[j];
        }
    }

    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());

    int left_index = 0;
    int right_index = n * n - 1;

    long long res = 0;

    while(left_index < n * n && right_index >= 0) {
        long long tmp = AB[left_index] + CD[right_index];
        if(tmp == 0) {
            long long cntA = 1, cntB = 1;

            while(left_index + cntA < n * n &&
                  AB[left_index] == AB[left_index + cntA]) {
                cntA++;
            }
            while(right_index - cntB >= 0 &&
                  CD[right_index] == CD[right_index - cntB]) {
                cntB++;
            }
            res += cntA * cntB;
            left_index += cntA;
            right_index -= cntB;
        } else if(tmp > 0) {
            right_index--;
        } else {
            left_index++;
        }
    }

    cout << res << "\n";

    return 0;
}