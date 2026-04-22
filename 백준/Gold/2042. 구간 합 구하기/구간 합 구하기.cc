#include <bits/stdc++.h>
using namespace std;

vector <long long> arr;
vector <long long> segTree;

// Segment Tree의 초기 구조를 설계하기 위한 함수
// node : segmentTree에서의 index
// start, end : 해당 node가 의미하는 구간
long long build(int node, int start, int end) {
    if(start == end) return segTree[node] = arr[start]; // leaf node인 경우 값 채워주기
    
    int mid = (start + end) / 2; // 중간 지점 계산

    // Non-leaf node의 값 계산 (좌측 자식 + 우측 자식)
    return segTree[node] = build(node * 2, start, mid) + build(node * 2 + 1, mid + 1, end); 
}

// Segment Tree의 특정 위치의 값(구간합)을 구하기 위한 함수
// node : segmentTree에서의 index
// start, end : 해당 node가 담고 있는 구간의 의미(start ~ end의 합)
// l, r : 사용자가 원하는 구간
long long query(int node, int start, int end, int l, int r) {
    // No-Cover
    // 하나도 커버하지 않는 경우(더할 필요 없음)
    if(r < start || l > end) return 0;
    
    // Full-Cover
    // 현재 노드의 범위가 사용자가 원하는 범위에 모두 포함됨(전부 더해야함)
    if(l <= start && end <= r) return segTree[node]; 

    // Partial-Cover
    // 부분적으로 현재 노드의 범위가 사용자가 원하는 범위에 포함된 경우
    // 좌측 자식에서 사용자가 원하는 범위에 포함된 부분 + 우측 자식에서 사용자가 원하는 범위에 포함된 부분
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, l, r) + query(node * 2 + 1, mid + 1, end, l, r);
}

void update(int node, int start, int end, int i, long long newValue) {
    // 해당 노드의 범위 안에 들어오지 않은 경우(업데이트 필요하지 않음)
    if(i < start || i > end) return;

    // leaf node에 도착한 경우
    if(start == end) {
        segTree[node] = newValue;
        return;
    }

    int mid = (start + end) / 2;

    update(node * 2, start, mid, i, newValue); // 좌측 자식노드 업데이트
    update(node * 2 + 1, mid + 1, end, i, newValue); // 우측 자식노드 업데이트

    segTree[node] = segTree[node * 2] + segTree[node * 2 + 1]; // 현재 노드 업데이트
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;

    cin >> n >> m >> k;

    arr.resize(n + 1);
    segTree.resize(4 * n);

    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    build(1, 1, n);

    for(int i = 0; i < m + k; i++) {
        long long opr, l, r;
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