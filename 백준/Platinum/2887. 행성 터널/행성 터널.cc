#include <bits/stdc++.h>
using namespace std;
using TUPLE = tuple<int, int, int, int>;

int n;
vector <TUPLE> node;

struct Compare{
    bool operator()(tuple<int, int, int> &a, tuple<int, int, int> &b) {
        return get<0>(a) > get<0>(b);
    }
};

priority_queue <tuple <int, int, int>, vector<tuple<int, int, int>>, Compare> pq;
int union_find[100100];

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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++) {
        TUPLE tmp;
        get<0>(tmp) = i;

        cin >> get<1>(tmp) >> get<2>(tmp) >> get<3>(tmp);
        node.push_back(tmp);
    }

    sort(node.begin(), node.end(), [](TUPLE a, TUPLE b) {
        return get<1>(a) < get<1>(b);
    });

    for(int i = 0; i < n - 1; i++) {
        int start = get<0>(node[i]);
        int des = get<0>(node[i + 1]);
        int cost = abs(get<1>(node[i]) - get<1>(node[i + 1]));
        pq.push({cost, start, des});
    }

    sort(node.begin(), node.end(),
         [](TUPLE a, TUPLE b) { return get<2>(a) < get<2>(b); });

    for(int i = 0; i < n - 1; i++) {
        int start = get<0>(node[i]);
        int des = get<0>(node[i + 1]);
        int cost = abs(get<2>(node[i]) - get<2>(node[i + 1]));
        pq.push({cost, start, des});
    }

    sort(node.begin(), node.end(),
         [](TUPLE a, TUPLE b) { return get<3>(a) < get<3>(b); });

    for(int i = 0; i < n - 1; i++) {
        int start = get<0>(node[i]);
        int des = get<0>(node[i + 1]);
        int cost = abs(get<3>(node[i]) - get<3>(node[i + 1]));
        pq.push({cost, start, des});
    }

    // kruskal

    for(int i = 0; i < n; i++) {
        union_find[i] = i;
    }

    int vertex_amt = 0;
    long long res = 0;
    while(vertex_amt < n - 1) {
        tuple <int, int, int> tmp = pq.top();
        pq.pop();

        if(Combine(get<1>(tmp), get<2>(tmp))) {
            vertex_amt++;
            res += get<0>(tmp);
        }
    }


    cout << res << "\n";

    return 0;
}