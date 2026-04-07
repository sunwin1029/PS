#include <bits/stdc++.h>
using namespace std;

int n, m, fuel;
vector<vector<int>> board;
pair<int, int> driver;
vector<pair<int, int>> passenger;
vector<pair<int, int>> destination;
vector<vector<int>> disFromPassenger;  // [i번째 승객의 목적지] [i번째 승객] 과의 거리, 0번은 출발지점
vector<bool> isPassengerArrive; // 승객이 도착

int drow[4] = {-1, 1, 0, 0}; // 상, 하, 좌, 우
int dcol[4] = {0, 0, -1, 1}; 

// 시작점부터 끝점까지 최단경로 얻어오기
int getShortestPath(pair<int, int> startPoint, pair<int, int> endPoint) {
    vector<vector<int>> dis(n + 1, vector<int>(n + 1, -1));

    queue<pair<int, int>> q;
    q.push(startPoint);

    dis[startPoint.first][startPoint.second] = 0;

    while(!q.empty()) {
        if(dis[endPoint.first][endPoint.second] > 0) break;
        pair<int, int> tmp = q.front();
        int prevDis = dis[tmp.first][tmp.second];
        q.pop();

        for(int i = 0; i < 4; i++) {
            int newRow = tmp.first + drow[i];
            int newCol = tmp.second + dcol[i];

            // 영역을 벗어나는 경우
            if(newRow <= 0 || newRow > n || newCol <= 0 || newCol > n) {
                continue;
            }

            // 벽을 만나거나 이미 방문한 장소일 경우
            if(board[newRow][newCol] == 1 || dis[newRow][newCol] > -1) continue;

            dis[newRow][newCol] = prevDis + 1;

            q.push({newRow, newCol});
        }
    }

    return dis[endPoint.first][endPoint.second];
}

// return 값이 다음 시작 위치
int process(int startPointIndex) {
    int nextPassenger = -1;
    int minDis = INT_MAX;
    // 현재 위치에서 최단 거리 손님 찾기
    for(int i = 1; i <= m; i++) {
        if(isPassengerArrive[i] || disFromPassenger[startPointIndex][i] < 0) continue;
        // 최단거리 순
        if(minDis > disFromPassenger[startPointIndex][i]) {
            nextPassenger = i;
            minDis = disFromPassenger[startPointIndex][i];
        }
        // 거리가 같다면
        if(minDis == disFromPassenger[startPointIndex][i]) {
            // 행이 같은 경우, 열이 빠른 순
            if(passenger[nextPassenger].first == passenger[i].first) {
                if(passenger[nextPassenger].second > passenger[i].second) {
                    nextPassenger = i;
                    minDis = disFromPassenger[startPointIndex][i];
                }
            }
            // 행이 빠른순
            if(passenger[nextPassenger].first > passenger[i].first) {
                nextPassenger = i;
                minDis = disFromPassenger[startPointIndex][i];
            }
        }
    }

    if(nextPassenger < 0) return -1;

    fuel -= minDis;
    isPassengerArrive[nextPassenger] = true;

    int toDestinationDis = disFromPassenger[nextPassenger][nextPassenger];

    if(toDestinationDis < 0) return -1;

    if(fuel < toDestinationDis) return -1;

    // 두배 충전!(소모된 연료 기록 안하기 + 1회분 연료 채워넣기)
    fuel += toDestinationDis;


    return nextPassenger;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> fuel;
    board.resize(n + 1, vector<int>(n + 1)); // 지도
    passenger.resize(m + 1);    // 0번의 경우 없음
    destination.resize(m + 1);  // 0번의 경우 출발지
    disFromPassenger.resize(m + 1, vector<int>(m + 1));
    isPassengerArrive.resize(m + 1, false);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> board[i][j];
            
        }
    }

    cin >> destination[0].first >> destination[0].second;

    for(int i = 1; i <= m; i++) {
        cin >> passenger[i].first >> passenger[i].second >>
            destination[i].first >> destination[i].second;
    }


    // 최단거리 집어넣기
    for(int i = 0; i <= m; i++) {
        for(int j = 1; j <= m; j++) {
            disFromPassenger[i][j] =
                getShortestPath(destination[i], passenger[j]);
        }
    }


    int startPoint = 0;
    for(int i = 0; i < m; i++) {
        
        startPoint = process(startPoint);

        // 기름 부족
        if(startPoint < 0) break;
    }
    
    if(startPoint < 0) {
        cout << -1 << "\n";
    }
    else {
        cout << fuel << "\n";
    }

    return 0;
}