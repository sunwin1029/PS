#include <bits/stdc++.h>
#define EMPTY 0
#define RIGHT 1
#define LEFT 2
#define UP 3
#define DOWN 4
#define CHECKPOINT 5
#define WALL -1
using namespace std;

int r, c, k, w;
int chocolate = 0;
vector<vector<int>> board;
queue<tuple<int, int, int>> heater;
vector<pair<int, int>> checkPoint;
vector<vector<int>> temp;
vector<vector<vector<int>>> wall;

int drow[5] = {0, 0, 0, -1, 1};  // 오른쪽, 왼쪽, 위쪽, 아래쪽
int dcol[5] = {0, 1, -1, 0, 0};

bool test();
bool checkOut(int row, int col);
void blowWind();
void diffusion();
void tempDecrease();

void process() {
    while(true) {
        blowWind();
        diffusion();
        tempDecrease();
        chocolate++;

        if(test() || chocolate > 100) {
            return;
        }
    }
}

bool test() {
    bool isOverAll = true;
    for(int i = 0; i < checkPoint.size(); i++) {
        if(temp[checkPoint[i].first][checkPoint[i].second] < k) {
            isOverAll = false;
        }
    }

    return isOverAll;
}

// 범위 확인을 도와주는 함수
bool checkOut(int row, int col) {
    if(row < 1 || row > r || col < 1 || col > c) return true;
    return false;
}

void blowWind() {
    // 온풍기 목록 복사
    queue<tuple<int, int, int>> tmpHeater = heater;

    while(!tmpHeater.empty()) {
        tuple<int, int, int> eachHeater = tmpHeater.front();
        // 현재 히터로 높아지는 공기양을 저장하는 배열
        vector<vector<int>> tmpIncrease(r + 1, vector<int>(c + 1, 0));

        tmpHeater.pop();

        // 온풍기의 위치, 방향 정보 받아오기
        int row = get<0>(eachHeater);
        int col = get<1>(eachHeater);
        int dir = get<2>(eachHeater);
        // 다음 온도 상승량
        int hotAirCondition = 5;

        row = row + drow[dir];
        col = col + dcol[dir];

        // 히터의 공기 도달 불가능
        if(checkOut(row, col)) {
            continue;
        }

        // 히터에서 바로 바람이 나오는 칸(문제 조건상 벽으로 가로막힐 일 없음)
        tmpIncrease[row][col] = hotAirCondition;

        // 상승 온도가 전파될 수 있는 경우
        while(true) {
            // 전파되는 공기의 온도 감소
            hotAirCondition--;

            if(hotAirCondition < 1) break;

            // 새롭게 평가될 열 또는 행
            int newRow = row + drow[dir];
            int newCol = col + dcol[dir];

            // 현재 위치 정보가 범위를 벗어난 경우
            if(checkOut(row, col) || checkOut(newRow, newCol)) {
                break;
            }

            if(dir == UP) {
                for(int y = 1; y <= c; y++) {
                    if(tmpIncrease[row][y] == 0) continue;

                    // 좌상단
                    if(y - 1 > 0) {
                        if(wall[row][y][LEFT] != WALL &&
                           wall[row][y - 1][UP] != WALL) {
                            tmpIncrease[row - 1][y - 1] = hotAirCondition;
                        }
                    }

                    // 상단
                    if(wall[row][y][UP] != WALL) {
                        tmpIncrease[row - 1][y] = hotAirCondition;
                    }

                    // 우상단
                    if(y < c) {
                        if(wall[row][y][RIGHT] != WALL &&
                           wall[row][y + 1][UP] != WALL) {
                            tmpIncrease[row - 1][y + 1] = hotAirCondition;
                        }
                    }
                }
            } else if(dir == DOWN) {
                for(int y = 1; y <= c; y++) {
                    if(tmpIncrease[row][y] == 0) continue;

                    // 좌하단
                    if(y - 1 > 0) {
                        if(wall[row][y][LEFT] != WALL &&
                           wall[row][y - 1][DOWN] != WALL) {
                            tmpIncrease[row + 1][y - 1] = hotAirCondition;
                        }
                    }

                    // 하단
                    if(wall[row][y][DOWN] != WALL) {
                        tmpIncrease[row + 1][y] = hotAirCondition;
                    }

                    // 우하단
                    if(y < c) {
                        if(wall[row][y][RIGHT] != WALL &&
                           wall[row][y + 1][DOWN] != WALL) {
                            tmpIncrease[row + 1][y + 1] = hotAirCondition;
                        }
                    }
                }
            } else if(dir == LEFT) {
                for(int x = 1; x <= r; x++) {
                    // 해당 칸은 전파를 할 수 없음
                    if(tmpIncrease[x][col] == 0) continue;

                    // 좌상단
                    if(x - 1 > 0) {
                        if(wall[x][col][UP] != WALL &&
                           wall[x - 1][col][LEFT] != WALL) {
                            tmpIncrease[x - 1][col - 1] = hotAirCondition;
                        }
                    }
                    // 좌측
                    if(wall[x][col][LEFT] != WALL) {
                        tmpIncrease[x][col - 1] = hotAirCondition;
                    }

                    // 좌하단
                    if(x < r) {
                        if(wall[x][col][DOWN] != WALL &&
                           wall[x + 1][col][LEFT] != WALL) {
                            tmpIncrease[x + 1][col - 1] = hotAirCondition;
                        }
                    }
                }
            } else if(dir == RIGHT) {
                for(int x = 1; x <= r; x++) {
                    // 해당 칸은 전파를 할 수 없음
                    if(tmpIncrease[x][col] == 0) continue;

                    // 우상단
                    if(x - 1 > 0) {
                        if(wall[x][col][UP] != WALL &&
                           wall[x - 1][col][RIGHT] != WALL) {
                            tmpIncrease[x - 1][col + 1] = hotAirCondition;
                        }
                    }
                    // 우측
                    if(wall[x][col][RIGHT] != WALL) {
                        tmpIncrease[x][col + 1] = hotAirCondition;
                    }

                    // 우하단
                    if(x < r) {
                        if(wall[x][col][DOWN] != WALL &&
                           wall[x + 1][col][RIGHT] != WALL) {
                            tmpIncrease[x + 1][col + 1] = hotAirCondition;
                        }
                    }
                }
            }

            row = newRow;
            col = newCol;
        }

        for(int x = 1; x <= r; x++) {
            for(int y = 1; y <= c; y++) {
                temp[x][y] += tmpIncrease[x][y];
            }
        }
    }
}

void diffusion() {
    vector<vector<int>> moveTemp(r + 1, vector<int>(c + 1, 0));

    for(int x = 1; x <= r; x++) {
        for(int y = 1; y <= c; y++) {
            int dif;
            if(y < c && wall[x][y][RIGHT] != WALL) {
                dif = (temp[x][y] - temp[x][y + 1]) / 4;
                moveTemp[x][y] -= dif;
                moveTemp[x][y + 1] += dif;
            }
            if(x < r && wall[x][y][DOWN] != WALL) {
                dif = (temp[x][y] - temp[x + 1][y]) / 4;
                moveTemp[x][y] -= dif;
                moveTemp[x + 1][y] += dif;
            }
        }
    }

    for(int x = 1; x <= r; x++) {
        for(int y = 1; y <= c; y++) {
            temp[x][y] += moveTemp[x][y];
        }
    }
}

void tempDecrease() {
    for(int x = 1; x <= r; x++) {
        if(temp[x][1] > 0) temp[x][1]--;
        if(temp[x][c] > 0) temp[x][c]--;
    }

    for(int y = 2; y <= c - 1; y++) {
        if(temp[1][y] > 0) temp[1][y]--;
        if(temp[r][y] > 0) temp[r][y]--;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c >> k;
    board.resize(r + 1, vector<int>(c + 1));
    wall.resize(r + 1, vector<vector<int>>(c + 1, vector<int>(5)));
    temp.resize(r + 1, vector<int>(c + 1, 0));

    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            cin >> board[i][j];
            if(board[i][j] > 0 && board[i][j] < 5) {
                heater.push({i, j, board[i][j]});
            }
            if(board[i][j] == CHECKPOINT) {
                checkPoint.push_back({i, j});
            }
        }
    }

    cin >> w;

    for(int i = 0; i < w; i++) {
        int x, y, t;

        cin >> x >> y >> t;

        if(t == 0 && x > 1) {
            wall[x][y][UP] = WALL;
            wall[x - 1][y][DOWN] = WALL;
        }
        if(t == 1 && y < c) {
            wall[x][y][RIGHT] = WALL;
            wall[x][y + 1][LEFT] = WALL;
        }
    }

    process();

    cout << (chocolate > 100 ? 101 : chocolate) << "\n";

    return 0;
}