#include <bits/stdc++.h>
using namespace std;

int type[10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector <int> fruit(n);

    for(int i = 0; i < n; i++) {
        cin >> fruit[i];
    }

    int left = 0;
    int right = 0;
    int type_num = 0;
    int max = 0;

    while(right < n) {
        if(type[fruit[right]] == 0) {
            type_num++;
        }
        type[fruit[right]]++;

        while(type_num > 2) {
            type[fruit[left]]--;
            if(type[fruit[left]] == 0) type_num--;
            left++;
        }

        max = max > right - left + 1 ? max : right - left + 1;
        right++;
    }

    cout << max << "\n";

    return 0;
}