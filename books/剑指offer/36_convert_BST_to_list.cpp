#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x):val(x), left(NULL),right(NULL){}
};


TreeNode *convertRecusively(TreeNode *root);

int main() {
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(17);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(14);
    root->right->left->right = new TreeNode(15);
    auto head = convertRecusively(root);
    auto tmp = head;
    do {
        cout << tmp->val << endl;
        tmp = tmp->right;
    } while (tmp != head);

    return 0;
}

TreeNode *convertRecusively(TreeNode *root) {
    if (!root) return NULL;
    auto left = convertRecusively(root->left);
    auto right = convertRecusively(root->right);
    root->right = root; root->left = root;
    if (right) {
        root->right = right;
        right->left->right = root;
        root->left = right->left;
        right->left = root;
    }
    if (left) {
        left->left->right = root;
        root->left->right = left;
        auto tmp = left->left;
        left->left = root->left;
        root->left = tmp;
    }
    
    return left ? left : root;
}




