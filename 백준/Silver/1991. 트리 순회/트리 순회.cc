#include <bits/stdc++.h>
using namespace std;

vector <tuple<char, char, char>> tree(30, {'.', '.', '.'}); // node, left_child, right_child
int n;

void preorder(int index) {
    if(get<0>(tree[index]) == '.') return;
    cout << get<0>(tree[index]);
    if(get<1>(tree[index]) != '.') {
        preorder(get<1>(tree[index]) - 'A');
    }
    if(get<2>(tree[index]) != '.') {
        preorder(get<2>(tree[index]) - 'A');
    }
}

void inorder(int index) {
    if(get<1>(tree[index]) != '.') {
        inorder(get<1>(tree[index]) - 'A');
    }
    if(get<0>(tree[index]) == '.') return;
    cout << get<0>(tree[index]);
    if(get<2>(tree[index]) != '.') {
        inorder(get<2>(tree[index]) - 'A');
    }
}

void postorder(int index) {
    if(get<1>(tree[index]) != '.') {
        postorder(get<1>(tree[index]) - 'A');
    }
    if(get<2>(tree[index]) != '.') {
        postorder(get<2>(tree[index]) - 'A');
    }
    if(get<0>(tree[index]) == '.') return;
    cout << get<0>(tree[index]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < 26; i++) {
        tree[i] = {i + 'A', '.', '.'};
    }

    for(int i = 0; i < n; i++) {
        char x, y, z;
        cin >> x >> y >> z;

        tree[x - 'A'] = {x, y, z};
    }

    

    preorder(0);
    cout << "\n";
    inorder(0);
    cout << "\n";
    postorder(0);
    cout << "\n";

    return 0;
}