//
// Created by sunwin on 2025. 1. 2..
//

#include <iostream>
#include <algorithm>
using namespace std;

int house[200200];

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   int c;
   int res;

   cin >> n >> c;

  for (int i = 0; i < n; i++) {
    cin >> house[i];
  }
  sort(house, house + n);

  int left = 1; // 최소 거리
  int right = house[n - 1] - house[0]; // 최대 거리
  int result = 0;

  while (left <= right) {
    int mid = (left + right) / 2;
    int check = 1; // 첫 번째 집에 공유기를 설치한 상태
    int prev = house[0];

    for (int i = 1; i < n; i++) {
      if (house[i] - prev >= mid) {
        check++;
        prev = house[i];
      }
    }

    if (check >= c) { // 공유기를 더 설치할 수 있으면 거리 증가
      result = mid;
      left = mid + 1;
    } else { // 공유기가 부족하면 거리 감소
      right = mid - 1;
    }
  }
  // 1 9 , 1 5,
   cout << result << endl;
   return 0;



   // 1 2 3 4 5 100 150 200 300
   // 정렬은 되어있는데 한쪽으로 쏠린 경우라면? -> 가운데를 그냥 가면 안될 것 같은데
    /*
       거리를 기준으로?

       그냥 이분탐색으로 절반씩 쪼개나가면서 찾자!
     */

}
