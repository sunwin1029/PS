#include <bits/stdc++.h>
using namespace std;

int t;

int dp(vector <int> &cost, vector <vector <int>> &sequence, vector<int> &total_cost, int n) {
    if(total_cost[n] > -1) return total_cost[n];

    total_cost[n] = 0;

    for(int i = 0; i < sequence[n].size(); i++) {
        total_cost[n] = max(total_cost[n], dp(cost, sequence, total_cost, sequence[n][i]));
    }
    total_cost[n] += cost[n];

    return total_cost[n];
}

void program() {
    int n, k, final_building;
    cin >> n >> k;
    
    vector <int> cost(n + 1, 0);
    vector <vector <int>> sequence (n + 1);
    vector <int> total_cost(n + 1, -1);

    for(int i = 1; i <= n; i++) {
        cin >> cost[i];
    }

    for(int i = 0; i < k; i++) {
        int pre_condition, can_build;

        cin >> pre_condition >> can_build;

        sequence[can_build].push_back(pre_condition);
    }
    cin >> final_building;

    /*
    for(int i = 1; i <= n; i++) {
        sort(sequence[i].begin(), sequence[i].end(), greater<int>());
    }
    */

    cout << dp(cost, sequence, total_cost, final_building) << "\n";    
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    while(t--) program();

    return 0;
}