#include <bits/stdc++.h>
using namespace std;

int N, M, S, G[1010][1010], C[1010];
int G_2[1010][1010], C_2[1010];

void BFS(int v) {
    queue<int> Q;
    Q.push(v);
    C[v] = 1;
    while (!Q.empty()) {
        v = Q.front(); Q.pop();
        cout << v << " ";
        for (int i = 1; i <= N; i++) {
            if (G[v][i] && !C[i]) {
                Q.push(i);
                C[i] = 1;
            }
        }
    }
}

void DFS(int v) {
    cout << v << " ";
    C_2[v] = 1;
    for(int i = 1; i <= N; i++) {
        if(G_2[v][i] && !C_2[i]) DFS(i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> S;
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        G[x][y] = 1;
        G[y][x] = 1;
        G_2[x][y] = 1;
        
        G_2[y][x] = 1;
    }
    DFS(S);
    cout << "\n";
    BFS(S);
    return 0;
}