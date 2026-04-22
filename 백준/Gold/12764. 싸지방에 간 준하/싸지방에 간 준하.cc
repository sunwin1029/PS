#include <bits/stdc++.h>
using namespace std;

int n;

struct compare {
    bool operator() (pair <int, int> a, pair<int, int> b) {
        return a.first > b.first;
    }
};

bool Compare(pair <int, int> a, pair <int, int> b) {
    return a.first < b.first;
}

priority_queue <pair <int, int>, vector<pair<int, int>>, compare> q;
priority_queue <int, vector<int>, greater<int>> available_computer;

vector <pair <int, int>> arr;
int res[100100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    int start, end;
    int max_computer = 0;
    int next_computer = -1;

    for(int i = 0; i < n; i++) {
        cin >> start >> end;
        arr.push_back({start, end});
    }
    sort(arr.begin(), arr.end(), Compare);

    // queue가 가지는 정보 -> 끝나는 시간, 사용중인 컴퓨터 정보
    for(int i = 0; i < n; i++) {
        while(q.size() > 0 && arr[i].first > q.top().first) {
            available_computer.push(q.top().second);    
            q.pop();
        }

        if(available_computer.size() == 0) {
            //available_computer.push(++max_computer);
            next_computer = ++max_computer;
        }
        else {
            next_computer = available_computer.top();
            available_computer.pop();
        }

        q.push({arr[i].second, next_computer});
        res[next_computer]++;
    }

    cout << max_computer << "\n";
    for(int i = 1; i <= max_computer; i++) {
        cout << res[i] << " ";
    }
    cout << "\n";

    return 0;
}