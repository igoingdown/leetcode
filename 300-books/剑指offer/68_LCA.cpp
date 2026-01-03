#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};


TreeNode * lca(TreeNode *root, TreeNode *p, TreeNode *q);
int helper(TreeNode *root, TreeNode *p, TreeNode *q, TreeNode *&res);

int main() {
    TreeNode *root = new TreeNode(37);
    root->left = new TreeNode(-34);
    root->right = new TreeNode(-48);
    root->left->right = new TreeNode(-100);
    root->right->left = new TreeNode(-100);
    root->right->right = new TreeNode(48);
    root->right->right->left = new TreeNode(-54);
    root->right->right->left->left = new TreeNode(-71);
    root->right->right->left->right = new TreeNode(-22);
    root->right->right->left->right->right = new TreeNode(8);
    TreeNode *p = lca(root, root->right->right->left->left, root->right->right);
    if (p) cout << p->val << endl;
    else cout << "NULL" << endl;
    return 0;
}

TreeNode * lca(TreeNode *root, TreeNode *p, TreeNode *q) {
    TreeNode *res = NULL;
    helper(root, p, q, res);
    return res;
}

// 同时在一棵二叉树中查找p和q两个节点，如果只找到了p节点则返回1，如果只找到了q节点，则返回2，如果同时找到p和q节点，则返回3，其余情况返回0，那么根据返回值就可以判断是否是公共祖先
int helper(TreeNode *root, TreeNode *p, TreeNode *q, TreeNode *&res) {
    if (!root || res) return 0;
    int l = helper(root->left, p, q, res);
    if (l == 3) return 3;  // 左子树同时找到p和q
    int r = helper(root->right, p, q, res);
    if (r == 3) return 3;  // 右子树同时找到p和q
    if ((l == 1 && r == 2) || (l == 2 && r == 1)) {
        // 左子树和右子树分别找到p和q，则当前节点为最近公共祖先
        res = root; return 3;
    } else if ((root == p && (l == 2 || r == 2)) || (root == q && (l == 1 || r == 1))) {
        // 当前节点为p,且左子树或者右子树找到q。或者当前节点为q,且左子树或者右子树找到p
        res = root; return 3;
    } else if (root == p || l == 1 || r == 1) return 1;
    else if (root == q || l == 2 || r == 2) return 2;
    else return 0;
}

