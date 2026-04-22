#include <bits/stdc++.h>
using namespace std;
int paper[110][110];

int f(int a, int b) {
    if(a - b > 0) return a - b;
    else {
        return 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    int res = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++)
        cin >> paper[i][j];
    }

    res += 2 * (n * m);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            res += f(paper[i][j], paper[i][j - 1]);
    }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= 1; j--) {
            res += f(paper[i][j], paper[i][j + 1]);
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            res += f(paper[i][j], paper[i - 1][j]);
        }
    }
    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= m; j++) {
            res += f(paper[i][j], paper[i + 1][j]);
        }
    }



    cout << res;
    return 0;
}