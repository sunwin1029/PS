#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class coordinate {
    public:
        int x;
        int y;
};

bool compare(coordinate a, coordinate b) {
    if(a.x == b.x)
        return a.y < b.y;
    else return a.x < b.x;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    coordinate arr[100001];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i].x >> arr[i].y;

    sort(arr, arr + n, compare);

    for(int i = 0; i < n; i++) cout << arr[i].x << " " << arr[i].y << "\n";
}