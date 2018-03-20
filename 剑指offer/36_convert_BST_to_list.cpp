#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x):val(x), left(NULL),right(NULL){}
};


TreeNode *convert(TreeNode *root);
void convert_node(TreeNode *root, TreeNode **last);
void convert_node(TreeNode *root, TreeNode *last);

int main() {
	TreeNode *root = new TreeNode(10);
	root->left = new TreeNode(5);
	root->right = new TreeNode(17);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(7);
	root->right->left = new TreeNode(14);
	root->right->left->left = new TreeNode(12);
	TreeNode *head = convert(root);
	cout << endl;
	while (head) {
		cout << head->val << endl;
		head = head->right;
	}
	return 0;
}

TreeNode *convert(TreeNode *root) {
	TreeNode *last = NULL;
	convert_node(root, &last);
	TreeNode *head = last;
	while (head && head->left) head = head->left;
	return head;
}

void convert_node(TreeNode *root, TreeNode **last) {
	if (!root) return;
	convert_node(root->left, last);
	root->left = *last;
	if (*last) (*last)->right = root;
	*last = root;
	convert_node(root->right, last);
}

// last必须为二重指针！！！这里是为了测试.
void convert_node(TreeNode *root, TreeNode *last) {
	if (!root) return;
	convert_node(root->left, last);
	root->left = last;
	if (last) last->right = root;
	convert_node(root->right, root);
	TreeNode *tmp = root;
}


