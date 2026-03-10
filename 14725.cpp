#include <bits/stdc++.h>
using namespace std;

struct Node {
    string name; 
    vector <Node *> child;
    // Node* child[1000];
    unordered_map<string, int> m;
    int child_num;
    int level;

    Node(string n, int l) {
        name = n;
        child_num = 0;
        level = l;
    }
};

bool Compare(Node *a, Node *b) {
    return a->name < b->name;
}

void print(Node* start) {
    sort(start->child.begin(), start->child.end(), Compare);

    for(int i = 0; i < start->level - 1; i++) {
        cout << "--";
    }
    if(start->level != 0)
        cout << start->name << "\n";

    for(int i = 0; i < start->child_num; i++) {
        print(start->child[i]);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    Node* root = new Node("root", 0);

    for(int i = 0; i < n; i++) {
        int k;
        Node* ptr = root;
        cin >> k;

        for(int j = 0; j < k; j++) {
            string s;
            cin >> s;

            if(ptr->m.count(s)) {
                int index = ptr->m[s];
                ptr = ptr->child[index];
                continue;
            }
            else {
                Node* new_node = new Node(s, ptr->level + 1);
                ptr->m[s] = ptr->child_num;
                ptr->child.push_back(new_node);
                ptr->child_num++;
                ptr = new_node;
            }
        }
    }

    print(root);

    return 0;
}