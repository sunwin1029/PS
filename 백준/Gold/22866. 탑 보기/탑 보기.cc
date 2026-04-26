#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> building;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    building.resize(n + 1);

    for(int i = 1; i <= n; i++) {
        cin >> building[i];
    }

    stack<pair<int, int>> leftTop;  // height, index
    stack<pair<int, int>> rightTop;

    vector<pair<int, int>> leftStatus(n + 1,  {0, 0});  // amt, nearIndex
    vector<pair<int, int>> rightStatus(n + 1, {0, 0});

    for(int i = 1; i <= n; i++) {
        while(!leftTop.empty() && building[i] >= leftTop.top().first) {
            leftTop.pop();
        }

        leftStatus[i].first = leftTop.size();
        if(leftTop.size() > 0)
            leftStatus[i].second = leftTop.top().second;

        leftTop.push({building[i], i});
    }

    for(int i = n; i >= 1; i--) {
        while(!rightTop.empty() && building[i] >= rightTop.top().first) {
            rightTop.pop();
        }

        rightStatus[i].first = rightTop.size();
        if(rightTop.size() > 0) rightStatus[i].second = rightTop.top().second;

        rightTop.push({building[i], i});
    }

    for(int i = 1; i <= n; i++) {
        if(leftStatus[i].first == 0 && rightStatus[i].first == 0) {
            cout << "0\n";
            continue;
        }

        cout << leftStatus[i].first + rightStatus[i].first << " ";

        if(leftStatus[i].first == 0) {
            cout << rightStatus[i].second << "\n";
            continue;
        }
        if(rightStatus[i].first == 0) {
            cout << leftStatus[i].second << "\n";
            continue;
        } 

        int leftDis = abs(i - leftStatus[i].second);
        int rightDis = abs(i - rightStatus[i].second);


        if(leftDis > rightDis) {
            cout << rightStatus[i].second << "\n";
        }
        else {
            cout << leftStatus[i].second << "\n";
        }
    }

    return 0;
}