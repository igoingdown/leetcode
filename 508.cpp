#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        unordered_map<int, int> m;
        int maxCount = 0;
        helper(root, m, maxCount);
        for(auto i = m.begin(); i != m.end(); i++) {
            if ((i->second) == maxCount) {
                res.push_back(i->first);
            }
        }
        return res;
    }
    int helper(TreeNode* r, unordered_map<int, int>& m, int& maxCount) {
        if (!r) {
            return 0;
        }
        int sum = r->val;
        sum += helper(r->left, m, maxCount);
        sum += helper(r->right, m, maxCount);
        m[sum]++;
        maxCount = max(maxCount, m[sum]);
        return sum;
    }
};
