#include <iostream>

int arr[300000] = {-1, -1, };

int main() {
    int n;
    int tot = 0;
    while(1) {
        tot = 0;
        std::cin >> n;
        if(n == 0)
        break;
        for(int i = 1; i <= n; i++) {
            if(arr[i] == -1)
            continue;
            for(int j = 2; j * i <= 2 * n; j++) {
                arr[i * j] = -1;
            }
        }
        for(int i = n + 1; i <= 2 * n; i++) {
            if(arr[i] != -1) {
                // std::cout << "**" << " " << i << "\n";
                tot++;
            }
        }
        std::cout << tot << "\n";
    }
    return 0;
}