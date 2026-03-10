#include <bits/stdc++.h>
#define MOD 1'000'000'007
using namespace std;

vector <long long> arr;
vector <long long> seg;

long long build(int node, int start, int end) {
    if(start == end) return seg[node] = arr[start];

    int mid = (start + end) / 2;

    return seg[node] = (build(node * 2, start, mid) * build(node * 2 + 1, mid + 1, end)) % MOD;
}   

long long query(int node, int start, int end, int l, int r) {
    if(r < start || l > end) return 1;

    if(l <= start && r >= end) return seg[node];

    int mid = (start + end) / 2;

    return (query(node * 2, start, mid, l, r) * query(node * 2 + 1, mid + 1, end, l, r)) % MOD;
}

void update(int node, int start, int end, int index, long long newValue) {
    if(index < start || index > end) return;

    if(start == end) {
        seg[node] = newValue;
        return;
    }

    int mid = (start + end) / 2;

    update(node * 2, start, mid, index, newValue);
    update(node * 2 + 1, mid + 1, end, index, newValue);

    seg[node] = (seg[node * 2] * seg[node * 2 + 1]) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;

    cin >> n >> m >> k;

    arr.resize(n + 1);
    seg.resize(4 * n);


    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    build(1, 1, n);

    for(int i = 0; i < m + k; i++) {
        int opr, l, r;

        cin >> opr >> l >> r;

        if(opr == 1) {
            update(1, 1, n, l, r);
        }
        else {
            cout << query(1, 1, n, l, r) << "\n";
        }
    }

    return 0;
}