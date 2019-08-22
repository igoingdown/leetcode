#### DP专题

62: Unique Paths

<https://leetcode.com/problems/unique-paths/?tab=Description>

DP。二维DP递推表达式为$dp[i][j] = dp[i-1][j] + dp[i][j-1]$，可以简化为一维DP。

63: Unique Paths II

<https://leetcode.com/problems/unique-paths-ii/?tab=Description>

DP。同62。

64: Minimum Path Sum

<https://leetcode.com/problems/minimum-path-sum/?tab=Description>

DP。同62。

120: Triangle

<https://leetcode.com/problems/triangle/>

DP。自底向上，每个问题只有两个小的子问题，同62。
`dp[c] = min(dp[c], dp[c+1]) + triangle[r][c]`，$O(N^2)$。


152: Maximum Product Subarray

<https://leetcode.com/problems/maximum-product-subarray/>

DP。用`f_max[i],f_min[i]`分别记录以`nums[i]`结尾的sub-array的乘积最大值和最小值。
初始化`f_max[0] = nums[0]; f_min[0] = nums[0];`，然后遍历`i`$\in$`[1, nums.size()）`，
更新规则分别为`f_max[i] = max(nums[i], max(f_max[i - 1] * nums[i], f_min[i - 1] * nums[i]));`
和`f_min[i] = min(nums[i], min(f_max[i - 1] * nums[i], f_min[i - 1] * nums[i]));`。
对本题比较熟练的情况下，可以使用2个变量来代替1维DP。


53: Maximum Subarray

<https://leetcode.com/problems/maximum-subarray/?tab=Description>

DP，可以降为0维DP，即kadane算法。设有长度为$n$的数组$a$用`sum`和`res`分别记录当前的累加和与最终的结果。
从 ![](http://latex.codecogs.com/gif.latex?{a_1}) 开始累加，当加到$a_i$时候如果`sum < 0`，将`sum`清零，相当于把前面的一个连续子数组扔掉，如果`sum > 0`更新result。

这样做的原因是如果上述算法中出现$\sum_{k = i}^{j}a_k < 0$，
则必有$\sum_{k=i}^{j+\lambda}a_k < a_{j+\lambda}, \lambda \in [1, n-j]$ 因此可以将$a[i,j]$这部分直接扔掉，从`j+1`开始继续查找和最大的连续子数组。


363: Max Sum of Rectangle No Larger Than K

<https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/>

BS，DP：本题实际上是53题的升级版，BS的解法实际上糅合了kadane算法（即53题经典解法）和有界最大连续子数组。
首先通过遍历所有可能的矩形左右边的组合，然后用dp求和，因为多加一列的话可以应用之前几列的求和结果。
对于每行的和，应用最大kadane算法的思想可以得出和最大的矩形，而应用有界最大子数组算法可以求出有界情况下和最大的矩形。
时间复杂度：$O((col)^2row\log(row))，空间复杂度为O(row)。
暴力解法是遍历每个矩形可能的左右、上下边，利用dp计算累加和，时间复杂度O((row)^2(col)^2)，空间复杂度为O(row)。


72: Edit Distance

<https://leetcode.com/problems/edit-distance/description/>

DP。用二维数组记录$s[0,i]$与$p[0,j]$的距离。
* 初始化: `dp[0][j] = j`，`dp[i][0] = i`
* 二重循环递推: 
	* `s[i] == p[j]`：`dp[i][j] = min(dp[i-1][j-1], 1+dp[i-1][j], 1+dp[i][j-1])`，`min`函数中的三项分别表示在该处对进行**改、增、删**的操作。
	* `s[i] != p[j]`：`dp[i][j] = min(1+dp[i-1][j-1], 1+dp[i-1][j], 1+dp[i][j-1])`，`min`函数中的三项分别表示在该处对进行**改、增、删**的操作。
	
	上述两种情况的区别在于**改**操作导致的结果不同，相同的时候是不需要改的，所以少了`+1`。

486: Predict the Winner

<https://leetcode.com/problems/predict-the-winner/description/>

DP。二维DP比一维DP更易于理解。两个维度坐标含义相同，填表方式是先填长度比较小的范围，沿对角线填表。
`dp[i][j] = min(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1])`，每次都是1号玩家先取，
1号玩家取完之后2号玩家就成了“1”号玩家，但是对于1号玩家来说，2号玩家充当“1”号玩家时得到的分数实际上就是1号玩家失掉的分数。
当两者都是用最优的策略进行游戏时，一个玩家取了一个数之后，问题规模减1，而问题的结构是完全相同的，于是有了上式。

45: Jump Game II

<https://leetcode.com/problems/jump-game-ii/description/>

DP,BFS。

* DP： 复杂度为$O(N^2)$，自己写的DP，遍历nums，填充并修改dp，如果dp[i]都有效，遍历[1, nums[i]]，更新dp[i+j]，这种方式会超时。师姐的dp跟我不太一样，为了得到dp[i]，遍历dp[0, i-1]，如果一步可以到i则直接跳出，师姐的dp思路才是真正的dp思路。
* BFS：时间复杂度$O(N)$，从0开始，对于每层更新能到达的最远的元素，然后从那个元素开始，直到能够到最后一个元素位置。

55: Jump Game

<https://leetcode.com/problems/jump-game/?tab=Description>

同45。DP，BFS两种方法都可以，还有一种直接循环法，是BFS的简化版。
* 直接循环法：遍历数组中的每个元素$a_i$，不断更新能到达的最远处`max_reach`，遍历过程中还要保证$i\leq$`max_reach`。最后返回`i==a.size()`。

85: Maximal Rectangle

<https://leetcode.com/problems/maximal-rectangle/description/>

DP。把原来的1010矩阵变成直方图矩阵。外层遍历每一行，内层遍历每一列，下一行只要需要使用上一行的信息，所以可以简化为一维DP。height,left和right更新的先后顺序无所谓。关键是理解left[j]和right[j]为什么可以表示最高的（高度为height[j]）的全1向量的左右边界,原因是当matrix[i][j]为1时，left和right的更新会取当前行的边界cur和上一行的对应列的最小值(对right)或者最大值(left)。

837: New 21 Game

<https://leetcode.com/contest/weekly-contest-85/problems/new-21-game/>

DP。给定K,N,W，当牌的点数小于K时，从$[1, W]$的牌中等概论随机抽取一张，计算手牌的面值之和$<=N$的概率。使用pre记录当前牌面值总和之前的概率总，相当于前缀和，使用dp记录当前牌面值的概率。dp[i]最多只跟$[i - 1, i-1-W]$的牌面值概率的总和sum有关，$dp = sum / W$, 使用b记录相关牌面值的起点，使用e记录牌面值的终点。每次计算dp之后，$pre[i + 1] = pre[i] + dp[i]$。

730: Count Different Palindromic Subsequences

<https://leetcode.com/problems/count-different-palindromic-subsequences/description/>

DP。二维DP记录每个子串中不重复的回文子序列的个数，先固定长度，然后遍历起点。对于$DP[i][j]$，分两种情况:
1. $s[i] == s[j]$:假设$s[i+1:j-1]$的不重复的回文子序列为$\{y_1, y_2, ..., y_k\}$，$s[i]=s[j]=a$，不考虑具体的细节粗略估计应该有$DP[i][j]=DP[i+1][j-1] * 2 + 2$，这是因为$s[i:j]$的不重复回文子串粗略想想应该有$\{y_1, y_2, ..., y_n, ay_1a, ay_2a, ..., ay_na, a, aa\}$，下面考虑可能出现的重复，当$s[i:j]$的模式为`axxxaxxxaxxxa`时，就会出现重复，因此可以用TP的方法，分别从$s[i+1]$和$s[j-1]$向内查找$a$，设出现的位置分别为$l$和$r$。
 	* $l < r$：即$s[i:j]$的模式是`axxxaxxaxxxa`，因此重复的就是最里面的`xx`的非重复回文子序列个数，此时$DP[i][j] = DP[i+1][j-1]*2 - DP[l+1][r-1]$。
	* $l = r$：即$s[i:j]$的模式是`axxxaxxxa`，此时$DP[i][j] = DP[i + 1][j-1] * 2 + 1$
	* $l > r$: 即不存在重复，$s[i:j]$的模式是`axxxa`，此时$DP[i][j] = DP[i+1][j-1] * 2 + 2$。
2. $s[i] != s[j]$:$DP[i][j] = DP[i+1][j] + DP[i][j-1] - DP[i+1][j-1]$。

731: Rectangle Area II

<https://leetcode.com/contest/weekly-contest-88/problems/rectangle-area-ii/>

DP。计算二维坐标系内所有非旋转矩形（所有矩形的边均和X或Y轴平行）重叠的面积。基本思想是将所有矩形分成小块，所有部分都只计算一次。
  * 我自己的思路：使用priority_queue，将所有矩形按照$\{X_1, X_2, Y_1, Y_2\}$的优先级进行排序，每次取出前两个矩形，每次将重复的部分保留，计算多出的部分。我的思路有个bug，当多出的部分与后续的矩形有重复时，这个方法就有了重复计算。
  * **正确方法**：将所有出现过的X，Y分别提取出来。遍历每个矩形，找到其左下角和右上角两个坐标的位置$\{X_1, Y_1, X_2, Y_2\}$在X和Y中对应的index：$\{i_1, j_1, i_2, j_2\}$，遍历所有小矩形$\{x_1, y_1, x_2, y_2\}$，其中$i_1 <= x_1 < x_2 <= i_2, j_1 <= y_1 < y_2 <= j_2$。由于$x_1$和$x_2$必然在X中相邻，$y_1$和$y2$必然在Y中相邻，因此只需标记$\{x_1, y_1\}$即可，可以用二维DP记录应该访问的小矩形，$DP[x_1][y_1] =true$就表示小矩形$\{x_1, y_1, x_2, y_2\}$的面积应该被计入最后的结果中。



131: Palindrome Partitioning

https://leetcode.com/problems/palindrome-partitioning/description/

DP，DFS。先用dp计算任意子串是否为回文，再使用dfs收集合法的partition。

----


