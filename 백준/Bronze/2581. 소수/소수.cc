#include <iostream>

int main() {
    int arr[30000] = {0, -1, };
    int m, n;
    int tot = 0;
    int check = 0;
    int min;
    std::cin >> m >> n;
    for(int i = 2; i <= n; i++) {
        if(arr[i] == -1)
        continue;
        for(int j = 2; j * i <= n; j++) {
            arr[j * i] = -1;
        }
    }
    for(int i = m; i <= n; i++) {
        if(arr[i] != -1) {
            if(check == 0) {
                check = 1;
                min = i;
            }
            tot += i;
        }
    }
    if(tot == 0) {
        std::cout << "-1";
        return 0;
        
    }
    std::cout << tot << "\n" << min;
    
    return 0;
}