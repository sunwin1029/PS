#include <bits/stdc++.h>
using namespace std;

int drow[8] = {-1, -1, -1, 0, 0, 1, 1, 1}; 
int dcol[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int n, m, k;

class Ground {
   public:
    int fertilizer = 5;
    int annualFertilizer;
    vector <int> tree;
    // priority_queue<int, vector<int>, greater<int>> tree;  // age

    void initAnnualFertilizer(int f) { annualFertilizer = f; }

    void initF(int f) { fertilizer = f; }

    void plusTree(int z) { tree.push_back(z); }

    void spring() {
        sort(tree.begin(), tree.end());
        vector <int> newTree;
        bool dead = false;
        for(int i = 0; i < tree.size(); i++) {
            int tmpTree = tree[i];

            if(dead) {
                fertilizer += tmpTree / 2;
            }
            else if(tmpTree > fertilizer) {
                dead = true;
                fertilizer += tmpTree / 2;
            }
            else {
                fertilizer -= tmpTree;
                newTree.push_back(tmpTree + 1);
            }
        }

        tree = newTree;
    }

    void fall(int row, int col, vector <vector <Ground>> &board) {
        for(int i = 0; i < tree.size(); i++) {
            if(tree[i] % 5 != 0) {
                continue;
            }
            else {
                for(int j = 0; j < 8; j++) {
                    int newRow = row + drow[j];
                    int newCol = col + dcol[j];

                    if(newRow < 0 || newRow >= n || newCol < 0 || newCol >= n) {
                        continue;
                    }

                    board[newRow][newCol].plusTree(1);
                }
            }
        }
    }

    void winter() {
        fertilizer += annualFertilizer;
    }

    int treeNum() {
        return tree.size();
    }

};

vector<vector<Ground>> board;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int res = 0;

    cin >> n >> m >> k;
    board.resize(n, vector<Ground>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;

            board[i][j].initAnnualFertilizer(tmp);
        }
    }

    for(int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;

        board[x - 1][y - 1].plusTree(z);
    }

    while(k--) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                board[i][j].spring();
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                board[i][j].fall(i, j, board);
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                board[i][j].winter();
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            res += board[i][j].treeNum();
        }
    }

    cout << res << "\n";

    return 0;
}