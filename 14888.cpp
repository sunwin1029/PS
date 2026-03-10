#include <bits/stdc++.h>
using namespace std;

vector<int> operatorNum(4);
int n;

int backtrackingMax(int val, int index, vector<int> &arr) {
    int res0 = INT_MIN;
    int res1 = INT_MIN;
    int res2 = INT_MIN;
    int res3 = INT_MIN;

    if(index == 0) return backtrackingMax(arr[0], 1, arr);
    if(index == n) return val;

    if(operatorNum[0] > 0) {
        operatorNum[0]--;
        res0 = backtrackingMax(val + arr[index], index + 1, arr);
        operatorNum[0]++;
    }
    if(operatorNum[1] > 0) {
        operatorNum[1]--;
        res1 = backtrackingMax(val - arr[index], index + 1, arr);
        operatorNum[1]++;
    }
    if(operatorNum[2] > 0) {
        operatorNum[2]--;
        res2 = backtrackingMax(val * arr[index], index + 1, arr);
        operatorNum[2]++;
    }
    if(operatorNum[3] > 0) {
        operatorNum[3]--;
        res3 = backtrackingMax(val / arr[index], index + 1, arr);
        operatorNum[3]++;
    }

    return max({res0, res1, res2, res3});
}

int backtrackingMin(int val, int index, vector<int>& arr) {
    int res0 = INT_MAX;
    int res1 = INT_MAX;
    int res2 = INT_MAX;
    int res3 = INT_MAX;

    if(index == 0) return backtrackingMin(arr[0], 1, arr);
    if(index == n) return val;

    if(operatorNum[0] > 0) {
        operatorNum[0]--;
        res0 = backtrackingMin(val + arr[index], index + 1, arr);
        operatorNum[0]++;
    }
    if(operatorNum[1] > 0) {
        operatorNum[1]--;
        res1 = backtrackingMin(val - arr[index], index + 1, arr);
        operatorNum[1]++;
    }
    if(operatorNum[2] > 0) {
        operatorNum[2]--;
        res2 = backtrackingMin(val * arr[index], index + 1, arr);
        operatorNum[2]++;
    }
    if(operatorNum[3] > 0) {
        operatorNum[3]--;
        res3 = backtrackingMin(val / arr[index], index + 1, arr);
        operatorNum[3]++;
    }

    return min({res0, res1, res2, res3});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < 4; i++) {
        cin >> operatorNum[i];
    }

    cout << backtrackingMax(0, 0, arr) << "\n" << backtrackingMin(0, 0, arr) << "\n";


    return 0;
}