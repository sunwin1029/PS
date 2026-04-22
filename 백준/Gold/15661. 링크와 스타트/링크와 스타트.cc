#include <bits/stdc++.h>
using namespace std;

int return_small(int a, int b);
int balance(int index);
int sum_abil();

int arr[30][30];
int seperate[30];
int n;

int ab_value(int a) {
    return a >= 0 ? a : -a;
}

int return_small(int a, int b) {
    return a < b ? a : b;
}

int balance(int index) {
    int team_1;
    int team_2;
    if(index >= n - 1) {
        return sum_abil();
    }
    else {
        team_1 = balance(index + 1);
        seperate[index] = 1;
        team_2 = balance(index + 1);
        seperate[index] = 0;

        return return_small(team_1, team_2);
    }
}

int sum_abil() {
    int team_1 = 0;
    int team_2 = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(seperate[i] == seperate[j]) {
                if(seperate[i]) {
                    team_1 += arr[i][j];
                    //team_1 += arr[j][i];
                }
                else {
                    team_2 += arr[i][j];
                    //team_2 += arr[j][i];
                }
            }
        }
    }

    return ab_value(team_1 - team_2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
        cin >> arr[i][j];
    }

    cout << balance(0) << "\n";

}