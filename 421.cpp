class Solution {
    class TreeNode {
public:
    TreeNode* children[2];
    TreeNode() {
        children[0] = nullptr;
        children[1] = nullptr;
    }
};
class Trie {
public:
    TreeNode *root;
    Trie() {
        root = new TreeNode();
    }
    void insert(int n) {
        TreeNode *node = root;
        for (int i = 31; i >= 0; --i) {
            int bitNum = (n >> i) & 1;
            if (!node->children[bitNum]) {
                node -> children[bitNum] = new TreeNode();
            }
            node = node -> children[bitNum];
        }
    }

    int findMaxXor(int n) {
        int res = 0;
        TreeNode *node = root;
        for (int i = 31; i >= 0; --i) {
            int bitNum = (n >> i) & 1;
            if (node->children[1-bitNum]) {
                res |= (1 << i);
                node = node -> children[1-bitNum];
            } else {
                node = node -> children[bitNum];
            }
        }
        return res;
    }

};


public:
    int findMaximumXOR(vector<int>& nums) {
        Trie *t = new Trie();
        for (int num : nums) {
            t->insert(num);
        }
        int res = 0;
        for (int num : nums) {
            res = max(res, t->findMaxXor(num));
        }
        return res;
    }
};
