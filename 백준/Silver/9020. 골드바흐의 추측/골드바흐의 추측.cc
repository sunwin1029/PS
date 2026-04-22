#include <iostream>

int arr[10010] = {-1, -1, };

int main() {
    int n;
    int t;
    int tot = 0;
    
    std::cin >> t;
    for(int i = 2; i <= 5000; i++) {
        if(arr[i] == -1)
        continue;
        for(int j = 2; j * i <= 10000; j++)
        arr[j * i] = -1;
    }
    for(int i = 0; i < t; i++) {
        std::cin >> n;
        for(int i = n / 2; i <= n; i++) {
            if(arr[i] == -1)
            continue;
            else {
                if(arr[n - i] != -1) {
                    std::cout << n - i << " " << i << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}