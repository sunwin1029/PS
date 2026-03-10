#include <bits/stdc++.h>
using namespace std;

int n, m;
int start, des;

long long arr[110][110];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    long long cost;

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++)
        arr[i][j] = 1e18;
    }

    for(int i = 0; i < m; i++) {
        cin >> start >> des >> cost;
        arr[start][des] = min(arr[start][des], cost);
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(arr[i][j] == 1e18 || i == j) cout << "0";
            else cout << arr[i][j];
            cout << " ";
        }
        cout << "\n";
    }

    return 0;
}