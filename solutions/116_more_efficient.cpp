#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect_next(TreeLinkNode *root);
void layer_traversal(TreeLinkNode *root);

int main() {
    TreeLinkNode *root = new TreeLinkNode(0);
    root->left = new TreeLinkNode(1);
    root->right = new TreeLinkNode(2);
    root->left->right = new TreeLinkNode(3);
    root->right->right = new TreeLinkNode(4);
    connect_next(root);
    layer_traversal(root);
    return 0;
}

void layer_traversal(TreeLinkNode *root) {
    if (!root)
        return;
    queue<TreeLinkNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeLinkNode *cur = q.front();
        q.pop();
        cout << cur->val << " " << (cur->next ? to_string(cur->next->val) : "NULL") << endl;
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
}

void connect_next(TreeLinkNode *root) {
    TreeLinkNode *start = root, *next_start = NULL, *next_end = NULL;
    while (start) {
        while (start) {
            if (start->left) {
                if (next_start) {
                    next_end->next = start->left;
                    next_end = next_end->next;
                } else {
                    next_start = start->left;
                    next_end = next_start;
                }
            }
            if (start->right) {
                if (next_start) {
                    next_end->next = start->right;
                    next_end = next_end->next;
                } else {
                    next_start = start->right;
                    next_end = next_start;
                }
            }
            start = start->next;
        }
        swap(start, next_start);
        next_end = NULL;
    }
}

