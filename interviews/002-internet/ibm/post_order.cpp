#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int x):val(x), left(NULL), right(NULL){}
};

struct SNode
{
	bool visited;
	TreeNode *node;
	SNode(TreeNode *root):node(root), visited(false) {}
};

void post_order(TreeNode *root);

int main() {
	TreeNode *root = new TreeNode(0);
	root->left = new TreeNode(1);
	root->right = new TreeNode(2);
	root->left->left = new TreeNode(3);
	post_order(root);
	return 0;
}



void post_order(TreeNode *root) {
	if (!root) return;
	stack<SNode*> s;
	while (root) {
		s.push(new SNode(root));
		root = root->left;
	}
	while (!s.empty()) {
		auto cur = s.top();
		if (cur->visited || !cur->node->right) {
			s.pop();
			cout << cur->node->val << endl;
		} else {
			cur->visited = true;
			auto tmp = cur->node->right;
			while (tmp) {
				s.push(new SNode(tmp));
				tmp = tmp->left;
			}
		}
	}
}
