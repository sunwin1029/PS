#include <bits/stdc++.h>
#define BORDER 6
using namespace std;
int n;
vector<vector<int>> arr;
vector<vector<int>> population;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    population.resize(n + 1, vector<int>(n + 1));
    int res = INT_MAX;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> population[i][j];
        }
    }

    for(int x = 1; x <= n; x++) {
        for(int y = 1; y <= n; y++) {
            for(int d1 = 1; d1 <= n; d1++) {
                for(int d2 = 1; d2 <= n; d2++) {
                    // 경계 조건
                    if(x + d1 + d2 > n) continue;
                    if(y - d1 < 1) continue;
                    if(y + d2 > n) continue;

                    vector<vector<int>> board(n + 1, vector<int>(n + 1, 0));

                    // 1번 경계선
                    for(int i = 0; i <= d1; i++) {
                        board[x + i][y - i] = BORDER;
                    }

                    // 2번 경계선
                    for(int i = 0; i <= d2; i++) {
                        board[x + i][y + i] = BORDER;
                    }

                    // 3번 경계선
                    for(int i = 0; i <= d2; i++) {
                        board[x + d1 + i][y - d1 + i] = BORDER;
                    }

                    // 4번 경계선
                    for(int i = 0; i <= d1; i++) {
                        board[x + d2 + i][y + d2 - i] = BORDER;
                    }

                    // 1번 구역 채우기
                    for(int i = 1; i < x + d1; i++) {
                        for(int j = 1; j <= y; j++) {
                            if(board[i][j] == BORDER) break;
                            board[i][j] = 1;
                        }
                    }

                    // 2번 구역 채우기
                    for(int i = 1; i <= x + d2; i++) {
                        for(int j = n; j >= y + 1; j--) {
                            if(board[i][j] == BORDER) break;
                            board[i][j] = 2;
                        }
                    }

                    // 3번 구역 채우기
                    for(int i = x + d1; i <= n; i++) {
                        for(int j = 1; j <= y - d1 + d2; j++) {
                            if(board[i][j] == BORDER) break;
                            board[i][j] = 3;
                        }
                    }

                    // 4번 구역 채우기
                    for(int i = x + d2 + 1; i <= n; i++) {
                        for(int j = n; j >= y - d1 + d2; j--) {
                            if(board[i][j] == BORDER) break;
                            board[i][j] = 4;
                        }
                    }

                    // 5번 구역 채우기
                    for(int i = 1; i <= n; i++) {
                        for(int j = 1; j <= n; j++) {
                            if(board[i][j] == 0 || board[i][j] == BORDER)
                                board[i][j] = 5;
                        }
                    }

                    // 최소 구역, 최대 구역 구하기
                    int dis1 = 0;
                    int dis2 = 0;
                    int dis3 = 0;
                    int dis4 = 0;
                    int dis5 = 0;

                    for(int i = 1; i <= n; i++) {
                        for(int j = 1; j <= n; j++) {
                            switch(board[i][j]) {
                                case(1):
                                    dis1 += population[i][j];
                                    break;
                                case(2):
                                    dis2 += population[i][j];
                                    break;
                                case(3):
                                    dis3 += population[i][j];
                                    break;
                                case(4):
                                    dis4 += population[i][j];
                                    break;
                                case(5):
                                    dis5 += population[i][j];
                                    break;
                            }
                        }
                    }

                    int minVal = min({dis1, dis2, dis3, dis4, dis5});
                    int maxVal = max({dis1, dis2, dis3, dis4, dis5});

                    res = min(res, maxVal - minVal);
                }
            }
        }
    }

    cout << res << "\n";

    return 0;
}