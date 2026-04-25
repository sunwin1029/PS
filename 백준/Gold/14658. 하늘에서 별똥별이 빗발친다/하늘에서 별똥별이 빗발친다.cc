#include <bits/stdc++.h>
using namespace std;

int n, m, l, k;
vector<pair<int, int>> stars;
int res = 0;

// 해당 별똥별을 트램펄린의 어느 꼭짓점에 둘것인가?
int drow[4] = {1, 1, -1, -1};  // 좌상단, 우상단, 좌하단, 우하단
int dcol[4] = {1, -1, 1, -1};

bool Compare(const pair<int, int>& a, const pair<int, int>& b) {
    if(a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> l >> k;

    stars.resize(k);

    for(int i = 0; i < k; i++) {
        cin >> stars[i].first >> stars[i].second;
    }

    sort(stars.begin(), stars.end(), Compare);

    for(int x = 0; x < k; x++) {
        for(int y = 0; y < k; y++) {
            pair <int, int> point = {stars[x].first, stars[y].second};

            for(int dir = 0; dir < 4; dir++) {
                int starsAmt = 0;
                int rowStart = point.first;
                int colStart = point.second;

                int rowEnd = point.first + drow[dir] * l;
                int colEnd = point.second + dcol[dir] * l;

                if(rowStart > rowEnd) swap(rowStart, rowEnd);
                if(colStart > colEnd) swap(colStart, colEnd);

                for(int j = 0; j < k; j++) {
                    pair<int, int> otherStar = stars[j];

                    int otherRow = otherStar.first;
                    int otherCol = otherStar.second;

                    if(otherRow >= rowStart && otherRow <= rowEnd &&
                       otherCol >= colStart && otherCol <= colEnd) {
                        starsAmt++;
                    }
                }
                res = max(res, starsAmt);
            }
        }
        }

    cout << k - res << "\n";

    return 0;
}