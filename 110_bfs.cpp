/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        
    if(!root)
        return true;
    else if(abs(get_depth(root->left) - get_depth(root->right)) < 2)
        return isBalanced(root->left) && isBalanced(root->right);
    else
        return false;
        
    }
    
    
    
    int get_depth(TreeNode * n)
    {
    if(!n)
        return 0;

    int d = 0;
    queue<TreeNode *> q;
    q.push(n);
    int layer_size = q.size();

    while(! q.empty())
    {
        TreeNode * temp = q.front();
        q.pop();
        -- layer_size;

        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);

        if(!layer_size)
        {
            layer_size = q.size();
            ++ d;
        }
    }

    return d;
    }
    
};