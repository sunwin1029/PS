#include <bits/stdc++.h>
#define MINUS -1
#define PLUS -2
using namespace std;

int n;
void getRes(deque<int> q, string s);

void backTracking(deque<int>& q, int num, int tmp, string s) {
    if(num > n) {
        q.push_back(tmp);

        if(q.size() % 2 != 0) getRes(q, s);

        q.pop_back();
        return;
    }

    // 숫자 이어붙이기
    int connected = tmp * 10 + num;
    backTracking(q, num + 1, connected, s + " " + to_string(num));

    // + 넣기
    q.push_back(tmp);
    q.push_back(PLUS);

    backTracking(q, num + 1, num, s + "+" + to_string(num));

    q.pop_back();
    q.pop_back();

    // - 넣기
    q.push_back(tmp);
    q.push_back(MINUS);

    backTracking(q, num + 1, num, s + "-" + to_string(num));

    q.pop_back();
    q.pop_back();

   
}

void getRes(deque<int> q, string s) {
    int start = q.front();
    q.pop_front();

    while(!q.empty()) {
        int op = q.front();
        q.pop_front();

        int tmp = q.front();
        q.pop_front();

        if(op == MINUS) {
            start -= tmp;
        } else if(op == PLUS) {
            start += tmp;
        }
    }

    if(start == 0) {
        cout << s << "\n";
    }
}

void program() {
    cin >> n;
    deque<int> q;
    backTracking(q, 2, 1, "1");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        program();
        cout << "\n";
    }
    return 0;
}