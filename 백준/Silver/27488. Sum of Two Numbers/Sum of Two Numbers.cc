#include <bits/stdc++.h>
using namespace std;

pair<int, int> splitNumber(int num) {
    int a = 0, b = 0;
    bool toggle = true; // 홀수를 번갈아 가며 배분하기 위한 플래그
    int place = 1; // 자리 수 조정용 (10, 100, ...)

    while (num > 0) {
        int digit = num % 10; // 현재 자릿수 가져오기
        num /= 10; // 다음 자릿수로 이동

        if (digit % 2 == 0) { // 짝수인 경우
            a = a + (digit / 2) * place;
            b = b + (digit / 2) * place;
        } else { // 홀수인 경우
            if (toggle) {
                a = a + (digit / 2 + 1) * place;
                b = b + (digit / 2) * place;
            } else {
                a = a + (digit / 2) * place;
                b = b + (digit / 2 + 1) * place;
            }
            toggle = !toggle; // 다음 홀수는 다른 쪽에 배분
        }

        place *= 10; // 자리 수 증가 (1 -> 10 -> 100 ...)
    }

    return make_pair(a, b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    pair<int, int> res;
    int n;
    for(int i = 0; i < t; i++) {
        cin >> n;
        res = splitNumber(n);
        cout << res.first << " " << res.second << "\n";
    }


    return 0;
}