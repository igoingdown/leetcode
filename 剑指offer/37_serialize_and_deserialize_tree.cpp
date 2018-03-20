#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};


string serialize_tree(TreeNode *root);
TreeNode* deserialize(string &s);
TreeNode* deserialize(istringstream &in);
void serialize_tree(TreeNode *root, ostringstream &out);
void print_tree(TreeNode *root);

int main() {
	TreeNode *root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(4);
	root->right->left = new TreeNode(3);
	string s = serialize_tree(root);
	cout << s << endl;
	TreeNode *r = deserialize(s);
	cout << endl;
	print_tree(r);
	cout << endl;

	return 0;
}

void print_tree(TreeNode *root) {
	if (!root) {
		cout << "$ "; return;
	}
	cout << root->val << " ";
	print_tree(root->left);
	print_tree(root->right);
}

string serialize_tree(TreeNode* root) {
	ostringstream out;
	serialize_tree(root, out);
	return out.str();
}


void serialize_tree(TreeNode *root, ostringstream &out) {
	if (!root) out << "$ "; 
	else {
		out << root->val << " ";
		serialize_tree(root->left, out);
		serialize_tree(root->right, out);
	}
}

TreeNode* deserialize(string &s) {
	istringstream in(s);
	return deserialize(in);
}

TreeNode * deserialize(istringstream &in) {
	string val; in >> val;
	if (val != "$") {
		TreeNode *root = new TreeNode(stoi(val));
		root->left = deserialize(in);
		root->right = deserialize(in);
		return root;
	}
	return NULL;
}

