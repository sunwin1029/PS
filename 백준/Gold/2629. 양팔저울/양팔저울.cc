#include <bits/stdc++.h>
using namespace std;

int block_num;
int bead_num;

int block_weight[33];
int bead_weight[10];

int dp[80900]; // 0~39999 => -40000~-1 , 40000 ~ => 0 ~


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> block_num;
    for(int i = 0; i < block_num; i++) {
        cin >> block_weight[i];
    }

    cin >> bead_num;
    for(int i = 0; i < bead_num; i++) {
        cin >> bead_weight[i];
    }

    dp[40000] = 50000;

    for(int i = 0; i < block_num; i++) {
        for(int j = 0; j < 80900; j++) {
            if(dp[j] > 0 && dp[j] != i + 1) {
                if(dp[j + block_weight[i]] == 0) dp[j + block_weight[i]] = i + 1;
                if(dp[j - block_weight[i]] == 0) dp[j - block_weight[i]] = i + 1;
            }
        }
    }

    for(int i = 0; i < bead_num; i++) {
        if(dp[bead_weight[i] + 40000] > 0) {
            cout << "Y "; 
        }
        else {
            cout << "N ";
        }
    }
    cout << "\n";


    return 0;
}