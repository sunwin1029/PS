#include <bits/stdc++.h>
using namespace std;

int n, m;
int city[55][55];

int get_chicken_address(stack <int> s);
void fill_new_city(pair<int, int> loc, int (*new_city)[55]);

int ab(int x) {
    return x > 0 ? x : -x;
}

int f(int loc, int last_chicken_num, stack<int>& s) {
    if (loc >= n * n) {
        return (last_chicken_num == 0) ? get_chicken_address(s) : INT_MAX;
    }
    if (last_chicken_num == 0) return get_chicken_address(s);

    int res1 = INT_MAX, res2 = INT_MAX;

    if (city[loc / n][loc % n] == 2) {
        s.push(loc);
        res1 = f(loc + 1, last_chicken_num - 1, s);
        s.pop();
    }
    res2 = f(loc + 1, last_chicken_num, s);

    return min(res1, res2);
}



int get_chicken_address(stack <int> s) {
    int new_city[55][55];
    int (*ptr)[55] = new_city;
    for(int i = 0; i < 55; i++) {
        for(int j = 0; j < 55; j++)
        new_city[i][j] = INT_MAX;
    }

    while(!s.empty()) {
        int loc = s.top();
        fill_new_city({loc / n, loc % n}, ptr);
        s.pop();
    }

    int chicken_address = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(city[i][j] == 1) chicken_address += new_city[i][j];
        }
    }

    return chicken_address;
}


void fill_new_city(pair<int, int> loc, int (*new_city)[55]) {
    int row = loc.first;
    int column = loc.second;
    int dis;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            dis = ab(row - i) + ab(column - j);
            if(dis < new_city[i][j]) new_city[i][j] = dis;
        }
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
        cin >> city[i][j];
    }

    stack <int> s;
    cout << f(0, m, s) << "\n";

    return 0;
}