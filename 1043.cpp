#include <bits/stdc++.h>
using namespace std;

int n, m;
int know_amt;

bool is_know[55]; // 진실을 아는 번호
bool know_party[55]; // 진실을 말해야 하는 파티
vector <vector <int>> party; // 전체 저장


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> know_amt;
    
    // 진실을 아는 사람 저장
    for(int i = 0; i < know_amt; i++) {
        int tmp;
        cin >> tmp;

        is_know[tmp] = true;
    }

    // 전체 파티 상태 기록
    for(int i = 0; i < m; i++) {
        int amt;
        cin >> amt;

        vector <int> arr;
        
        for(int j = 0; j < amt; j++) {
            int tmp;
            cin >> tmp;
            arr.push_back(tmp);
        }

        party.push_back(arr);
    }

    // 파티의 수만큼 검사 반복
    for(int i = 0; i < m; i++) {
        // 전체 파티 검사
        for(int j = 0; j < m; j++) {
            // 이미 진실을 알고 있는 파티의 경우 스킵
            if(know_party[j]) continue;

            for(int k = 0; k < party[j].size(); k++) {
                // 파티에 아는 사람이 있는 경우
                if(is_know[party[j][k]]) {
                    // 해당 파티의 모든 사람을 진실을 아는 사람으로 변경
                    for(int x = 0; x < party[j].size(); x++) {
                        is_know[party[j][x]] = true;
                    }
                    // 해당 파티의 상태를 알고 있는 파티로 변경
                    know_party[j] = true;
                    break;
                }
            }
        }
    }

    int res = 0;
    for(int i = 0; i < m; i++) {
        // 진실을 모르는 파티 수 확인
        if(!know_party[i]) res++;
    }

    cout << res << "\n";
    return 0;
}