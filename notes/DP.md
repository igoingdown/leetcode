#### DP专题

62: Unique Paths

<https://leetcode.com/problems/unique-paths/?tab=Description>

* DP
  * 二维DP递推表达式为$dp[i][j] = dp[i-1][j] + dp[i][j-1]$，可以简化为一维DP 进一步简化空间复杂度。
* Math（**最优解**）
  * 排列组合，使用排列数，总计 $ (m -1) + (n-1)$ 步，选择 $n-1$ 步向右或 $m-1$ 步向下，两者等价。
  * 用排列数还是组合数的讲究：核心在于选取的 m 个元素是否有差异，这个题目中元素之间没有差异，可类比一堆球，只有颜色（红色和蓝色）差异，抓 4 个球，其中有 2 个红球的抓取方式数。元素同质则顺序不影响结果

63: Unique Paths II

<https://leetcode.com/problems/unique-paths-ii/?tab=Description>

* DP，同62。

64: Minimum Path Sum

<https://leetcode.com/problems/minimum-path-sum/?tab=Description>

* DP，同62。

120: Triangle

<https://leetcode.com/problems/triangle/>

* DP
  * 自底向上：每个问题只有两个小的子问题，同62。
`dp[c] = min(dp[c], dp[c+1]) + triangle[r][c]`，$O(N^2)$。
  * 自顶向下：每个问题都是上一层的两个相邻父节点的较小值加上当前节点值


152: Maximum Product Subarray

<https://leetcode.com/problems/maximum-product-subarray/>

* DP
  * 使用两个数组`max_dp`和`min_dp`分别维护到第`i`个元素为止的最大和最小乘积。对于第 `i+1`个元素，有3种可能得到最大乘积
    * 当前元素本身
    * 当前元素乘以之前的最大值
	* 当前元素乘以之前的最小值
  * 以上3种情况的最大和最小值就是当前的max_dp和min_dp的值，同时 max_dp 的值也是全局最大值。
  * 对本题比较熟练的情况下，可以使用2个变量来代替1维DP。
  * 子数组的和、乘积等聚合性质都可以用这种思路，算法基础是递推关系明确，规模为 `n+1` 的问题可以降级为规模为`n`的子问题。记录包含第`n`个元素的子数组的聚合信息和全局最值，可以保证不重不漏，考虑加入第 `n+1`个元素的情况，只需考虑包含第 `n+1`个元素的新组合，不包含第`n+1` 元素的组合更小规模的子问题已经全部解决了。


53: Maximum Subarray

<https://leetcode.com/problems/maximum-subarray/?tab=Description>

* DP，同 152

363: Max Sum of Rectangle No Larger Than K

<https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/>

* BS：糅合有界前缀和，跟 DP 关系不大，DP 适合解决最值，有界值还是要用二分查找和前缀和


72: Edit Distance

<https://leetcode.com/problems/edit-distance/description/>

* DP。用二维数组记录$s[0,i]$与$p[0,j]$的距离。
  * 字符相等​：无需操作，直接继承前一步结果：`dp[i][j] = dp[i-1][j-1]`
  * ​字符不等​：取三种操作的最小值 + 1，dp[i][j] = min(插入, 删除, 替换) + 1。其中：
    * ​插入​：dp[i][j-1] + 1（在 word1 尾部插入 word2[j]）
    * 删除​：dp[i-1][j] + 1（删除 word1[i]）
	* 替换​：dp[i-1][j-1] + 1（将 word1[i] 替换为 word2[j]）

486: Predict the Winner

<https://leetcode.com/problems/predict-the-winner/description/>

* DP。二维DP比一维DP更易于理解。两个维度坐标含义相同，填表方式是先填长度比较小的范围，沿对角线填表。DP状态定义​：`dp[i][j]` 表示当剩余数组为 nums[i...j] 时，当前玩家与对手的得分差的最大值 
`dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1])`，每次都是1号玩家先取，
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

808: Soup Servings

math，DP，DFS，BFS。难点在于空间和时间限制很死，而题目结果是有极限的，
要发现问题的结果的规律，简化求解过程。
概率随着N的增大而显著增大，概率最大值为1，这就要自己去试探边界。
BFS导致TLE，DFS + memo可以接近临界情况，但是还是不够，
必须发现概率随N递增规律才能解出这道题。DP要考虑空间开销，我用的二维DP，
可以优化到一维DP。


560: Subarray Sum Equals K

https://leetcode.com/problems/subarray-sum-equals-k/description/

一刷使用二维DP内存超了，改为一维DP之后AC，这两种方法都是O(N^2)时间复杂度，空间复杂度一个为O(N^2)，一个为O(N)。
二刷用map存储累积和，map的查找替换了vector的查找，时间复杂度从O(N^2)降到了O(N)。
不太理解初始时"m[0]=1"的设置！


97: Interleaving String

https://leetcode.com/problems/interleaving-string/description/

DP。二维DP，`dp[i][j]`表示`s1`的子串$s1[0, i]$和`s2`的子串$s2[0,j]$是否可以组合成`s3`的子串$s3[0, i+j]$。
由于`s1`和`s2`组合为`s3`时，来自`s1`和`s2`的字符在源串中的相互顺序不变，因此`dp[i][j] == true`有两种情况：
1. `s3[i+j]`来自`s1`：即`s3[i+j] == s1[i]`，此时还要有`dp[i-1][j] == true`
2. `s3[i+j]`来自`s2`：即`s3[i+j] == s2[j]`，此时还要有`dp[i][j-1] == true`


139: Word Break

<https://leetcode.com/problems/word-break/description/>

DP。将$s[0, j]$分成两部分$s[0, i]$和$s[i+1, j]$，如果`dp[i] == true`且$s[i+1, j]$是字典中的词，
则`DP[j] == true`。可以令`i`从`j-1`遍历到`0`，只要发现符合上述情况的`i`就跳出循环，处理下一个`j`。时间复杂度$O(N^2)$，空间复杂度$O(N)$。


135: Candy

<https://leetcode.com/problems/candy/description/>

BFS，DP。

* BFS：将问题转化为拓扑排序，O(N^2)的复杂度，超时。
* DP：先从左向右扫描数组，与左侧元素比较更新DP，之后反向扫描数组，根据元素与右侧元素的关系修改DP。时、空间复杂度均为$O(N)$。

96: Unique Binary Search Trees

<https://leetcode.com/problems/unique-binary-search-trees/description/>

DP。

* 初始化: $dp[0] = 1, dp[1] = 1$。
* 递推关系: $dp[i] = \sum\_{j=1}^i (dp[j-1] * dp[i-j])$

将1到n分别作为根，左右两侧一个规模更小的子问题，左右两侧结果相乘就是一种情况，枚举所有情况求和即可。

这道题和矩阵相乘的那道题很类似，都是从序列中间取一个元素，
分割序列将问题转化为规模更小的子问题，同时分割元素可以是序列中的任意一个元素，
这类的递推函数很常见。DP问题的解不仅可以由一个小规模子问题的解得到，还可以由多个甚至所有小规模子问题的解的组合得到。


300: Longest Increasing Subsequence

https://leetcode.com/problems/longest-increasing-subsequence/#/description

DP，patient sort。
* patient sort：patient sort是专门应对这个问题的算法，时间复杂度为$O(N \log N)$。
* DP：时间复杂度为$O(N^2)$，效率略低，**注意重复数字不能计入length**，和95相似。

32: Longest Valid Parentheses

<https://leetcode.com/problems/longest-valid-parentheses/description/>

DP，stack，TP。TP是最高效的。

* DP: `dp[i]`记录的是以字符`s[i]`结尾的合法括号序列的长度，分两种基本情况：
	* `s[i] == '('`: 此时有`dp[i] = 0`；
	* `s[i] == ')'`: 此时根据`s[i-1]`的值分两种情况：
		* `s[i - 1] == '('`:此时`s[i]`和`s[i-1]`刚好配对， `dp[i] = dp[i- 2] + 2`
		* `s[i-1] == ')'`: 此时如果`s[i - dp[i-1] - 1]`（`'('`）和`s[i]`（`')'`）
		刚好可以将以`s[i-1]`结尾长度为`dp[i-1]`的合法子串包住，
		则有`dp[i] = dp[i-dp[i-1]-2] + dp[i-1]+2`。**注意：这种情况下，
		新的合法子串不仅包括被包住的合法子串，
		还包括被包住的合法子串之前的能够和新包住的合法子串拼接成更长的合法子串的部分**。
* stack: 栈中保存的是上一个非法字符的index，初始化栈顶为`-1`。
* TP：先后进行两次遍历，正向一次，反向一次，
并用`left`记录当前有可能合法的子串中左括号`'('`的个数，
用`right`记录当前有可能合法的子串中右括号`')'`的个数，用`result`记录全局的解。
	* 正向遍历会出现三种情况
		1. `left > right`：说明子串有可能合法的，因为后面可能会出现一些`')'`与前面多出的`'('`配对
		2. `left < right`：说明当前子串一定不合法，此时两个变量全部归零；
		3. `left == right`： 说明当前子串完全合法，此时应该更新`result`。
	* 反向遍历也会出现类似的三种情况：
		1. `left < right`：说明子串有可能合法的，因为前方可能会出现一些`'('`与后面多出的`')'`配对
		2. `left > right`：说明当前子串一定不合法，此时两个变量全部归零；
		3. `left == right`： 说明当前子串完全合法，此时应该更新`result`。
	* 一次遍历无法解决问题的原因：举个例子，当输入字符串为`((())`时，前向遍历得到的结果是0，
	因为最前面的那个`(`在后续遍历过程中一直无法找到可以与之配对的`')'`，
	而`left > right`始终成立。正向遍历优先匹配`'('`，而反向遍历优先遍历`')'`，
	这两种情况是互斥的，而且只有这两种元素，因此双向遍历是有效的。

647: Palindromic Substrings

<https://leetcode.com/problems/palindromic-substrings/description/>

DP，曼彻斯特算法。

* DP：时间复杂度和空间复杂度都是$O(N^2)$。
* 曼彻斯特算法：专门用于解决字符串中回文子串长度的算法，下面的说明来自[知乎高票答案](https://www.zhihu.com/question/37289584)。
	* 变量含义：
		* 字符串`str`：未添加`'#'`之前的原始字符串。
		* 字符串`buffer`：代表添加了`'#'`后的字符串。
		* 数组`max_len`：与`buffer`长度相同，`max_len[i]`表示以第i个字符为中心的回文串的最大半径。
		* 变量`max_pos`：表示当前**已经匹配完毕的结尾最远的回文串**到达了`buffer`数组的第`max_pos`个字符。
		* 变量`ID`：表示当前**已经匹配完毕的结尾最远的回文串**的中心字符index。
	* 不难发现，`max_len[i]-1`即以字符`buffer[i]`为中心的最长回文子串除去`'#'`的长度。
	* 当前字符`buffer[i]`已经被包含在曾经被判断过的回文串内（即`max_pos>i`)，
	那么它在这个回文串中相对应的那个字符`buffer[2*ID-i]`，应当已经被计算过以它为中心的回文串可以有多长了。
	那么以`buffer[i]`为中心的回文串长度，就有了第一个下限`max_len[2*ID-i]`（运用回文串的对称性）。
	另外以`buffer[2*ID-i]`为中心的回文串，它可能延展到了以`buffer[ID]`为中心的回文串之外。
	这样我们就不能保证以`buffer[i]`为中心的回文串包括了以`buffer[ID]`为中心的回文串之外的部分，
	于是我们得到了第二个下限：`max_pos-i`。综上，在`max_pos>i`时，
	我们就得到了`max_len[i]=min(max_len[2*ID-i],max_pos-i)`。
	这时我们只得到了一个可怜的下限，因此我们要在这个下限的基础上继续向外扩展。最后更新`max_pos`和`ID`。
	* 算法复杂度分析：考虑当前字符`buffer[i]`，我们可以分为三种情况:
		1. `max_len[i]=1`，说明`max_pos`没有覆盖超过`buffer[i]`，那么`max_pos`在这一步后一定会增加。
		2. `max_len[i]=max_pos-i`，说明以`buffer[i]`为中心的回文串至少到达了`max_pos`，那么`max_pos`在这之后不会减少。
		3. `max_len[i]=max_len[ID*2-i]`，说明可怜的以`buffer[i]`为中心的回文子串最长只有这么长，已经匹配不出去了。
	
		Mx的値是单调的，并且始终不会超过字符串长度Len，
		那么对于所有的`i`，**1**、**2**两种种情况的执行时间总和不会超过`Len`。因此总时间复杂度依旧是O(n)。


845: Longest Mountain in Array

https://leetcode.com/contest/weekly-contest-87/problems/longest-mountain-in-array/

DP。分别使用前向和后向DP记录左侧和右侧能与该元素形成单调递严格减的序列的长度，
正向遍历填充前向DP，逆向遍历填充后向DP，最后结合两个DP结果给出答案。


650: 2 Keys Keyboard

https://leetcode.com/problems/2-keys-keyboard/description/

一刷没思路，使用大神的思路AC。大神没有用DP，时间复杂度最好为O(logN),最差O(N)，比DP算法效率高，但是比较难以理解。再刷，注意理解！


376: Wiggle Subsequence

https://leetcode.com/problems/wiggle-subsequence/description/

一刷没思路，大神解法集中在贪心和DP两类。贪心算法一刷AC，不好理解，意思是每次选山峰的最高点和最低点，为什么这样就可以保证序列最长？
DP算法一刷初始化变量名写错，WA。再刷！
两种算法的区别和联系是什么？


516: Longest Palindromic Subsequence

https://leetcode.com/problems/longest-palindromic-subsequence/description/

一刷没思路，大神总结了从暴力递归到简化版DP的四种方法，一刷使用暴力递归发现TLE。
二刷使用带memo的递归，由于递归深度与字符串长度相同，字符串过长导致栈空间溢出得到MLE。
三刷使用DP,一次AC。空间复杂度为O(N^2)，时间复杂度为O(N^2)。
四刷使用更高效的DP，一次AC，时间复杂度为O(N^2)，空间复杂度为O(N)。
不用再刷，但是可以回顾，这个题目很经典。

暴力递归导致重复计算，于是有了带memo的递归。而随着递归深度增大，栈空间消耗过大，
于是有了DP。递归是top-down的思路，而DP则是bottom-up的思路。
这道题的关键的状态方程不易理解，需要举个例子，如“bbbab”, 
状态方程为("bbbab") = 'b' == 'b' ? 2 + ("bba") ? max("bbba", "bbab")。
可以清楚看到"bba"三者都有，而后面两个最大只是("bba") + 1。


322: Coin Change

<https://leetcode.com/problems/coin-change/description/>

DFS，BFS，DP。

* DFS：不能进行贪心剪枝，使用贪心剪枝并不一定得到最优解！如([10, 25, 30], 50)这个反例，
* BFS：因为问题要找最短的解，这相当于提示用BFS，但是BFS会导致MLE。
* DP：对$\forall$`i`$\in[0, amount]$，$DP[i] = \sum_k {DP[i - coins_k]}，i \geq coins_k$。

DP问题首先看问题能否降为子问题，如果能将原始问题分解为两个或更多规模更小的子问题，
那就很可能用Buttom-up的DP方法，这里面寻找最优子结构是最难的。一般面试能碰到的DP可以分为几类:
* 一维DP：如LCS、本题，
* 二维DP，`i`和`j`的含义相同：代表的是找回文子串(不用曼彻斯特算法的情况)
* 二维DP，`i`和`j`表示的含义不同：代表是0-1背包问题

518: Coin Change 2

<https://leetcode.com/problems/coin-change-2/description/>

DP。与上题不同的是要去重，这里计算的是目标组合的个数。
相比于这题，Climbing Stairs相比，这里因为计算的是合法组合数，去重更困难。
思路是先控制使用的coin的面值，逐个加入新面值，改变组合数。


740: Delete and Earn

<https://leetcode.com/contest/weekly-contest-61/problems/delete-and-earn/>

DP，可以降为子问题，典型的0-1背包问题。要继续思考，细嚼慢咽还是很有收获的。


115: Distinct Subsequences

<https://leetcode.com/problems/distinct-subsequences/description/>

DP。二维DP，`dp[i][j]`表示$S$的子串$S[0,i-1]$中包含$T$的子串$T[0,j-1]$这样的子序列的个数。
$T[0,0]$表示空串，初始化令$\forall i \in[0, S.size()]$，`dp[i][0]=1`表示$S$的任意子串都包含一个空的子序列。
后面分为两种情况：
* 基本情况：`dp[i][j] += dp[i-1][j]`，这种情况下在任意条件下都成立，表示不使用$S[i-1]$进行匹配
* 附加情况：当$S[i-1]$`==`$T[j-1]$时，`dp[i][j] += dp[i-1][j-1]`，当$S[i-1]$和$T[j-1]$相同时，还要加上去掉这两个字符之后的匹配结果。


494: Target Sum

<https://leetcode.com/problems/target-sum/description/>

DP，DFS。
* DP：`vecotr<T>::resize()`并不会对`vector`原有的数据进行重置，只会将其截断或者在后端补充，应该先用`clear()`清空数据之后再复用`vector`。
* DFS思路：将num分为正集合P和负集合N，于是有下面的推导
	1. $sum(P) - sum(N) = target$
	2. $sum(P) + sum(N) + sum(P) - sum(N) = target + sum(P) + sum(N)$
	3. $2 * sum(P) = target + sum(nums)$

	现在问题也就变成了寻求满足条件的P的个数，可以用DFS。


304: Range Sum Query 2D - Immutable

https://leetcode.com/problems/range-sum-query-2d-immutable/description/

一刷没有对二维数组的维度进行初始判断，没AC。
使用DP，时间复杂度和空间复杂度均为O(M\*N)，效率不高，二刷关键是调研更优秀的解法。


474: Ones and Zeroes

https://leetcode.com/problems/ones-and-zeroes/description/

一刷使用暴力DFS，TLE。bitset的使用得到了锻炼，bitset使用set和reset进行赋值，使用test测试位，使用count度量位。
二刷使用DP，出了bug，没调通。
三刷使用大神的空间复杂度O(M\*N)，时间复杂度O(M\*N\*L)的DP算法，一次AC。
大神的思路并不好理解，再刷！注意理解！


375: Guess Number Higher or Lower II

https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/

一刷使用dp思路不对，问题没想清楚，总想着用二分法，事实上二分法的结果并非最优！
二刷使用大神的bottom-up的DP，没有一次AC，对DP的更新过程理解不够，再刷，注意理解。


638: Shopping Offers

https://leetcode.com/problems/shopping-offers/description/

一刷使用自己设计的DP方法，WA。二刷使用带memo的dfs，这是top-down的dp，但是我更熟悉bottom-up的dp。
由于把变量k写成key（这也是变量名设计问题），一直WA，debug很久。
思路比较清晰，我自己两个思路都想明白了，但是手生。再刷！


546: Remove Boxes

https://leetcode.com/problems/remove-boxes/description/

一刷递归思路有漏洞，二刷使用DFS，
主要是k参数表示的是起始元素（第i个元素）的重复次数。
数据的删除过程很精妙，将两个相同元素之间的子序列进行递归，
起始元素就是k记录的重复元素。参数设置出错WA。
三刷使用DP， 
[这里有非常详细的解释](https://discuss.leetcode.com/topic/84687/java-top-down-and-bottom-up-dp-solutions)


5: Longest Palindromic Substring

https://leetcode.com/problems/longest-palindromic-substring/#/description

DP，TP。查找字符串中的最长回文子串。

* DP方法：使用DP判断每个子串是否为回文串，若子串为回文串且长度大于已知最长回文子串的长度，
则更新最长回文子串的起止点，时间复杂度和空间复杂度均为$O(N^2)$
* TP：遍历每个字符，沿两侧展开，更新起始点和最大长度，时间复杂度为$O(N^2)$，空间复杂度为$O(1)$。

198: House Robber

https://leetcode.com/problems/house-robber/description/

比较简单，DP一刷AC。时间复杂度和空间复杂度都是O(N)，可以将空间复杂度降至O(1)。二刷使用时间复杂度O(N)，空间复杂度为O(1)的DP算法，一次AC。


213: House Robber II

https://leetcode.com/problems/house-robber-ii/description/

一刷没思路，使用大神的DP思路没有对nums的长度为1时的场景进行判断，WA。
关键是将该题转化到上面一题。再刷的时候注意理解，思考留出一个house不rob从而破环的合理性。


583: Delete Operation for Two Strings Add to List

https://leetcode.com/problems/delete-operation-for-two-strings/#/description

DP。dp的元素矩阵表示应该删除的字符个数，最外围那一行和列表示一个串为子串，
而另外一个串为空串！


740: Delete and Earn

https://leetcode.com/contest/weekly-contest-61/problems/delete-and-earn/

DP，可以降为子问题，典型的0-1背包问题。要继续思考，细嚼慢咽还是很有收获的。


70: Climbing Stairs

https://leetcode.com/problems/climbing-stairs/description/

DP，递归。递归超时，可以使用迭代替换递归，实质是斐波那契数列，计算的是合法的排列数。


91: Decode Ways

https://leetcode.com/problems/decode-ways/#/description

线性DP。注意处理非法输入，每个原问题最多有两个最优子问题：
1. `f[0] = 0`，空串结果为0
2. `f[i] = s[i] == '0' ? 0 : f[i - 1] + "10" < s[i-1,i] <= "26" ? f[i-2] : 0`，
如果当前字符是`1-9`，则该字符可以单独decode，这是`f[i]`应该加上`f[i-1]`，
如果当前字符和前一个字符组成的字符串属于`["10", "26"]`，

这两个字符可以连在一起decode，此时`f[i]`应该加上`f[i-2]`，于是这个题目的实质就和斐波那契数列一致了。



10: Regular Expression Matching

https://leetcode.com/problems/regular-expression-matching/description/

DP，DFS。正则表达式匹配，频率超高！同频的还有四则运算表达式的计算，前、中、后缀表达式切换和运算！

* DFS：分char和`.`，之后在内部讨论后面是否有`'*'`。
* DP：对于$p$中的任意字符$p_j$和要与$p_j$匹配的$s$中的字符$s_i$,先考虑$p_j$是否为`'*'`：
	1. $p_j$`== '*'`：此时分$s_{i}$是否为$p_{j-1}$的重复：
		* $s_i$是$p_{j-1}$的重复：此时应有$s[0,...,i-1]$和$p[0,...,j]$匹配成功，`dp[i][j] =  dp[i-1][j] && s[i] == p[j-1]`
		* $s_i$不是$p_{j-1}$的重复：此时可以视为$p_{j-1}$在$s[i]$后重复了0次，应有$s[0,...,i]$和$p[0,...,j-2]$匹配成功，`dp[i][j] = dp[i][j - 2]`
	2. $p_j$`!= '*'`：如果成功匹配，则$p[j]$必为通配符`'.'`或者$s[i]$`==`$p[j]$，`dp[i][j] = p[j] == '.' || s[i] == p[j]`。


764: Largest Plus Sign

判断仅含有0和1的矩阵中，1的位置能够组成的最大“十字架”的形状大小。

DP。


798: Smallest Rotation with Highest Score

DP。一刷使用暴力法O(N^2)超时。大神的DP方法没看懂，继续攻克DP解法。



689: Maximum Sum of 3 Non-Overlapping Subarrays

https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/description/

在数组中找出3个不重叠长度为K的连续子数组要求三个数组的和最大。
* BF解法，遍历三个子数组所有可能的起始位置，求和，O(KN^3)。
* DP解法，使用前缀和记录sum，这应该视作解决连续序列问题的基本方法！
三个internval的出现的位置是被限定的，middle的起始位置i处于[k, n - 2k]区间，
当middle限定后，left的起点限定在[0, i - 1 - k]区间，right起点限定在[i + k, n - k]区间。
从左向右使用缓存记录left的局部最大值，从右向左记录right的局部最大值，
当middle的起点i从左向右移动时，只要知道[0, i - 1]区间left的最大值和[i + k, n - 1]区间上right的最大值即可。


279: Perfect Squares

https://leetcode.com/problems/perfect-squares/#/description
* DP
* Math: 


459: Repeated Substring Pattern

https://leetcode.com/problems/repeated-substring-pattern/#/description

DP。时间复杂度为O(N)。


132: Palindrome Partitioning II

https://leetcode.com/problems/palindrome-partitioning-ii/description/

DP。找出将字符串$s$分割为多个palindrome子串的最小的切割次数。

用二维数组$f$记录子串$s[i,j]$是否为palindrome，用一维数组$h$记录子串$s[0,j]$的最小分割。
* 判断palindrome与上题无异
* 若$f[i][j]$`== true`，$h[j] = min (1 + h[i-1], h[j])$。
* 判断palindrome可以先遍历$j$再遍历$i$，两层循环即可。



321: Create Maximum Number

https://leetcode.com/problems/create-maximum-number/


DP。我跟小爽几想到的是笨方法，需要两次 DP。
* 第一次 DP: 找出用 n 个数字,保持数字相对顺序，用其中 i([1,n]) 个数字能找到的最大值
* 第二次 DP: 将 x 和 y 两个数组合成一个数，并保持内部相对顺序不变，要判断 每一位是选择 x 还是 y


264: Ugly Number II

https://leetcode.com/problems/ugly-number-ii/#/description

两种解法
Heap: 最小堆
DP: dp[i] = min(dp[p2] * 2, dp[p3] * 3, dp[p5] * 5)

