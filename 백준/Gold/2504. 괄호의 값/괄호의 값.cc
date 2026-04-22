#include <iostream>
#include <stack>
#include <string.h>
#include <cmath>
using namespace std;

int main() {
    char arr[50];
    cin >> arr;
    int len = strlen(arr);
    stack <int> s;
    int open_2 = 0; // '('
    int open_3 = 0; // '['
    bool valid = true;
    int tot = 0;
    
    for(int i = 0; i < len; i++) {
        if(arr[i] == 40) {
            s.push(2);
            open_2++;
        }
        else if(arr[i] == 41) {
            if(arr[i - 1] == 40) {
                open_2--;
                s.pop();
                tot += 2 * pow(2, open_2) * pow(3, open_3);
            } // 괄호가 바로 열리고 닫히는 경우
            else if(!s.empty() && s.top() == 2) {
                s.pop();
                open_2--;
            }
            else  {
                valid = false;
                break;
            }
        
        }
        else if(arr[i] == 91) {
            s.push(3);
            open_3++;
        }
        else if(arr[i] == 93) {
            if(arr[i - 1] == 91) {
                open_3--;
                s.pop();
                tot += 3 * pow(2, open_2) * pow(3, open_3);
            } // 괄호가 바로 열리고 닫히는 경우
            else if(!s.empty() && s.top() == 3) {
                s.pop();
                open_3--;
            }
            else  { 
                valid = false;
                break;
            }
        }
    }
    if(!s.empty())  valid = false;

    if(valid) cout << tot;
    else cout << "0";
    
    return 0;
}