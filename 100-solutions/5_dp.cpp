class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), start = 0, end = 0;
        if (n < 2) return s;  // 处理边界情况：空串或单字符
        
        // dp[i][j] 表示子串 s[i..j] 是否为回文串
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        // 初始化：单个字符都是回文串
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        
        // 按字串长度填充dp数组
        // j是右边界，i是左边界
        for (int j = 1; j < n; j++) {
            for (int i = 0; i < j; i++) {
                // 核心递推公式：
                // s[i] == s[j]：首尾字符相同
                // i + 1 > j - 1：处理长度为2的情况
                // dp[i + 1][j - 1]：内部子串是否为回文
                dp[i][j] = s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1]);
                
                // 更新最长回文串的位置
                if (dp[i][j] && j - i > end - start) {
                    start = i;
                    end = j;
                }
            }
        }
        
        // 返回最长回文子串
        return s.substr(start, end - start + 1);
    }
};