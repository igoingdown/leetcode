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


vector<int> traverse(TreeNode *root) {
     vector<int> result;
      stack<TreeNode*> s;
      s.push(root);
      while (!s.empty()) {
  auto t= s.top();
  s.pop();
  if (!t) {
      continue;
  }
  result.push_back(t->val);
  if (t->right) {
  s.push(t->right);
  }

  if (t->left) {
              s.push(t->left);
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
