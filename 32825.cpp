#include <bits/stdc++.h>
using namespace std;

int rowInput[4];
int colInput[4];
bool numUsed[14];

int middleArr[3][3];
int res = 0;

void backtracking(int row, int col) {
    if(col >= 3) {
        if(rowInput[row] != 0) return;
        backtracking(row + 1, 0);
        return;
    }

    if(row == 3) {
        if(rowInput[0] == 0 && rowInput[1] == 0 && rowInput[2] == 0 &&
           colInput[0] == 0 && colInput[1] == 0 && colInput[2] == 0)
            res++;
        return;
    }
    for(int i = 1; i <= 13; i++) {
        if(numUsed[i]) continue;

        numUsed[i] = true;
        rowInput[row] -= i;
        colInput[col] -= i;

        if(row == 2 && colInput[col] != 0) {
            numUsed[i] = false;
            rowInput[row] += i;
            colInput[col] += i;
            continue;
        }

        backtracking(row, col + 1);

        numUsed[i] = false;
        rowInput[row] += i;
        colInput[col] += i;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int sum = 0;
    for(int i = 0; i < 4; i++) {
        cin >> rowInput[i];
        sum += rowInput[i];
    }
    for(int j = 0; j < 4; j++) {
        cin >> colInput[j];
        sum += colInput[j];
    }

    if(91 * 2 != sum) {
        cout << "0\n";
        return 0;
    }

    for(int d = 1; d <= 13; d++) {
        int h = colInput[3] - d;
        if(h < 1 || h > 13 || h == d || numUsed[d] || numUsed[h] ||
           rowInput[0] - d < 0 || rowInput[1] - h < 0) {
            numUsed[d] = false;
            continue;
        }
        numUsed[d] = true;
        numUsed[h] = true;
        rowInput[0] -= d;
        rowInput[1] -= h;

        for(int l = 1; l <= 13; l++) {
            int m = rowInput[3] - l;
            if(m < 1 || m > 13 || m == l || numUsed[l] || numUsed[m] ||
               colInput[0] - l < 0 || colInput[1] - m < 0)
                continue;

            numUsed[l] = true;
            numUsed[m] = true;
            colInput[0] -= l;
            colInput[1] -= m;

            backtracking(0, 0);

            numUsed[l] = false;
            numUsed[m] = false;
            colInput[0] += l;
            colInput[1] += m;
        }

        rowInput[0] += d;
        rowInput[1] += h;
        numUsed[h] = false;

        numUsed[d] = false;
    }

    cout << res << "\n";

    return 0;
}