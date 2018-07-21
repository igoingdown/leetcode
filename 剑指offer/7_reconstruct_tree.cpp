#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};


TreeNode * reconstruct_tree_by_pre_and_in_order_traversal_res(const vector<int> &pre, const vector<int> &in);
TreeNode * pre_and_in(const vector<int> &pre, const vector<int> &in, int p_start, int p_end, int i_start, int i_end);
void preTraversal(TreeNode *root, vector<int> &res);
void inTraversal(TreeNode *root, vector<int> &res);
void postTraversal(TreeNode *root, vector<int> &res);

int main() {
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left-> right = new TreeNode(4);
	root->left->right->left = new TreeNode(5);
	vector<int> pre, in, post;
	preTraversal(root, pre);
	for (int n : pre) cout << n << "\t";
	cout << endl;
	inTraversal(root, in);
	for (int n : in) cout << n << "\t";
	cout << endl;
	TreeNode *reconstructed_root = reconstruct_tree_by_pre_and_in_order_traversal_res(pre, in);
	vector<int> pre_res, in_res;
	preTraversal(reconstructed_root, pre_res);
	inTraversal(reconstructed_root, in_res);
	for (int n : pre_res) cout << n << "\t";
	cout << endl;
	for (int n : in_res) cout << n  << "\t";
	cout << endl;

	return 0;
}

void preTraversal(TreeNode *root, vector<int> &res) {
	if (!root) return;
	res.push_back(root->val);
	preTraversal(root->left, res);
	preTraversal(root->right, res);
}

void inTraversal(TreeNode *root, vector<int> &res) {
	if (!root) return;
	inTraversal(root->left, res);
	res.push_back(root->val);
	inTraversal(root->right, res);
}

void postTraversal(TreeNode *root, vector<int> &res) {
	if (!root) return;
	postTraversal(root->left, res);
	postTraversal(root->right, res);
	res.push_back(root->val);
}

TreeNode * reconstruct_tree_by_pre_and_in_order_traversal_res(const vector<int> &pre, const vector<int> &in) {
	int n = pre.size();
	if (n == 0) return NULL;
	return pre_and_in(pre, in, 0, n - 1, 0, n - 1);
}

TreeNode * pre_and_in(const vector<int> &pre, const vector<int> &in, int p_start, int p_end, int i_start, int i_end) {
	if (i_start > i_end || p_start > p_end) return NULL;
	TreeNode *root = new TreeNode(pre[p_start]);
	int root_index = i_start;
	while (in[root_index] != pre[p_start]) root_index++;
	root->left = pre_and_in(pre, in, p_start + 1, p_start + root_index - i_start, i_start, root_index - 1);
	root->right = pre_and_in(pre, in, p_start + root_index - i_start + 1, p_end, root_index + 1, i_end);
	return root;
}