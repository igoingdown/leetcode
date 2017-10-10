/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private: 
    stack<TreeNode*> s;
public:
    BSTIterator(TreeNode *root) {
        if (root) {
            s.push(root);
            while (root->left) {
                s.push(root->left);
                root = root->left;
            }
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        int res = s.top()->val;
        auto node = s.top();
        s.pop();
        if (node->right) {
            s.push(node->right);
            while (s.top()->left) {
                s.push(s.top()->left);
            }
        }
        return res;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */