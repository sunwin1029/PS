#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    class Node* left_child;
    class Node* right_child;
    int current_node;
};


void make_tree(Node* ptr, int tmp) {
    if(ptr->current_node > tmp) {
        if(ptr->left_child == NULL) {
            Node* node = new Node;
            node->current_node = tmp;
            ptr->left_child = node;
        }
        else {
            make_tree(ptr->left_child, tmp);
        }
    }
    else {
        if(ptr->right_child == NULL) {
            Node* node = new Node;
            node->current_node = tmp;
            ptr->right_child = node;
        }
        else {
            make_tree(ptr->right_child, tmp);
        }
    }
}


void print_post_fix(Node* ptr) {
    if(ptr->left_child != NULL) {
        print_post_fix(ptr->left_child);
    }
    if(ptr->right_child != NULL) {
        print_post_fix(ptr->right_child);
    }
    cout << ptr->current_node << "\n";
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);    

    int n;
    Node* root = new Node;

    cin >> n;
    root->current_node = n;
    
    while(cin >> n) {
        make_tree(root, n);
    }

    print_post_fix(root);

    return 0;
}