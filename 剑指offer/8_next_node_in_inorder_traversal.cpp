#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left, *right, *parent;
	TreeNode(int x):val(x), left(NULL),right(NULL), parent(NULL){}
};

TreeNode * next_node(TreeNode *target);

int main() {
	TreeNode *root = new TreeNode(0);
	root->left = new TreeNode(1);
	root->left->parent = root;
	root->right = new TreeNode(2);
	root->right->parent = root;
	root->right->left = new TreeNode(4);
	root->right->left->parent = root->right;
	root->right->left->left = new TreeNode(5);
	root->right->left->left->parent = root->right->left;
	auto tmp = next_node(root->right);
	if (tmp) cout << tmp->val << endl;
	else cout << "NULL" << endl;
	return 0;
}

TreeNode * next_node(TreeNode *target) {
	if (!target) return target;
	if (!target->right) {
		if (target->parent && target->parent->left == target) return target->parent;
		else {
			auto tmp = target->parent;
			while (tmp && tmp->parent && tmp->parent->right == tmp) tmp = tmp->parent; 
			// 没有右子，向上找到第一个节点非父节点的右子的节点，返回该节点的父节点
			return tmp ? tmp->parent : tmp;
		}

	} else {
		auto tmp = target->right;
		while (tmp->left) tmp = tmp->left;
		return tmp; 
	}

}