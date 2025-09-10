class Solution {
public:
    int word2Int(string& word) {
        int res = 0;
        for (char c: word) {
            res |= (1 << (c - 'a'));
        }
        return res;
    }
    int maxProduct(vector<string>& words) {
        vector<int> nums(words.size());
        for (int i = 0; i < words.size(); i++) {
            nums[i] = word2Int(words[i]);
        }
        int res = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if ((nums[i] & nums[j]) == 0) {
                    res = max(res, int(words[i].size()) * int(words[j].size()));
                }
            }
        }
        return res;
    }
};
