#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    char label;
    TreeNode* left;
    TreeNode* right;
};

void printPreOrder(TreeNode* node) {
    if(node == nullptr) return;

    printf("%c", node->label);
    printPreOrder(node->left);
    printPreOrder(node->right);
}


void printInOrder(TreeNode* node) {
    if(node == nullptr) return;

    printInOrder(node->left);
    printf("%c", node->label);
    printInOrder(node->right);
}

void printPostOrder(TreeNode* node) {
    if(node == nullptr) return;

    printPostOrder(node->left);
    printPostOrder(node->right);
    printf("%c", node->label);
}

int main() {
    int N;
    char a, b, c;
    cin >> N;

    TreeNode* root = new TreeNode();
    root->label = 'A';
    TreeNode* node;

    queue<TreeNode*> q;
    q.push(root);

    for(int i = 0; i < N; i++) {
        cin >> a >> b >> c;

        int qSize = q.size();
        for(int i = 0; i < qSize; i++) {
            if(q.front()->label == a) {
                node = q.front();
                q.pop();
                break;
            } else {
                q.push(q.front());
                q.pop();
            }
        }

        if(b != '.') {
            node->left = new TreeNode();
            node->left->label = b;
            q.push(node->left);
        } else {
            node->left = nullptr;
        }
        
        if(c != '.') {
            node->right = new TreeNode();
            node->right->label = c;
            q.push(node->right);
        } else {
            node->right = nullptr;
        }
    }
    
    printPreOrder(root);
    cout << '\n';
    printInOrder(root);
    cout << '\n';
    printPostOrder(root);
    
    return 0;
}