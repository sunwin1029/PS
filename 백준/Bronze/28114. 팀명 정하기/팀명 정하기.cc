#include <iostream>
#include <algorithm>

struct data{
    int p;
    int y;
    char s[4];
};

bool compare_p(struct data& a, struct data& b) {
    return a.p > b.p;
}
bool compare_y(struct data& a, struct data& b) {
    return a.y < b.y; 
}

int main() {
    
    struct data data[3];
    
    for(int i = 0; i < 3; i++) {
        std::cin >> data[i].p >> data[i].y >> data[i].s;
    }
    std::sort(data, data + 3, compare_y);
    
    for(int i = 0; i < 3; i++)
    std::cout << data[i].y % 2000;
    std::cout << "\n";
    
    std::sort(data, data + 3, compare_p);
    for(int i = 0; i < 3; i++)
    std::cout << data[i].s[0];
    

    return 0;
}