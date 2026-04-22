#include <bits/stdc++.h>
using namespace std;

int h, w;

vector <vector <char>> rotate(vector <vector <char>>& prev) {
    int row = prev.size();
    int column = prev[0].size();

    vector <vector <char>> rotated(column, vector <char>(row));


    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            rotated[j][row - 1 - i] = prev[i][j];
        }
    }

    return rotated;
}

bool is_okay(const vector <vector <char>>& board) {
    vector <bool> check(board[0].size(), true);

    for(int i = board.size() - 1; i >= 0; i--) {
        for(int j = 0; j < board[0].size(); j++) {
            if(board[i][j] == '#') check[j] = false;
            if(board[i][j] == '.' && check[j] == false) return false;
        }
    }

    cout << board.size() << " " << board[0].size() << "\n";
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            cout << (board[i][j] == '#' ? '.' : '#');
        }
        cout << "\n";
    }

    return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> h >> w;

    vector <vector <char>> board(h, vector<char>(w));

    for(int i = 0; i < h; i++) {
        string str;
        cin >> str;

        for(int j = 0; j < w; j++) {
            board[i][j] = str[j];
        }
    }

    bool is_possible = false;
    for(int i = 0; i < 4; i++) {
        if(is_okay(board)) {
            is_possible = true;
            break;
        }
        board = rotate(board);
    }

    if(!is_possible) cout << "impossible\n";


    return 0;
}