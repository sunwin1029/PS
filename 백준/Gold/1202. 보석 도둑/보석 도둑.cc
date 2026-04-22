#include <bits/stdc++.h>
using namespace std;

int n, k;

bool compare(pair <int, int> a, pair <int, int> b) {
    return a.first < b.first;
}

struct Compare {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        return a.second < b.second;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    vector <pair <int, int>> diamond;
    vector <int> bag;

    for(int i = 0; i < n; i++) {
        pair <int, int> tmp;
        cin >> tmp.first >> tmp.second;
        diamond.push_back(tmp);
    }

    for(int i = 0; i < k; i++) {
        int tmp;
        cin >> tmp;
        bag.push_back(tmp);
    }

    sort(diamond.begin(), diamond.end(), compare);
    sort(bag.begin(), bag.end());

    priority_queue <pair <int, int>, vector <pair <int, int>>, Compare> pq;
    int dia_index = 0;
    long long res = 0;

    for(int i = 0; i < k; i++) {
        while(dia_index < n && diamond[dia_index].first <= bag[i]) {
            pq.push(diamond[dia_index]);
            dia_index++;
        }
        if(!pq.empty()) {
            res += pq.top().second;
            pq.pop();
        }
    }

    cout << res << "\n";

    return 0;
}