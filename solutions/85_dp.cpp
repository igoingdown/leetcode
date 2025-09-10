class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n, res = 0;
        if (m == 0) return 0;
        n = matrix[0].size();
        if (n == 0) return 0;
        vector<int> left(n, 0), right(n, n), height(n, 0);
        for (int i = 0; i < m; i++) {
            // 外层遍历每一行，内层遍历每一列，下一行只要需要使用上一行的信息，所以可以简化为一维DP
            // height,left和right更新的先后顺序无所谓。
            // 关键是理解left[j]和right[j]为什么可以表示最高的（高度为height[j]）的全1向量的左右边界
            // 原因是当matrix[i][j]为1时，left和right的更新会取当前行的边界cur和上一行的对应列的最小值(对right)或者最大值(left)
            for (int j = 0; j < n; j++) {  // 更新height，height[j]表示点(i,j)最高的全'1'向量高度
                if (matrix[i][j] == '0') height[j] = 0;
                else height[j] += 1;
            }
            for (int j = 0, cur = 0; j < n; j++) { //更新left,left[j]表示height[j]能向左延伸的最远边界index
                if (matrix[i][j] == '1') left[j] = max(left[j], cur);
                else {
                    left[j] = 0; cur = j + 1;
                }
            }
            for (int j = n - 1, cur = n; j >= 0; j--) { //更新right,right[j]表示height[j]能向右延伸的最远边界index，注意左闭右开
                if (matrix[i][j] == '1') right[j] = min(right[j], cur);
                else {
                    right[j] = n; cur = j;
                }
            }
            for (int j = 0; j < n; j++) res = max(res, (right[j] - left[j]) * height[j]);
        }
        return res;
    }
};