#include <bits/stdc++.h>
using namespace std;

int arr[1010][1010];
bool v[1010];
int n, m, result;

void dfs (int num) {
    v[num] = true;

    for(int i = 1; i <= n; i++) {
        if(arr[num][i] && !v[i])
        dfs(i);
    }
}

int main() {
     ios::sync_with_stdio(false);
     cin.tie(NULL);

    result = 0;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        arr[x][y] = 1;
        arr[y][x] = 1;
    }

    for(int i = 1; i <= n; i++) {
        if(!v[i]) {
            result++;
            dfs(i);   
        }
    }
    cout << result;
    return 0;
}