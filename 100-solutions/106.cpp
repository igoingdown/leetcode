//
//  main.cpp
//  106
//
//  Created by 赵明星 on 2017/2/11.
//  Copyright © 2017年 赵明星. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> inorder = {4, 2, 5, 1, 3};
    vector<int> postorder = {4, 5, 2, 3, 1};
    TreeNode * r = buildTree(inorder, postorder);
    cout << r->val << endl;
    cout << r->left->val << endl;
    cout << r->right->val << endl;
    cout << r->left->left->val << endl;
    cout << r->left->right->val << endl;
    std::cout << "Hello, World!\n";
    return 0;
}


TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.size() == 0) {
        return NULL;
    }
    
    TreeNode * root = new TreeNode(postorder.back());
    if (inorder.size() == 1) {
        return root;
    }
    
    TreeNode * p;
    stack<TreeNode *> s;
    s.push(root);
    postorder.pop_back();
    
    while (1) {
        if (inorder.back() == s.top()->val) {
            p = s.top();
            s.pop();
            inorder.pop_back();
            
            if (inorder.size() == 0) {
                break;
            }
            
            if (s.size() && inorder.back() == s.top()->val) {
                continue;
            }
            
            p->left = new TreeNode(postorder.back());
            postorder.pop_back();
            s.push(p->left);
        } else {
            p = new TreeNode(postorder.back());
            postorder.pop_back();
            s.top()->right = p;
            s.push(p);
        }
    }
    return root;
}































