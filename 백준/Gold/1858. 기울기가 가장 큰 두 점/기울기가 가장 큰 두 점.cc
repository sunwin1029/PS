#include <bits/stdc++.h>
using namespace std;

pair <int, int> p[77777];

class c {
    public:
        int x;
        int y;
        int n;
    
};


bool arePointsOnLine(const c& A, const c& B, const c& C, const c& D) {
    // 벡터 AB와 AC의 외적
    long long cross1 = (long long)(B.x - A.x) * (C.y - A.y) - (long long)(B.y - A.y) * (C.x - A.x);
    // 벡터 AB와 AD의 외적
    long long cross2 = (long long)(B.x - A.x) * (D.y - A.y) - (long long)(B.y - A.y) * (D.x - A.x);
    
    // 두 외적이 모두 0이어야 함
    return (cross1 == 0) && (cross2 == 0);
}

bool compare(c a, c b) {
    return a.x < b.x;
}

double ab(double a) {
    return  a > 0 ? a : -a;
}

pair<int, int> findTwoSmallest(int a, int b, int c, int d) {
    int arr[4] = {a, b, c, d};
    sort(arr, arr + 4); 
    if(arr[0] == arr[1]) return {arr[0], arr[2]};
    return {arr[0], arr[1]};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    c arr[77777];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i].x >> arr[i].y;
        arr[i].n = i + 1;
    }

    sort(arr, arr + n, compare);

    double best = 0;
    c bestA;
    c bestB;
    int resA = 999999;
    int resB = 999999;
    for(int i = 1; i < n; i++) {
        if(fabs(ab((arr[i].y - arr[i - 1].y) / (arr[i].x - arr[i - 1].x)) - best) < 1e-10) {
                if(arePointsOnLine(bestA, bestB, arr[i], arr[i - 1])) {
                //한 직선 상에 있다면
                pair<int, int> tmp = findTwoSmallest(arr[i].n, arr[i - 1].n, resA, resB);
                resA = tmp.first;
                resB = tmp.second;
                }

                else {
                    if(resA > arr[i].n || resA > arr[i - 1].n) {
                        resA = min(arr[i].n, arr[i - 1].n);
                        resB = max(arr[i].n, arr[i - 1].n);
                    }
                }
            }
    
        if(ab((arr[i].y - arr[i - 1].y) / (arr[i].x - arr[i - 1].x)) > best) {
            best = ab((arr[i].y - arr[i - 1].y) / (arr[i].x - arr[i - 1].x));
            bestA = arr[i];
            bestB = arr[i - 1];
            resA = min(arr[i].n, arr[i - 1].n);
            resB = max(arr[i].n, arr[i - 1].n);
        }
    }
    
    if(resA < resB)
    cout << resA << " " << resB;
    else
    cout << resB << " " << resA;

    return 0;
}   