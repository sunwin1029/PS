#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> road[1010];  // destination, cost
vector<tuple<int, int, string>> min_dis(1010,
                                        {INT_MAX, 0, ""});  // cost, num, road
int start_city, end_city;

struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) { 
        return a.second > b.second;
     }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int start_point, destination, cost;
    for(int i = 0; i < m; i++) {
        cin >> start_point >> destination >> cost;
        road[start_point].push_back({destination, cost});
    }
    cin >> start_city >> end_city;

    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;  // {destination, cost}
    pq.push({start_city, 0});
    min_dis[start_city] = {0, 1, to_string(start_city)};

    while(!pq.empty()) {
        pair<int, int> tmp = pq.top();
        pq.pop();

        int middle = tmp.first;
        int middle_cost = tmp.second;

        if(get<0>(min_dis[middle]) < middle_cost) continue;

        for(int i = 0; i < road[middle].size(); i++) {
            int i_des = road[middle][i].first;
            int i_cost = road[middle][i].second;

            if(get<0>(min_dis[i_des]) > middle_cost + i_cost) {
                get<0>(min_dis[i_des]) = middle_cost + i_cost;  // 최단경로 갱신
                pq.push({i_des, get<0>(min_dis[i_des])});  // 우선순위 큐 삽입
                get<2>(min_dis[i_des]) = get<2>(min_dis[middle]) + " " +
                                         to_string(i_des);  // 경로 변경
                get<1>(min_dis[i_des]) = get<1>(min_dis[middle]) + 1;
            }
        }
    }

    cout << get<0>(min_dis[end_city]) << "\n"
         << get<1>(min_dis[end_city]) << "\n"
         << get<2> (min_dis[end_city]) << "\n";

        return 0;
}