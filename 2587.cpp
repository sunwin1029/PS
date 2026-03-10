#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    vector<int> arr(5);

    for(int i = 0; i < 5; i++) cin >> arr[i];
    
    sort(arr.begin(), arr.end());

    int middle = arr[2];

    int avg = 0;

    for(int i = 0; i < 5; i++) avg += arr[i];

    avg /= 5;


    cout << avg << "\n" << middle << "\n";


    return 0;
}