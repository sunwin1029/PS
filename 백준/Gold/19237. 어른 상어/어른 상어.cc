#include <bits/stdc++.h>
#define NOTHING -1
using namespace std;

int n, m, k;

int drow[4] = {-1, 1, 0, 0};
int dcol[4] = {0, 0, -1, 1};
vector<int> sharkDir;
vector<vector<pair<int, int>>> board;  // index, lastTime
vector<pair<int, int>> sharkLocation;
vector<vector<vector<int>>> sharkDirPriority;  // 상어의 우선순위
int sharkAmt;
int res = 0;

void process();
void sharkMove(int index);
void deleteSmell();
void makeSmell();
void deleteShark();

void process() {
    // 상어 이동하기
    for(int i = 0; i < m; i++) {
       sharkMove(i);
    }
    // 상어 내쫓기
    deleteShark();
    // 냄새 상태 변경하기
    deleteSmell();


    makeSmell();
}

// index 번째 상어의 이동
void sharkMove(int index) {
    int curDir = sharkDir[index];  // 현재 상어의 방향
    int nextDir = -1;              // 다음으로 상어가 이동할 방향

    // 현재 상어의 위치
    int row = sharkLocation[index].first;
    int col = sharkLocation[index].second;

    // 이미 사라진 상어
    if(row < 0 || col < 0) return;

    int newRow, newCol;

    for(int i = 0; i < 4; i++) {
        int tmpDir = sharkDirPriority[index][curDir][i];  // 현재

        newRow = row + drow[tmpDir];
        newCol = col + dcol[tmpDir];

        // 이동하지 못하는 칸일 경우
        if(newRow >= n || newRow < 0 || newCol >= n || newCol < 0) {
            continue;
        }

        // 이동하려는 칸이 냄새가 없는 경우
        if(board[newRow][newCol].first == NOTHING) {
            nextDir = tmpDir;
            break;
        }
    }

    // 다음 상어의 위치가 정해진 경우
    if(nextDir >= 0) {
        sharkLocation[index] = {newRow, newCol};
        sharkDir[index] = nextDir;
        return;
    }

    // 자신의 냄새가 있는 칸이 있다면
    for(int i = 0; i < 4; i++) {
        int tmpDir = sharkDirPriority[index][curDir][i];  // 현재

        newRow = row + drow[tmpDir];
        newCol = col + dcol[tmpDir];

        // 이동하지 못하는 칸일 경우
        if(newRow >= n || newRow < 0 || newCol >= n || newCol < 0) {
            continue;
        }

        // 이동하려는 칸이 냄새가 없는 경우
        if(board[newRow][newCol].first == index) {
            nextDir = tmpDir;
            break;
        }
    }

    // 새롭게 이동할 위치가 정해진 경우
    if(nextDir >= 0) {
        sharkLocation[index] = {newRow, newCol};
        sharkDir[index] = nextDir;
        return;
    }
}

// 냄새 제거
void deleteSmell() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j].second > 0) {
                board[i][j].second--;
            }

            if(board[i][j].second == 0) {
                board[i][j] = {NOTHING, NOTHING};
            }
        }
    }
}

// 상어가 냄새 생성
void makeSmell() {
    for(int i = 0; i < m; i++) {
        int row = sharkLocation[i].first;
        int col = sharkLocation[i].second;

        if(row < 0 || col < 0) continue;

        board[row][col] = {i, k};
    }
}

void deleteShark() {
    for(int i = 0; i < m; i++) {
        for(int j = i + 1; j < m; j++) {
            // 위치가 겹칠 경우
            if(sharkLocation[i].first >= 0 &&
               sharkLocation[i] == sharkLocation[j]) {
                sharkLocation[j] = {-1, -1};
                sharkAmt--;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    board.resize(n, vector<pair<int, int>>(n, {NOTHING, NOTHING}));
    sharkDir.resize(m);
    sharkDirPriority.resize(m, vector<vector<int>>(4, vector<int>(4)));
    sharkLocation.resize(m);

    sharkAmt = m;

    // 상어 위치 저장
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;

            if(tmp > 0) {
                sharkLocation[tmp - 1] = {i, j};
            }
        }
    }


    // 방향 우선순위저장
    for(int i = 0; i < m; i++) {
        cin >> sharkDir[i];
        sharkDir[i]--;
    }

    // 상어 우선순위 증가
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < 4; j++) {
            for(int k = 0; k < 4; k++) {
                cin >> sharkDirPriority[i][j][k];
                sharkDirPriority[i][j][k]--;
            }
        }
    }

    // 초기 냄새 생성
    makeSmell();

    while(true) {
        res++;
        process();

        // cout << res << "\n";

        if(sharkAmt < 2 || res > 1000) {
            break;
        }
    }

    cout << (res > 1000 ? -1 : res) << "\n";

    return 0;
}