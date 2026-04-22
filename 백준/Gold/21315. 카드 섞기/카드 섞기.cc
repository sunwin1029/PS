#include <bits/stdc++.h>
using namespace std;

int n;
int k_1;
int k_2;
vector <int> origin;

vector <int> mix(int k, vector<int> before) {
    if(k < 0) {
        return before;
    }
    vector<int> after;
    vector<int> tmp(before.end() - (int)pow(2, k), before.end());
    after = mix(k - 1, tmp);
    after.insert(after.end(), before.begin(), before.end() - (int)pow(2, k));

    return after;
}

bool vector_same(vector<int>& a, vector<int>& b) {
    return a == b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector <int> res;
    vector <int> arr;
    int max_k = 1;
    while(pow(2, max_k) < n) {
        max_k++;
    }

    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
        origin.push_back(i + 1);
    }

    for(int i = 1; i < max_k; i++) {
        for(int j = 1; j < max_k; j++) {
            if(arr == mix(j, mix(i, origin))) {
                cout << i << " " << j << "\n";
                return 0;
            }
        }
    }


    return 0;
}