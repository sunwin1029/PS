#include <bits/stdc++.h>
using namespace std;

int r, c, k;
int rMax = 3;
int cMax = 3;
vector <vector <int>> arr(100, vector <int>(100));

bool Compare(const pair <int, int> &a, const pair <int, int> &b) {
    if(a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}



void rowProcess() { 
    int newCMax = 0; // rowProcess 이후 갱신될 행의 최대 크기
    vector <vector <int>> tmpArr(100, vector<int>(100));

    for(int i = 0; i < rMax; i++) {
        map<int, int> numCnt; // 수가 몇번 나왔는지 세는 함수
        for(int j = 0; j < cMax; j++) {
            if(arr[i][j] == 0) continue; // 0은 스킵
            numCnt[arr[i][j]]++;
        }

        vector <pair <int, int>> arrangeArr; // 정렬용 배열

        // 정렬용 배열에 정리
        for(auto &p : numCnt) {
            arrangeArr.push_back({p.first, p.second});
        }

        sort(arrangeArr.begin(), arrangeArr.end(), Compare);

        // 행의 최대 크기 재계산
        newCMax = max(newCMax, (int)arrangeArr.size() * 2);
        newCMax = newCMax > 100 ? 100 : newCMax;


        // 원래 배열에 배치
        for(int j = 0; j < arrangeArr.size(); j++) {
            if(j >= 50) break; // 행의 크기가 100이 넘어가는 경우 방지
            tmpArr[i][j * 2] = arrangeArr[j].first;
            tmpArr[i][j * 2 + 1] = arrangeArr[j].second;
        }

    }

    cMax = newCMax;
    arr = tmpArr;
}

void colProcess() {
    int newRMax = 0;
    vector<vector<int>> tmpArr(100, vector<int>(100));

    for(int i = 0; i < cMax; i++) {
        map<int, int> numCnt;  // 수가 몇번 나왔는지 세는 함수

        for(int j = 0; j < rMax; j++) {
            if(arr[j][i] == 0) continue;  // 0은 스킵
            numCnt[arr[j][i]]++;
        }

        vector<pair<int, int>> arrangeArr;  // 정렬용 배열

        // 정렬용 배열에 정리
        for(auto& p : numCnt) {
            arrangeArr.push_back({p.first, p.second});
        }

        sort(arrangeArr.begin(), arrangeArr.end(), Compare);

        // 행의 최대 크기 재계산
        newRMax = max(newRMax, (int)arrangeArr.size() * 2);
        newRMax = newRMax > 100 ? 100 : newRMax;


        // 원래 배열에 배치
        for(int j = 0; j < arrangeArr.size(); j++) {
            if(j >= 50) break;  // 행의 크기가 100이 넘어가는 경우 방지
            tmpArr[j * 2][i] = arrangeArr[j].first;
            tmpArr[j * 2 + 1][i] = arrangeArr[j].second;
        }
    }

    rMax = newRMax;
    arr = tmpArr;
}

bool process() {
    if(rMax >= cMax) {
        rowProcess();
    } else {
        colProcess();
    }

    if(arr[r][c] == k) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c >> k;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    // 인덱스 맞추기 위해서
    r--;
    c--;
    int res = -1;

    if(arr[r][c] == k) {
        cout << 0 << "\n";
        return 0;
    }


    for(int i = 1; i <= 100; i++) {
        if(process()) {
            res = i;
            break;
        }
    }

    cout << res << "\n";


    return 0;
}