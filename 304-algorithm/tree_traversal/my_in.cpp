#include <iostream>
#include <vector>
#include <stack>

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


struct Node {
    TreeNode *node;
    bool leftvisited;
    Node():node(NULL),leftvisited(false){}
    Node(TreeNode* n):node(n),leftvisited(false){}
    Node(TreeNode* n, bool v):node(n),leftvisited(v){}
};

vector<int> traverse(TreeNode *root) {
    vector<int> result;
    if (!root) {
        return result;
    }
    stack<Node*> s;
    s.push(new Node(root));
    while (!s.empty()) {
        auto t= s.top();
        if (!t->node->left || t->leftvisited) {
            s.pop();
            result.push_back(t->node->val);
            if (t->node->right) {
                s.push(new Node(t->node->right));
            }
        }
        else if (t->node->left) {
            s.push(new Node(t->node->left));
            t->leftvisited = true;
        }
   }
   return result;
}


int main() {
    TreeNode *root = new TreeNode(2);
    root->left= new TreeNode(3);
    root->left->left= new TreeNode(1);
    for (auto i : traverse(root)) {
        cout << i << endl;
    }
    return 0;
}
