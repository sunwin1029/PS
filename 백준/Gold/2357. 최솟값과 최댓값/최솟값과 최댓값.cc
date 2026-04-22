#include <bits/stdc++.h>
using namespace std;

vector <int> arr;
vector <pair<int, int>> segTree;

pair<int, int> build(int node, int start, int end) {
    if(start == end) return segTree[node] = {arr[start], arr[start]};

    int mid = (start + end) / 2;

    pair <int, int> l, r;

    l = build(node * 2, start, mid);
    r = build(node * 2 + 1, mid + 1, end);

    return segTree[node] = {min(l.first, r.first), max(l.second, r.second)};
}

pair<int, int> query(int node, int start, int end, int l, int r) {
    if(r < start || l > end) return {INT_MAX, INT_MIN};

    if(l <= start && r >= end) return segTree[node];

    int mid = (start + end) / 2;

    pair <int, int> lNode, rNode;

    lNode = query(node * 2, start, mid, l, r);
    rNode = query(node * 2 + 1, mid + 1, end, l, r);

    return {min(lNode.first, rNode.first), max(lNode.second, rNode.second)};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    arr.resize(n + 1);
    segTree.resize(4 * n + 1);

    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    build(1, 1, n);

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        pair<int, int> tmp = query(1, 1, n, a, b);

        cout << tmp.first << " " << tmp.second << "\n";
    }



    return 0;
}