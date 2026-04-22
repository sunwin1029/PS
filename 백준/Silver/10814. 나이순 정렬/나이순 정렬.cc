#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class member {
    public:
        int age;
        string name;
};

bool compare(member a, member b) {
    return a.age < b.age;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    member arr[100001];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i].age >> arr[i].name;

    stable_sort(arr, arr + n, compare);

    for(int i = 0; i < n; i++) cout << arr[i].age << " " << arr[i].name << "\n";
    return 0;
}