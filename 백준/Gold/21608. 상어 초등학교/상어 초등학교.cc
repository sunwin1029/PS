#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> board;
vector<vector<int>> preference;
int n;
int res = 0;

int drow[4] = {-1, 1, 0, 0};  // 상하좌우
int dcol[4] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    board.resize(n + 1, vector<int>(n + 1, 0));
    preference.resize(n * n + 1, vector<int>(5));
    vector<int> prefer(4);

    for(int i = 1; i <= n * n; i++) {
        int studentNum;
        cin >> studentNum;

        // 저장 배열에 입력받기
        for(int j = 0; j < 4; j++) {
            cin >> prefer[j];
            preference[studentNum][j] = prefer[j];
        }

        int desRow = 1;
        int desCol = 1;
        int desLikeAmt = -1;   // 주변에 좋아하는 사람의 수
        int desEmptyAmt = -1;  // 주변에 비어있는칸

        // 놓을 공간 결정
        for(int r = 1; r <= n; r++) {
            for(int c = 1; c <= n; c++) {
                // 이미 배치되어 있는 경우
                if(board[r][c] > 0) continue;

                int likeAmt = 0;
                int emptyAmt = 0;

                // 문제 조건 파악
                for(int d = 0; d < 4; d++) {
                    int newRow = r + drow[d];
                    int newCol = c + dcol[d];

                    // 범위를 벗어난 경우
                    if(newRow < 1 || newRow > n || newCol < 1 || newCol > n)
                        continue;
                    
                    for(int k = 0; k < 4; k++) {
                        // 주변에 좋아하는 사람이 있는 경우
                        if(preference[studentNum][k] == board[newRow][newCol]) {
                            likeAmt++;
                        }
                        
                    }
                    // 주변 칸이 비어있는 경우
                    if(board[newRow][newCol] == 0) {
                        emptyAmt++;
                    }
                }

                if(desLikeAmt < likeAmt ||
                   (desLikeAmt == likeAmt && desEmptyAmt < emptyAmt)) {
                    desRow = r;
                    desCol = c;
                    desLikeAmt = likeAmt;
                    desEmptyAmt = emptyAmt;
                }
            }
        }

        // 학생 위치 정해주기
        board[desRow][desCol] = studentNum;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int nearLikeAmt = 0;
            for(int d = 0; d < 4; d++) {
                int newRow = i + drow[d];
                int newCol = j + dcol[d];

                if(newRow < 1 || newRow > n || newCol < 1 || newCol > n)
                    continue;

                for(int k = 0; k < 4; k++) {
                    if(board[newRow][newCol] == preference[board[i][j]][k]) {
                        nearLikeAmt++;
                        break;
                    }
                }
            }
            switch(nearLikeAmt) {
                case 1:
                    res += 1;
                    break;
                case 2:
                    res += 10;
                    break;
                case 3:
                    res += 100;
                    break;
                case 4:
                    res += 1000;
                    break;
            }
        }
    }

    cout << res << "\n";

    return 0;
}