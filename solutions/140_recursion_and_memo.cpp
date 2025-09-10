class Solution {
private: 
    unordered_map<string, vector<string>> mem;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (mem.find(s) != mem.end()) return mem[s];
        vector<string> res;
        if (find(wordDict.begin(), wordDict.end(), s) != wordDict.end()) res.push_back(s); // s本身就是dict中的一个元素
        for (int i = 1; i < s.size(); i++) {
            string word = s.substr(i);
            if (find(wordDict.begin(), wordDict.end(), word) != wordDict.end()) {
                // 尾部的word合法, 开始递归
                // f([0, j]) = f([0, i]) + word(i + 1, j) 
                // 递推表达式同139的DP方法.
                vector<string> pre = wordBreak(s.substr(0, i), wordDict);
                for (auto &s : pre) s += " " + word;
                res.insert(res.begin(), pre.begin(), pre.end());   // 将递归得到的结果添加到结果列表中
            }
        }
        mem[s] = res;
        return res;
    }
};