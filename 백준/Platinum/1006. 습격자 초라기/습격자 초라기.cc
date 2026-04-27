#include <bits/stdc++.h>
#define NOTHING 0
#define UP 1      // 위에가 채워진 상태
#define DOWN 2    // 아래가 채워진 사앹
#define UPDOWN 3  // 위아래 다 채워진 상태
#define INNER 0
#define OUTER 1

using namespace std;

int t;
int n, w;

void search(vector<vector<int>>& dp, vector<vector<int>>& board) {
    for(int i = 2; i <= n; i++) {
        // 0. 아무칸도 안채워진 경우
        dp[i][NOTHING] = dp[i - 1][UPDOWN];

        // 1. 윗쪽만 채워진 경우

        // 1-1. 윗칸을 단독으로 채우는 경우
        dp[i][UP] = min(dp[i][UP], dp[i - 1][UPDOWN] + 1);
        // 1-2. 윗칸을 전칸과 연결짓는 경우
        if(board[i - 1][OUTER] + board[i][OUTER] <= w) {
            dp[i][UP] = min(dp[i][UP], dp[i - 1][DOWN] + 1);
        }

        // 2. 아랫쪽만 채워진 경우

        // 2-1. 아랫칸을 단독으로 채우는 경우
        dp[i][DOWN] = min(dp[i][DOWN], dp[i - 1][UPDOWN] + 1);
        // 2-2. 아랫칸을 전칸과 연결짓는 경우
        if(board[i - 1][INNER] + board[i][INNER] <= w) {
            dp[i][DOWN] = min(dp[i][DOWN], dp[i - 1][UP] + 1);
        }

        // 3. 위, 아래칸 모두 전칸과 연결되는 경우

        if(board[i - 1][OUTER] + board[i][OUTER] <= w &&
           board[i - 1][INNER] + board[i][INNER] <= w) {
            dp[i][UPDOWN] = min(dp[i][UPDOWN], dp[i - 1][NOTHING] + 2);
        }

        // 4. 해당 칸의 위아래를 한번에 묶는 경우
        if(board[i][OUTER] + board[i][INNER] <= w) {
            dp[i][UPDOWN] = min(dp[i][UPDOWN], dp[i - 1][UPDOWN] + 1);
        }

        // 5. 최종적으로 꽉찬 상태 확인
        dp[i][UPDOWN] = min({dp[i][UPDOWN], dp[i][UP] + 1, dp[i][DOWN] + 1});
    }
}

void program() {
    cin >> n >> w;

    int res = INT_MAX;

    vector<vector<int>> dp(n + 1, vector<int>(4, 1e9));
    vector<vector<int>> board(n + 1, vector<int>(2));


    for(int i = 1; i <= n; i++) {
        cin >> board[i][INNER];
    }

    for(int i = 1; i <= n; i++) {
        cin >> board[i][OUTER];
    }

    // n == 1 인 경우
    if(n == 1) {
        if(board[1][INNER] + board[1][OUTER] <= w)
            cout << 1 << "\n";
        else
            cout << 2 << "\n";
        return;
    }

    // 1. 끝과 끝이 연결되지 않은 경우
    dp[1][NOTHING] = 0;
    dp[1][UP] = 1;
    dp[1][DOWN] = 1;
    dp[1][UPDOWN] = 2;

    if(board[1][OUTER] + board[1][INNER] <= w) {
        dp[1][UPDOWN] = 1;
    }
    search(dp, board);

    res = min(res, dp[n][UPDOWN]);

    // 2. 위만 연결된 경우
    if(board[1][OUTER] + board[n][OUTER] <= w) {
        fill(dp.begin(), dp.end(), vector<int>(4, 1e9));
        dp[1][UP] = 1;
        dp[1][UPDOWN] = 2;
        search(dp, board);
        res = min(res, dp[n][DOWN]);
    }

    // 3. 아래만 연결된 경우
    if(board[1][INNER] + board[n][INNER] <= w) {
        fill(dp.begin(), dp.end(), vector<int>(4, 1e9));
        dp[1][DOWN] = 1;
        dp[1][UPDOWN] = 2;
        search(dp, board);
        res = min(res, dp[n][UP]);
    }

    // 4. 둘 다 연결된 경우
    if(board[1][OUTER] + board[n][OUTER] <= w &&
       board[1][INNER] + board[n][INNER] <= w) {
        fill(dp.begin(), dp.end(), vector<int>(4, 1e9));
        dp[1][UPDOWN] = 2;
        search(dp, board);
        res = min(res, dp[n - 1][UPDOWN]);
    }

    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    while(t--) {
        program();
    }

    return 0;
}