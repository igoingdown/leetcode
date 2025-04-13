#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;





class TrieNode {
public:
    TrieNode * children[2];
    TrieNode() : children{nullptr,nullptr} {}
    
};
void insert(TrieNode *root, int num) {
    for (int i = 30; i >= 0; i--) {
        int bit = ((num >> i) & 1);
        if (!root->children[bit]) {
            root->children[bit] = new(TrieNode);
        }
        root = root->children[bit];
    }
}

int search(TrieNode *root, int num) {
    int res = 0;
    for (int i = 30; i >= 0; i--) {
        int bit = ((num >> i) & 1);
        if (root -> children[1-bit]) {
            root = root -> children[1-bit];
            res |= (1 << i);
        } else {
            root = root -> children[bit];
        }
    }
    return res;
}


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        TrieNode *root = new(TrieNode);
        for (auto num : nums) {
            insert(root, num);
            res = max(res, search(root, num));
        }
        return res;
    }
};




int main() {
    vector<int> nums = {3,10,5,25,2,8};
    int target = 9;
    Solution sol;
    int result = sol.findMaximumXOR(nums);
    cout << result << endl;
    return 0;
}