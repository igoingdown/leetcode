class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        
        // dp[i][j] 表示将 word1 的前 i 个字符转换为 word2 的前 j 个字符所需的最少操作数
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
        
        // 初始化：空串转换到另一个字符串需要的操作数
        // dp[0][j] 表示空串转换到 word2 前 j 个字符需要 j 次插入
        for (int j = 1; j <= n2; j++) 
            dp[0][j] = j;
            
        // dp[i][0] 表示 word1 前 i 个字符转换到空串需要 i 次删除
        for (int i = 1; i <= n1; i++) 
            dp[i][0] = i;
        
        // 填充 dp 数组
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (word1[i-1] == word2[j-1]) {
                    // 如果当前字符相同，可以选择：
                    // 1. 使用这个字符（替换）：dp[i-1][j-1]
                    // 2. 不使用这个字符：
                    //    - 删除 word1[i-1]，上一步已完成变换，删除即可：dp[i-1][j] + 1
                    //    - 删除 word2[j-1]（相当于在word1插入）：dp[i][j-1] + 1
                    dp[i][j] = min(dp[i-1][j-1], 
                                 1 + min(dp[i][j-1], dp[i-1][j]));
                } else {
                    // 如果当前字符不同，可以：
                    // 1. 替换：dp[i-1][j-1] + 1
                    // 2. 删除 word1[i-1]：dp[i-1][j] + 1
                    // 3. 插入 word2[j-1]：dp[i][j-1] + 1
                    dp[i][j] = 1 + min(dp[i-1][j-1], 
                                     min(dp[i][j-1], dp[i-1][j]));
                }
            }
        }
        
        // 返回将整个 word1 转换为 word2 所需的最少操作数
        return dp[n1][n2];
    }
};