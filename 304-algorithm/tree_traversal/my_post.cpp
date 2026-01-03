#include <iostream>
#include <vector>
#include<stack>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0),left(NULL),right(NULL){}
    TreeNode(int i):val(i),left(NULL),right(NULL){}
    TreeNode(int i,TreeNode *l, TreeNode *r):val(i),left(l),right(r){}
};



struct Node{
    TreeNode *node;
    bool rightVisited;
    Node():node(NULL),rightVisited(false){}
    Node(TreeNode *n):node(n),rightVisited(false){}
    Node(TreeNode *n, bool v):node(n),rightVisited(v){}
};


vector<int> traverse(TreeNode *root) {
    vector<int> result;
    if (root == NULL) {
        return result;
    }
    stack<Node*> s;
    s.push(new Node(root));
    while (!s.empty()) {
        cout << "xxx" << s.top()->node->val << endl;
        while (!(s.top()->rightVisited) && (s.top()->node->left)) {
            s.push(new Node(s.top()->node->left));
        }

        if (s.top()->node->right == NULL || s.top()->rightVisited) {
        cout << "yyy" << s.top()->node->val << endl;
            result.push_back(s.top()->node->val);
            s.pop();
        }

            if (!(s.top()->rightVisited) &&  s.top()->node->right) {
                s.top()->rightVisited = true; 
                s.push(new Node(s.top()->node->right));
            }
    }
    return result;
}


int main() {
    TreeNode *root = new TreeNode(1);
    root->right= new TreeNode(2);
    root->right->left= new TreeNode(3);
    for (auto i : traverse(root)) {
        cout << i << endl;
    }
    return 0;
}
