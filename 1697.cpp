#include <bits/stdc++.h>
using namespace std;

int n, k;
vector <int> dp(200200);

struct cmp {
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
        return a.second > b.second;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    fill(dp.begin(), dp.end(), -1);

    cin >> n >> k;

    priority_queue <pair <int, int>, vector<pair <int, int>>, cmp> q; // {num, cal_amt}

    q.push({n, 0});
    dp[n] = 0;
    while(true) {
        pair <int, int> tmp;
        tmp = q.top();
        q.pop();
        if(tmp.first == k) {
            cout << tmp.second << "\n";
            break;
        }
        if(tmp.first * 2 < 200200 && dp[2 * tmp.first] == -1) {
            dp[2 * tmp.first] = tmp.second + 1;
            q.push({tmp.first * 2, tmp.second + 1});
        }
        if(tmp.first + 1 < 200001 && dp[tmp.first + 1] == -1) {
            dp[tmp.first + 1] = tmp.second + 1;
            q.push({tmp.first + 1, tmp.second + 1});
        }
        if(tmp.first > 0 && dp[tmp.first - 1] == -1) {
            dp[tmp.first - 1] = tmp.second + 1;
            q.push({tmp.first - 1, tmp.second + 1});
        }
        
        
    }



    return 0;
}