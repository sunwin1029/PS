#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> program(long long b);

vector<vector<long long>> init(6, vector<long long>(6));

int n;

vector<vector<long long>> multiple_matrix(vector<vector<long long>> &arr1,
                                          vector<vector<long long>> &arr2) {
    vector<vector<long long>> tmp(6, vector<long long>(6, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                tmp[i][j] =
                    (tmp[i][j] + (arr1[i][k] % 1000) * (arr2[k][j] % 1000)) %
                    1000;
            }
        }
    }
    return tmp;
}

vector<vector<long long>> program(long long b) {
    if(b == 1) return init;
    auto half = program(b / 2);
    auto result = multiple_matrix(half, half);

    if(b % 2 == 1) result = multiple_matrix(result, init);
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long b;
    cin >> n >> b;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cin >> init[i][j];
    }

    auto result = program(b);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cout << result[i][j] % 1000<< " ";
        cout << "\n";
    }

    return 0;
}