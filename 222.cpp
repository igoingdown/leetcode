#include <iostream>
#include <vector>
#include <bitset>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int countNodes(TreeNode* root);


int main(int argc, char const *argv[])
{
    /* code */
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout << countNodes(root) << endl;
    return 0;
}



int countNodes(TreeNode* root) {
    if (!root) {
        return 0;
    }
    TreeNode* tmp = root;
    int l = 0;
    while (tmp) {
        l++;
        tmp = tmp->left;
    }
    cout << l << endl;
    int low = 1 << (l - 1), high = (1 << l) - 1;
    int mid = 0;
    while (low < high) {
        cout << low << "\t" << high << endl;
        mid = low + ((high - low + 1) >> 1);
        int i = mid;
        vector<int> v;
        while (i) {
            // cout << i % 2;
            v.push_back(i % 2);
            i /= 2;
        }
        v.pop_back();
        // cout << endl;
        auto iter = v.rbegin();
        tmp = root;
        while (iter != v.rend() && tmp) {
            if (*iter == 0) {
                tmp = tmp->left;
            } else {
                tmp = tmp->right;
            }
            iter++;
        }
        if (!tmp) {
            high = mid - 1;
        } else {
            low = mid;
        }
        // cout << endl;

    }
    return low;
}







