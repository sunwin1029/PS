#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;    

    vector <vector <int>> edge(n + 1);
    vector <int> before_question_amt(n + 1, 0);

    for(int i = 0; i < m; i++) {
        int before, after;
        cin >> before >> after;

        edge[before].push_back(after);
        before_question_amt[after]++;
    }

    int remain_problem = n;
    priority_queue<int, vector<int>, greater<int>> no_require_before_qustion;

    for(int i = 1; i <= n; i++) {
        if(before_question_amt[i] == 0) no_require_before_qustion.push(i);
    }

    while(!no_require_before_qustion.empty()) {
        int tmp_question = no_require_before_qustion.top();
        no_require_before_qustion.pop();

        cout << tmp_question << " ";

        for(int i = 0; i < edge[tmp_question].size(); i++) {
            before_question_amt[edge[tmp_question][i]]--;
            if(before_question_amt[edge[tmp_question][i]] == 0) no_require_before_qustion.push(edge[tmp_question][i]);
        }
    }

    cout << "\n";

    return 0;
}