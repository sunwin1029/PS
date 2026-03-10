#include <bits/stdc++.h>
using namespace std;

int n;
vector <vector <long long>> dp(1 << 17, vector <long long> (20, -1));
int road[20][20];

long long tsp(long long mask, long long last_visited) {
    if(dp[mask][last_visited] != -1) return dp[mask][last_visited];
    if(!(mask & 1)) return dp[mask][last_visited] = LLONG_MAX;
    if(!(mask & (1 << last_visited))) return dp[mask][last_visited] = LLONG_MAX;

    if(mask == (1 << 0)) {
        return dp[mask][last_visited] = (last_visited == 0 ? 0 : LLONG_MAX);
    }

    long long best = LLONG_MAX;
    long long before_mask = mask & ~(1 << last_visited);

    for(int i = 0; i < n; i++) {
        if(road[i][last_visited] == 0) continue;
        if(!(mask & (1 << i))) continue;        
        long long before_cost = tsp(before_mask, i);
        if(before_cost == LLONG_MAX) continue;

        best = min(best, before_cost + road[i][last_visited]);
    }

    return dp[mask][last_visited] = best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> road[i][j];
        }
    }

    long long res = LLONG_MAX;
    long long mask = (1 << n) - 1;

    for(int i = 1; i < n; i++) {
        if(road[i][0] == 0) continue;
        long long tmp_cost = tsp(mask, i);
        if(tmp_cost == LLONG_MAX) continue;
        res = min(res, tmp_cost + road[i][0]);
    }

    cout << res << "\n";

    return 0;
}