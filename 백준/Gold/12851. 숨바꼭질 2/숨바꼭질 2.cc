#include <bits/stdc++.h>
using namespace std;

int n, k;
int amt;
int best = INT_MAX;
vector<int> short_dis(200200, INT_MAX);
vector<int> amt_short_dis(200200, 0);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    queue<tuple<int, int, int>> q;  // index, cost, way_amt
    q.push({n, 0, 1});

    short_dis[n] = 0;
    amt_short_dis[n] = 1;

    while(!q.empty()) {
        tuple<int, int, int> tmp = q.front();
        q.pop();

        if(short_dis[get<0>(tmp)] < get<1>(tmp)) continue;

        int before_index = get<0>(tmp) - 1;
        int next_index = get<0>(tmp) + 1;
        int double_index = get<0>(tmp) * 2;

        if(double_index < 200001 && short_dis[double_index] > get<1>(tmp) + 1) {
            short_dis[double_index] = get<1>(tmp) + 1;
            amt_short_dis[double_index] = amt_short_dis[get<0>(tmp)];
            q.push({double_index, short_dis[double_index],
                    amt_short_dis[double_index]});
        } 
        else if(double_index < 200001 && short_dis[double_index] == get<1>(tmp) + 1) {
            amt_short_dis[double_index] += amt_short_dis[get<0>(tmp)];
        }

        if(before_index >= 0 &&short_dis[before_index] > get<1>(tmp) + 1) {
            short_dis[before_index] = get<1>(tmp) + 1;
            amt_short_dis[before_index] = amt_short_dis[get<0>(tmp)];
            q.push({before_index, short_dis[before_index],
                    amt_short_dis[before_index]});
        } 
        else if(before_index >= 0 && short_dis[before_index] == get<1>(tmp) + 1) {
            amt_short_dis[before_index] += amt_short_dis[get<0>(tmp)];
        }

        if(next_index < 100001 && short_dis[next_index] > get<1>(tmp) + 1) {
            short_dis[next_index] = get<1>(tmp) + 1;
            amt_short_dis[next_index] = amt_short_dis[get<0>(tmp)];
            q.push({next_index, short_dis[next_index],
                    amt_short_dis[next_index]});
        }
        else if(next_index < 100001 && short_dis[next_index] == get<1>(tmp) + 1) {
            amt_short_dis[next_index] += amt_short_dis[get<0>(tmp)];
        }
    }

    cout << short_dis[k] << "\n" << amt_short_dis[k] << "\n";


    return 0;
}