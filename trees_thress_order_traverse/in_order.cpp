#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};


void InOrder_recursion(TreeNode* root, vector<int>& res);
void InOrder_no_recursion(TreeNode* root, vector<int>& res);

int main(int argc, char const *argv[])
{
	/* code */
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->right->right = new TreeNode(5);
	std::vector<int> v;
	// InOrder_recursion(root, v);
	InOrder_no_recursion(root, v);
	for (auto n : v) {
		cout << n << " ";
	}
	cout << endl;
	return 0;
}


void InOrder_recursion(TreeNode* root, vector<int>& res) {
	if (!root) {
		return;
	}
	InOrder_recursion(root->left, res);
	res.push_back(root->val);
	InOrder_recursion(root->right, res);
}



void InOrder_no_recursion(TreeNode* root, vector<int>& res) {
	stack<TreeNode*> s;
	while (root || !s.empty()) {
		while (root) {
			s.push(root);
			root = root->left;
		}
		root = s.top();
		s.pop();
		res.push_back(root->val);
		root = root->right;
	}
}