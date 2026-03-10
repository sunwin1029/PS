#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> union_find(100100);

struct Compare {
    bool operator()(const tuple<int, int, int> &a, const tuple<int, int, int> &b) {
        return get<2>(a) > get<2>(b);
    }
};

int Find(int x) {
    if(union_find[x] == x) return x;
    return union_find[x] = Find(union_find[x]);
}

bool Combine(int a, int b) {
    a = Find(a);
    b = Find(b);

    if(a == b) return false;

    union_find[b] = a;
    
    return true;
}

priority_queue <tuple <int, int, int>, vector <tuple <int, int, int>>, Compare> edge; // start, end, weight

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) union_find[i] = i;

    for(int i = 0; i < m; i++) {
        int start, end, weight;
        cin >> start >> end >> weight;

        edge.push({start, end, weight});
    }

    int vertex_num = 0;
    vector <int> weight;

    while(vertex_num < n - 1) {
        tuple <int, int, int> tmp = edge.top();
        edge.pop();

        if(Combine(get<0>(tmp), get<1>(tmp))) {
            weight.push_back(get<2>(tmp));
            vertex_num++;
        }
    }

    sort(weight.begin(), weight.end(), greater<int>());

    long long res = 0;
    for(int i = 1; i < weight.size(); i++) {
        res += weight[i];
    }

    cout << res << "\n";

    return 0;
}