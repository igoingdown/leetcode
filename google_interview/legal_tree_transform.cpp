bool checkLeagal(TreeNode* a, TreeNode *b) {
	if (a && b) {
		return a->val == b->val && ((checkLeagal(a->left, b->left) && checkLeagal(a->right, b->right) || (checkLeagal(a->left, b->right) && checkLeagal(a->right, b->left))));
}
if (!a && !b) return true;
if (!a || !b) return false;
}

bool isSame(TreeNode *a, TreeNode *b) {
	if (!a && !b) return true;
	if (!a || !b) return false;
	return isSame(a->left, b->left) && isSame(a->right, b->right);
}


void change(TreeNode *root) {
	if (!root) return;
	if (!root->left && !root->right) return;
	if (!root->left) change(root->left);
	if (!root->right) change(root->right);
	if (compare(root->left, root->right) < 0) swap(root->left, root->right);
}

int compare(TreeNode *a, TreeNode *b) {
	// 0 =  1 >  -1 < change < 
	if (!a && !b) return 0;
	if (!a) return -1;
	if (!b) return 1;
	if (a->val > b->val) return 1;
	if (a->val < b->val) return -1;
	int res = compare(a->left, b->left);
	if (res != 0) return res;
	return compare(a->right, b->right);
}
