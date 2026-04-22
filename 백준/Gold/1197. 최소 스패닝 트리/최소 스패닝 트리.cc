#include <bits/stdc++.h>
using namespace std;

int v, e;
int parent[10100];

struct Compare {
    bool operator()(const tuple<int, int, int> &a, const tuple<int, int, int> &b) {
        return get<2>(a) > get<2>(b);
    }
};

int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

bool combine(int a, int b) {
    a = find(a);
    b = find(b);

    if(a == b) return false;
    parent[b] = a;

    return true;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> v >> e;

    for(int i = 1; i <= v; i++) {
        parent[i] = i;
    }

    priority_queue <tuple <int, int, int>, vector<tuple <int, int, int>>, Compare> pq;

    for(int i = 0; i < e; i++) {
        int ta, tb, tc;
        cin >> ta >> tb >> tc;

        pq.push({ta, tb, tc});
    }

    int select = 0;
    int res = 0;

    while(select < v - 1) {
        tuple <int, int, int> tmp = pq.top();
        pq.pop();

        if(combine(get<0>(tmp), get<1>(tmp))) {
            select++;
            res += get<2>(tmp);
        }
    }

    cout << res << "\n";

    return 0;
}