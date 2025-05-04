#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class TrieNode {
public:
    TrieNode* children[2];
    TrieNode() : children{nullptr, nullptr} {}
};

class Trie {
public:
    TrieNode* root;
    Trie() : root(new TrieNode()) {}

    void insert(int num) {
        TrieNode* node = root;
        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->children[bit]) {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
        }
    }

    int search(int num) {
        TrieNode* node = root;
        int res = 0;
        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->children[1 - bit]) {
                res |= (1 << i);
                node = node->children[1 - bit];
            } else {
                node = node->children[bit];
            }
        }
        return res;
    }

    ~Trie() {
        deleteTrie(root);
    }

private:
    void deleteTrie(TrieNode* node) {
        if (!node) return;
        deleteTrie(node->children[0]);
        deleteTrie(node->children[1]);
        delete node;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        Trie trie;
        for (int num : nums) {
            trie.insert(num);
            res = max(res, trie.search(num));
        }
        return res;
    }
};

int main() {
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    Solution sol;
    cout << sol.findMaximumXOR(nums) << endl;
    return 0;
}