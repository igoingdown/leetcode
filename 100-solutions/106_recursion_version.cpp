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
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder);
TreeNode* buildTree(vector<int>& inorder, int in_start, int in_end, vector<int>& postorder, int post_start, int post_end, map<int, int> & v2i);

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
    if (inorder.size() == 0) return NULL;
    if (inorder.size() == 1) return new TreeNode(inorder.back());
    map<int, int> value2index;
    for (int i = 0; i < inorder.size(); i++) value2index[inorder[i]] = i;
    return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, value2index);
}


TreeNode* buildTree(vector<int>& inorder, int in_start, int in_end, vector<int>& postorder, int post_start, int post_end, map<int, int> & v2i) {
    if (in_start > in_end || post_start > post_end) return NULL;
    TreeNode * root = new TreeNode(postorder[post_end]);
    int root_index = v2i[root->val];
    root->left = buildTree(inorder, in_start, root_index - 1, postorder, post_start, post_start + root_index - in_start - 1, v2i);
    root->right = buildTree(inorder, root_index + 1, in_end, postorder, post_start + root_index - in_start, post_end - 1, v2i);
    return root;
}




























