---
style: summer

tags:
  - leetcode
  - summary
  - algorithm
  - 笔试
  - 面试
  - 题目
  - job
  - 算法
---


463: Island Perimeter

<https://leetcode.com/problems/island-perimeter/>

Matb。遍历所有的cell，用分离的cell总的的边数减去重叠的边的数目即可。在查找重叠的边的数目的时候有一点小技巧，就是沿着其中两个方向就好，可以沿着上三角或者下三角形的方向来做。

455: Assign Cookies

<https://leetcode.com/problems/assign-cookies/>

TP，greedy。给出两个序列$g$和$s$，$g_i$代表能满足第$i$个孩子要求的最小cookie的size，$s_j$表示第$j$个cookie的size。问如何分配使得到满意的孩子最多。

先将两个序列$s$和$g$升序排序，然后按双路指针的方式解决。思路是为每个孩子分配一个能满足需求的cookie，有点贪心算法的味道。STL的`algorithm`库中的`sort(beg, end, comp)`函数实际使用快排，其中的`comp`是函数对象或者函数指针，签名是 `bool comp(elem_type first_arg, elem_type second_arg)`，返回的`bool`值的含义是第一个参数是否应该排在第二个参数的前面。而且默认参数会将较小的参数排在前面，即`sort`函数默认升序排序！

453: Minimum Moves to Equal Array Elements

<https://leetcode.com/problems/minimum-moves-to-equal-array-elements/>

Math。给定长度为$n$的数组$A$，定义$A$上的一个元操作：**将数组中的n-1个元素加1**，最少经过多少次元操作可以使数组中元素都相等?

**将数组中的n-1个元素加1**等价于**数组中不加1的那个元素减去1，然后数组中的所有元素都加1**。将所有的元素都加1并不能改变原数组中的数之间的差值，于是本题就转化为求**最少的减1操作**。而要使数组中的元素全部相等，又要使用减法，那么最少的次数就是让这些元素全部都等于数组中最小的数。于是`answer = `$\sum_{i=1}^{n}A_i - min(A) * n$。

383: Ransom Note

<https://leetcode.com/problems/ransom-note/>

HashMap。判断能否用后一个串合成前一个串，只要后一个串的每个字符的频率都不小于前一个串的字符频率即可。

404: Sum of Left Leaves

<https://leetcode.com/problems/sum-of-left-leaves/>

* 递归:只要想明白一个节点的情况，其他节点都一样。对于每个节点如果指针为空，返回0；如果左子为叶子节点，结果要加上左子的值，否则要加上左子树的递归结果，最后加上右子树的递归结果返回即可。
* 非递归。利用栈，处理栈顶元素的时候直接处理栈顶元素，应该处理栈顶元素的左右结点。

834: Sum of Distances in Tree

<https://leetcode.com/contest/weekly-contest-84/problems/sum-of-distances-in-tree/>

DFS。用图的思路解决树的问题。先用DFS算出根节点到其他节点的距离之和`tot`，在计算过程中连带算出以任意节点$Node_i$为根节点的子树的节点个数$c_i$，这两个问题都是比较简单的问题。然后DFS遍历所有节点，已知根节点到所有其他节点的距离之和`s[cur]`的情况下，算任意一个子节点到其他所有节点的距离之和`s[child]`的公式是: `s[child] = (s[cur] - c[child]) + (tot - c[child])`。这是因为已知根节点`cur`到所有其他节点的距离之和`s[cur]`，求所有其他节点到一个子节点`child`的距离之和`s[child]`，可以将所有节点分为两部分，其中一部分是以`child`为根节点的子树，另一部分是整个树的其余部分。以`child`为根节点的子树上的每个节点到`cur`的距离减1就是这些节点到`child`的距离，树的另一部分上的每个节点到`cur`的距离+1就是他们到`child`的距离。反映在最终结果(距离加和)上，前一部分需要在`s[cur]`的基础上减掉`c[child]`，后一部分需要在`s[cur]`的基础上加上`(tot - c[child])`，于是就有了上面的公式。

409: Longest Palindrome

<https://leetcode.com/problems/longest-palindrome/>

HashMap。记录每个字母的个数，是偶数的话可以直接分两部分拼到结果palindrome的两侧对称的位置，如果字母个数为奇数个，选择偶数个分两部分拼到结果palindrome的两侧对称位置。如果有字母个数为奇数，可以将剩余的那个作为结果palindrome的轴。


448: Find All Numbers Disappeared in an Array

<https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/>

Math。在原数组上进行改动，对于$\forall i$，将$A_{|A_i|}$变为负数以标记出现过的数。之后遍历`i`$\in [1, n]$，如果$A_i > 0$，则`i`是missing的。

442: Find All Duplicates in an Array

<https://leetcode.com/problems/find-all-duplicates-in-an-array/>

同448。区别在于遇到重复值时直接就加入结果列表即可。


414: Third Maximum Number

<https://leetcode.com/problems/third-maximum-number/>

找出`n`个数中的第`m`（`m <= n`）大的数，这是个经典问题

* `m`不太大（`m<4`）时：同时设置多个max，遍历数组元素，分条件更新max。注意两点，一是max的初始化一定要比当前数组元素类型的最小值要小；二是max更新条件要写全，“=”的情况要排除。
* 当`m >= 4`时：可以借用快排的partition操作来做。

289: Game of Life

<https://leetcode.com/problems/game-of-life/>

位操作。遍历每个cell，每个cell的状态由分为0和1，可以将右侧第一位视为本轮的状态，右侧第二位视为下一轮的状态。由于0视为2位表示时是00，1视为2位表示时是01，这种表示不影响本轮的状态，而且可以在原地进行操作，更新下一轮的状态。最后将所有cell的状态右移1位就瞬间变为下一轮的状态了。

287: Find the Duplicate Number

<https://leetcode.com/problems/find-the-duplicate-number/>

BS，TP。TP是将问题转化为链表内部环检测的问题，因为这种存储结构实际上是一种*P**字形的逻辑结构，就是要招链表环的起点。

2: Add Two Numbers

<https://leetcode.com/problems/add-two-numbers/description/>

链表尾插法。

445: Add Two Numbers II

<https://leetcode.com/problems/add-two-numbers-ii/#/description>

链表。先反转链表，然后按第2题做。不允许反转链表可以先求二者长度，然后从后向前遍历。

24: Swap Nodes in Pairs

<https://leetcode.com/problems/swap-nodes-in-pairs/description/>

链表尾插法。一次走两步，注意使用`dummy_node`时，如果原链表只有一个元素直接返回`dummy_node->next`是错误的，要对这种情况进行判别。


268: Missing Number

<https://leetcode.com/problems/missing-number/>

Math。求和再做减法最方便，为了防止溢出需要用范围更大的数据结构。

229: Majority Element II

<https://leetcode.com/problems/majority-element-ii/>

Math。数组中最多有两个数`n1,n2`的频数`>n/3`。

BM多数投票算法（Boyer-Moore Majority Vote algorithm）。将n1，n2初始化为任意两个不同的数就行，对应counter1和counter2初始化为0。还要注意一点第一次遍历结束只是明确了n1，n2是出现频率最高的数，但是对应的counter是不准的，需要重新计数后再查看counter是否满足条件。

228: Summary Ranges

<https://leetcode.com/problems/summary-ranges/>

TP。用`b,e`分别记录当前range的起、止index，每次循环向后挪动`e`至range末尾的下一个元素，将当前range加入到结果列表中，令`b=e`即可。

547: Friend Circles

<https://leetcode.com/problems/friend-circles/description/>

DFS，并查集。并查集的`find(x,parents)`函数不用递归最好，可以在循环过程中缩减树的深度，增加树的宽度，达到提高效率的目的。

721: Accounts Merge

<https://leetcode.com/problems/accounts-merge/description/>

DFS，并查集。

839: Similar String Groups

<https://leetcode.com/contest/weekly-contest-85/problems/similar-string-groups/>

并查集。并查集在逻辑上构造一个森林，先将每个节点都初始化为森林中的一棵树，group为N。然后遍历所有的边，对于每一条边，如果两个节点所在树的根节点不同，就将后一个节点所在的树的根节点作为前一个节点所在树的根节点的子节点，同时group减1。这样就可以解决并查集的第一类题目，就是求group的数量。另一种题目要求不仅分出group，并且要给出每个group具体有哪些节点，这时候需要遍历每个节点，找出其所在树的根节点，按根节点分离每个group即可。547，839属于第一类，721属于第二类。

720: Longest Word in Dictionary

<https://leetcode.com/problems/longest-word-in-dictionary/description/>

Trie+DFS或者Trie+BFS。

677: Map Sum Pairs

<https://leetcode.com/problems/map-sum-pairs/description/>

Trie+BFS。

842: Split Array into Fibonacci Sequence

<https://leetcode.com/contest/weekly-contest-86/problems/split-array-into-fibonacci-sequence/>

DFS. 记录起始位置和分离结果，设置终止条件，将问题转为子问题，注意处理起始字符为`0`和解析出的数`>= INT_MAX`的情况。

743: Network Delay Time

<https://leetcode.com/problems/network-delay-time/description/>

DFS，BFS，Dijkstra。Dijkstra算法效率不如BFS，问题在于我实现的版本效率不高，可以继续改进。BFS是Dijkstra的降级。

542: 01 Matrix

<https://leetcode.com/problems/01-matrix/description/>

BFS。从`0`出发，初始化将所有位`0`的cell入队，作为第0层，然后BFS将后面访问的cell的值设为层数即可。

30: Substring with Concatenation of All Words

<https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/>

TP。

* KMP：使用KMP得到每个关键字在母串中出现的所有位置，然后使用DFS得到解，这种方式超时。
* TP：使用`map`记录每个模式串及对应的频率，两层循环，外循环遍历母串中可以作为拼接串起始位置的index `i`$\in [0,ss - ws * l)$，内循环进行匹配，每次匹配都从母串中取出长为`l`的子串，看是否在`map`中，在`map`中则修改`map`，直到`map`为空，这时产生了一个答案。此时继续外循环即可。

417: Pacific Atlantic Water Flow

<https://leetcode.com/problems/pacific-atlantic-water-flow/description/>

DFS，从外侧（海洋）向内部蔓延。用`visited`数组中的元素最后一位表示能否从大西洋过来，倒数第二位可以用于表示能否从太平洋过来，如果两个都可以过来，标识为3，只能从大西洋过来标识为1，只能从太平洋过来标识为2，都过不来标识为0。

162: Find Peak Element

<https://leetcode.com/problems/find-peak-element/>

BS。二分法可以用递归和非递归的方式实现现，复杂度为$O(logN)$。本题是一维数组找极值，MS有道题是二维数组找极值，思路相同，二分，$O(N)$时间找行的最小值，跟相邻行比较，如果是极值点则结束，不是就找更小的那个子矩阵。fun的水滴证明法相当直观！

154: Find Minimum in Rotated Sorted Array II

<https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/>

BS。

164: Find Minimum in Rotated Sorted Array

<https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/>

和154一模一样。

152: Maximum Product Subarray

<https://leetcode.com/problems/maximum-product-subarray/>

DP。用`f_max[i],f_min[i]`分别记录以`nums[i]`结尾的sub-array的乘积最大值和最小值。初始化`f_max[0] = nums[0]; f_min[0] = nums[0];`，然后遍历`i`$\in$`[1, nums.size()）`，更新规则分别为`f_max[i] = max(nums[i], max(f_max[i - 1] * nums[i], f_min[i - 1] * nums[i]));`和`f_min[i] = min(nums[i], min(f_max[i - 1] * nums[i], f_min[i - 1] * nums[i]));`。对本题比较熟练的情况下，可以使用2个变量来代替1维DP。

136: Single Number

<https://leetcode.com/problems/single-number/>

位操作。想象一个多层公寓，每个公寓住着0或者1，异或像如来神掌一样将每一位从上而下压缩。


137: Single Number II

<https://leetcode.com/problems/single-number-ii/description/>

位操作。每一位都有规律，仍然可以按照上题的思路思考，每一位上都是这样的规律$sum = x_1 * 3 + x_2 * 3 + ... + x_{n-1} * 3 + y$，要得到y对sum模3即可。

260: Single Number III

<https://leetcode.com/problems/single-number-iii/description/>

位操作，按第一个不同的位将nums分为两派即可。思路同前两道题。

461: Hamming Distance

<https://leetcode.com/problems/hamming-distance/description/>

位运算，与和异或。

477: Total Hamming Distance

<https://leetcode.com/problems/total-hamming-distance/description/>

位运算，分两派，该位为0和该位为1，分别记录每派的count，相乘加到结果上即可。


201: Bitwise AND of Numbers Range

<https://leetcode.com/problems/bitwise-and-of-numbers-range/description/>

位运算


405: Convert a Number to Hexadecimal

<https://leetcode.com/problems/convert-a-number-to-hexadecimal/description/>

位运算，注意0的问题，算术右移和逻辑右移的区别。


421: Maximum XOR of Two Numbers in an Array

<https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/>

位操作，Math。

190: Reverse Bits

<https://leetcode.com/problems/reverse-bits/description/>

位操作。将一个32位无符号数的2进制表示reverse，利用进制，采用10进制的方式来做即可，低位的权重更高。


7: Reverse Integer

<https://leetcode.com/problems/reverse-integer/description/>

Math。和190相似，注意INT_MAX、INT_MIN和正负号，参考**atoi**。


476: Number Complement

<https://leetcode.com/problems/number-complement/description/>

位运算，求补码，从符号位开始0变为1，然后取反。


342: Power of Four

<https://leetcode.com/problems/power-of-four/description/>

位运算。

318: Maximum Product of Word Lengths

<https://leetcode.com/problems/maximum-product-of-word-lengths/description/>

位运算。

104: Maximum Depth of Binary Tree

<https://leetcode.com/problems/maximum-depth-of-binary-tree/>

BFS，DFS。

389: Find the Difference

<https://leetcode.com/problems/find-the-difference/>

HashMap。对于字符串的常用方法，将字符转为数组下表，从而将空间复杂度降到O(N)。

226: Invert Binary Tree

<https://leetcode.com/problems/invert-binary-tree/>

DFS，递归。

169: Majority Element

<https://leetcode.com/problems/majority-element/>

Math，鸽巢原理，投票法。同权投票众数的票数最多，一定胜出。

100: Same Tree

<https://leetcode.com/problems/same-tree/>

DFS，递归。

128: Longest Consecutive Sequence

<https://leetcode.com/problems/longest-consecutive-sequence/>

HashMap，空间换时间。可以使用师姐的思路，每次遇到没访问过的元素，访问之，并查看该元素所在最长连续序列的长度，更新结果，$O(N^2)$。使用unordered_map记录访问元素的最大长度。当n-1和n+1都访问过后，将序列两端的元素对应的最大长度更新。因为之后序列内部的元素就不考虑了，只会考虑序列外的元素，而序列外的元素跟该序列可能链接的地方只有左右两端，这个题很像DP，注意要将该元素设为访问过的状态，要向map中添加pair，$O(N)$。

719: Find K-th Smallest Pair Distance

<https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/>

Hashmap，已知距离的范围，用vector对所有的距离进行计数，最后找出第k小的距离。


381: Insert Delete GetRandom O(1) - Duplicates allowed

<https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/description/>

Hashmap。使用`map`记录`val`到`val`在`nums`中出现的index的list `indices`的映射，`nums`记录的是一个个的pair，由`val`和`val`在`indices`中对应的index组成。有如下的关系`map[nums[i].first][nums[i].second] = i`。`random`函数只要随机从nums中任选一个即可，因为这种情况下数组中每个元素被选中的概率相同，满足`一个val的被选中的概率与其出现的次数成线性关系`的条件。详细思路[看这里](https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/discuss/85541/C++-128m-Solution-Real-O(1)-Solution)。


873: Length of Longest Fibonacci Subsequence

<https://leetcode.com/contest/weekly-contest-94/problems/length-of-longest-fibonacci-subsequence/>

Hashmap。给定一个数组$A$，找出其中最长的满足斐波那契规律的子序列的长度。

由于题目只需要知道最长的斐波那契子序列的长度，可以暴力解决。为了方便查找，将数组拷贝一份到Hashmap中，遍历所有可能的子序列，开头分别是$A_i$和$A_j$($i<j$)，如果Hashmap包含$sum = A_i + A_j$，则令$A_i = A_j, A_j = sum$，重复以上过程，记录可能得到的最大长度，时间复杂度为$O(N_3)$。

874: Walking Robot Simulation

<https://leetcode.com/problems/walking-robot-simulation/description/>

Hashmap。给定一个边界无限的二维平面和一个初始处于这个平面上原点面向$Y$轴正向的机器人，二维平面上有些障碍物$O$无法通过，给定一组命令$C$，每条命令为一个整数，正整数表示前进的距离，$-1$表示右转，$-2$表示左转。机器人执行命令，前进过程中如果遇到障碍物会停下，直到转向绕过障碍物。问机器人**执行命令过程中到原点的最远欧式距离**。

从原点出发，模拟机器人执行命令的路线，更新能够导到的最远距离。只要比较每条命令执行完机器人所处的位置到原点的距离和已知最大距离即可，因为沿着单一方向移动过程中的，机器人所处的位置到原点的欧式距离不可能有极（最）大值，只有中间停顿处才可能出现极（最）大值。


105: Construct Binary Tree from Preorder and Inorder Traversal

<https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/>

递归。


106: Construct Binary Tree from Inorder and Postorder Traversal

<https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/>

递归。同105，由于树中无重复元素，可以用map记录inorder中元素到index的映射，这样就不用在生成树时遍历inorder查找元素了，这样可以把时间复杂度降为$O(N^2)$。


108: Convert Sorted Array to Binary Search Tree

<https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/>

递归，二分查找。


109: Convert Sorted List to Binary Search Tree

<https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/#/description>

同108，区别在于本题中`mid`要通过快慢指针来找。

114: Flatten Binary Tree to Linked List

<https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/>

递归，将左右分别flattern之后，将左侧链接到右侧。

761: Special Binary String

<https://leetcode.com/problems/special-binary-string/description/>

* BFS:每次选字符串中两个special binary substring交换，如果结果没有访问过就将其放入队列中，这种解法是我自己的解法，有大量重复计算，超时。
* 递归：根据题意可以将special binary string类比为valid parenthesis，其中`1`类比为`(`，`0`类比为`)`，字母顺序更大可以类比为我们倾向与将**更深**的valid parenthesis排在前面。于是很容易想到递归算法，递归函数`f`的函数体：
	* 将valid parenthes分成多个连续的valid sub-parenthesis
	* 对每个valid sub-parenthesis除去最外层的`()`的部分调用递归函数`f`，得到相应的字母顺序最**大**的valid sub-parenthesis
	* 将上一步得到的结果按**更深的valid sub-parenthesis排在更前面**的规则排序并将排序后的子串拼接起来返回即可。
* 不管是`0,1`，还是`()`都是一种逻辑的代号，`0,1`不如`()`直观，详情可以参考[这篇解释](https://leetcode.com/problems/special-binary-string/discuss/155621/Logical-Thinking-with-Clear-Code)。

74: Search a 2D Matrix

<https://leetcode.com/problems/search-a-2d-matrix/?tab=Description>

BS，将矩阵降为视为一维数组用BS。index的映射关系:`matrix[mid / n][mid % n]`。

240: Search a 2D Matrix II

<https://leetcode.com/problems/search-a-2d-matrix-ii/description/>

math，BS的变形，所选的哨兵为角上的元素，每次将范围缩减一行或一列，$O(\max(M,N))$。暴力方法是对每一行进行BS，$O(MlogN)$。

73: Set Matrix Zeroes

<https://leetcode.com/problems/set-matrix-zeroes/?tab=Description>

将第一行(或第一列)作为标志，第一行(或第一列)用其他标志。从$(0, 0)$到$(m-1, n-1)$前向遍历将标志置0，从$(m-1, n-1)$到$(0, 0)$逆序遍历按标志将元素置0。时间复杂度$O(MN)$。

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

DP。自底向上，每个问题只有两个小的子问题，同62。`dp[c] = min(dp[c], dp[c+1]) + triangle[r][c]`，$O(N^2)$。

799: Champagne Tower

<https://leetcode.com/contest/weekly-contest-75/problems/champagne-tower/>

BFS。

53: Maximum Subarray

<https://leetcode.com/problems/maximum-subarray/?tab=Description>

DP，可以降为0维DP。设有长度为$n$的数组$a$用`sum`和`res`分别记录当前的累加和与最终的结果。从$a_1$开始累加，当加到$a_i$时候如果`sum < 0`，将`sum`清零，相当于把前面的一个连续子数组扔掉，如果`sum > 0`更新result。这样做的原因是如果上述算法中出现$\sum_{k = i}^{j}a_k < 0$，则必有$\sum_{k=i}^{j+\lambda}a_k < a_{j+\lambda}, \lambda \in [1, n-j]$ 因此可以将$a[i,j]$这部分直接扔掉，从`j+1`开始继续查找和最大的连续子数组。

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

DP。二维DP比一维DP更易于理解。两个维度坐标含义相同，填表方式是先填长度比较小的范围，沿对角线填表。`dp[i][j] = min(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1])`，每次都是1号玩家先取，1号玩家取完之后2号玩家就成了“1”号玩家，但是对于1号玩家来说，2号玩家充当“1”号玩家时得到的分数实际上就是1号玩家失掉的分数。当两者都是用最优的策略进行游戏时，一个玩家取了一个数之后，问题规模减1，而问题的结构是完全相同的，于是有了上式。

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

56: Merge Intervals

https://leetcode.com/problems/merge-intervals/?tab=Description

sort。sort的第三个参数为重载了"<"的函数，可以自己写myCompare函数实现"<"逻辑，也可以写函数类用于构建函数对象，也可以利用C++11新特性lambda表达式实现，编译器会根据lambda表达式生成函数对象。

57: Insert Interval

https://leetcode.com/problems/insert-interval/description/

本题至少有两种方法：
* 方法一：sort，同上题。先将要新Interval插入列表，sort后按上题的思路merge。$O(N\log{N})$
* 方法二：由于题目给定的Interval列表已经有序，插入新的Interval不需要重新对列表排序。扫一遍Interval列表，当前的Interval如果能merge到新Interval中，则更新新的Interval，如果不能更新，没有交集且当前的Interval在新的Interval前，则直接加入结果，如果没有交集且当前的Interval在新的Interval之后，直接退出扫描。将新的Interval和剩下的Interval逐个加入结果列表中。这是fun的方法，实际上模拟了上题合成单个Interval的过程，$O(N)$。

406: Queue Reconstruction by Height

<https://leetcode.com/problems/queue-reconstruction-by-height/description/>

sort。使用lambda表达式进行sort，然后将每个元素插到`res`的`res.begin()+p.second`的位置上。C++中的lambda表达式的书写规范为:`[](const T &a, const T &b){return a < b}`。

54: Spiral Matrix

<https://leetcode.com/problems/spiral-matrix/?tab=Description>

math。内循环每次从$(i,i)$开始，向右走到$(i, n - i - 1)$, 再向下走到$(m - i - 1, n - i - 1)$，再向左走到$(m - i - 1, i)$, 最后向上走到$(i + 1, i)$。注意去重，即后遍历一圈的过程中，前后两次沿相反的方向遍历的不能是同一行或者同一列！

59: Spiral Matrix II

<https://leetcode.com/problems/spiral-matrix-ii/?tab=Description>

同54。

835: Image Overlap

<https://leetcode.com/contest/weekly-contest-84/problems/image-overlap/>

math。空间考察，两个大小一样的方阵A，B重叠，有四种可能的情况，固定A，B可以与A重叠左上角，左下角，右上角，右下角。遍历A的格，作为重叠的部分在A内的一角，遍历B的每个格，根据重叠部分在A的方位（四个，所以有四种情况），计算重叠的格在A中对应的行和列，判断两者的值并分别计数。

858: Mirror Reflection

https://leetcode.com/contest/weekly-contest-90/problems/mirror-reflection/

math。全镜面正方形二维房间，一束光从一角照进来，控制入射角度（q控制）和房间的长度（p），观察这束光第一次照到角上会最先照到另外三个角的哪一个。这是一个非常好的初中物理题。其实只要沿一个方向（上方）按光的反射定律无限延伸即可，如果想到最简单的照到其它三个角的方式，后面就容易了。于是问题变为一个数学问题，一个点每次向上跑q，看什么时候能达到$n * q % p == 0$的条件，根据n来判断是哪个角。

867: Prime Palindrome

https://leetcode.com/contest/weekly-contest-92/problems/prime-palindrome/

math。给定整数N，找出一个回文质数`p`，要求`p`是满足`p >= N`的第一个回文质数。 由于题目条件`N < `$10^8$而且`N`为`int`型，因此可以遍历$i \in [0, 10000]$，作为回文数的左侧部分，然后通过`mirror`函数，将右侧补全。补全的过程中可以在左右两部分的中间添加一位数字$j \in [-1, 9]$($j=-1$表示不添加)。如果`mirror`函数的结果`p`满足$p >= N$且`p`是回文数，则答案正确。

上面的解法有个小trick，仔细分析`mirror`函数的遍历过程会发现，每次遍历的时候都是先产生一个$2k$位的整数，然后再产生10个$2k+1$位的整数，这就产生了一个问题:为什么先遍历大的整数，再遍历小的整数结果却不会出错？其实这是因为符合模式为`xx`(`x`表示一个整数)的质数只有11一个，这个结论需要证明！

48: Rotate Image

<https://leetcode.com/problems/rotate-image/?tab=Description>

math。矩阵顺时针旋转，先将矩阵进行上下翻转(上换到下)，然后对角互换(左下换到右上)，于是左上就换到了右上，左下换到了左上，右上换到了右下，右下换到了左下，实现了顺时针旋转90度。也可以先进行左右翻转，然后将左上和右下互换，由于左上与右下互换不如左下与右上来的简单，因此第一种方案更好一点。对于逆时针旋转先上下翻转，然后左上与右下互换。

66: Plus One

<https://leetcode.com/problems/plus-one/description/>

math。初始化令最低位进位c=1,可以按照统一的模式解决。

35: Search Insert Position

https://leetcode.com/problems/search-insert-position/?tab=Description

BS。可以直接用`upper_bound`或者`lower_bound`来做。

34: Search for a Range

https://leetcode.com/problems/search-for-a-range/?tab=Description

BS。BS查找下界和上界两类问题存在区别，区别在于求下界时mid要靠近low，求上界的时候mid要靠近high；这种区别决定在每次循环更新要找的那个界限（low或者high）。也可以直接使用STL的`upper_bound`和`lower_bound`。

33: Search in Rotated Sorted Array

https://leetcode.com/problems/search-in-rotated-sorted-array/?tab=Description

BS。先拿$a_{mid}$和$a_{low}$比较，是为了确定$a[mid]$在较大的前半部分还是较小的后半部分，$a_{mid}$在前半部分的条件就是$a_{low} \leq a_{mid}$。然后再根据$target$所处的位置分类。不能先用$target$进行分类，因为$target$可能不存在于数组中。


81: Search in Rotated Sorted Array II

https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

BS。同33，只是数组中存在重复元素，$a[mid] = a[low]$时分类不明显，直接拎出来，令`low++`(相当于遍历)，其余不变。


875: Koko Eating Bananas

https://leetcode.com/problems/koko-eating-bananas/description/

BS。有$N$堆香蕉，记为$P$，每堆有$P_i$个香蕉，KOKO要在$H$小时内把香蕉吃完，KOKO可以控制自己每小时吃的最多香蕉数$K$，而且每小时只选择一个香蕉堆吃香蕉，计算KOKO完成吃香蕉任务最小的$K$。

$K \in  [\sum_{i} P_i, \max_i{P_i}]$，已知上界和下界，用BS找目标元素$t$即可，目标元素$t$需要满足$\sum_{i}P_i/t$的上界 $<= H$。


31: Next Permutation

https://leetcode.com/problems/next-permutation/?tab=Description

math。先从后将降序序列反转，然后找被反转序列的前一个数字在反转序列中的上界与该数字替换。


41: First Missing Positive

<https://leetcode.com/problems/first-missing-positive/description/>

math，鸽巢原理，第一个missing的正整数的范围一定是$[1, array.size() + 1]$。类似小米实习面试题。

遍历数组中的每个坑，向坑中填入应该填入的数，规则是:第$i$个坑中填入的数为$i+1$，即$nums[i-1]=i$，对于每个坑$i$，只要不满足以下3个条件：
* $nums[i] \leq n$ `&&` $nums[i] > 0$
* $nums[i] - 1 \neq i$
* $nums[i] \neq nums[nums[i] - 1]$（防止因为有重复的数而导致死循环）

就执行`swap(nums[i], nums[nums[i] - 1])`将$nums[i]$装入到应该出现的位置(第$nums[i]-1$个坑)，此时第$i$个坑出现了一个新的数，重复以上步骤直到以上条件不满足或者第$i$个坑中填入了正确的数。

38: Count and Say

https://leetcode.com/problems/count-and-say/description/

TP。将序列模仿出来即可。


11: Container With Most Water

https://leetcode.com/problems/container-with-most-water/?tab=Description

TP。左右指针分别从数组两端开始，两指针夹逼过程中，矩形的长变小，只有宽增大，面积才可能增大。


67: Add Binary

https://leetcode.com/problems/add-binary/description/

TP。双指针后向遍历，最后将得到的结果逆转。

75: Sort Colors

<https://leetcode.com/problems/sort-colors/>

* 排序算法：手写快排、堆排等时间复杂度都是O(NlogN)。
* 暴力法：第一次遍历记录0，1，2的数量，第二次遍历按照数量赋值上去，$O(N)$。
* TP：$O(N)$。令$index_0$和$index_2$分别表示下一个0和2应该填进去的坑，扫一遍数组，将0放在swap到前面，2swap到后面，1自然就被swap到中间了。
* 变式题是阿里的二面算法题。RGB无序序列排成RGBRGB形式的序列，三指针。

821: Shortest Distance to a Character

https://leetcode.com/contest/weekly-contest-81/problems/shortest-distance-to-a-character/

TP。string中里指定字符最近的距离，分别从左侧和右侧使用TP进行遍历。

820: Short Encoding of Words

https://leetcode.com/contest/weekly-contest-81/problems/short-encoding-of-words/

TP。将后缀通过反转转为前缀，sort，出去子串长度即可，加法不好做，可以换到减法。


833: Find And Replace in String

https://leetcode.com/contest/weekly-contest-84/problems/find-and-replace-in-string/

TP。在字符串中进行多次互不影响的替换，先替换前面的，再替换后面的，用一个bias记录全局的偏移量。由于sources和targets中的字符串都要按照indexes中的index的顺序排序，使用map记录string到index的映射会有问题，因为key有可能存在重复。


214: Shortest Palindrome

https://leetcode.com/problems/shortest-palindrome/description/

TP。把原始串补成回文字符串的两个极限情况是：
1. 以第一个字符为中心，将后面的字符串补齐
2. 原始串就是回文串（中心是原始串的中点），不需要补齐
这样就可以分析出来原始串补齐之后形成的回文串的中点的位置范围，从原始串的中点开始，向左遍历找到第一个可以通过补全就能得到回文串的位置即可。


855: Exam Rooms

https://leetcode.com/contest/weekly-contest-89/problems/exam-room/

TP。 用set记录已经被占领的座位，由于set基于红黑树实现，可以对元素默认进行升序排序。每次有新的人要加入考场，遍历set，找相邻且距离最远的两个元素，第一个元素和最后一个元素单独考虑，因为他们只有一个边界，其余元素都有两个边界。

868: Binary Gap

https://leetcode.com/contest/weekly-contest-93/problems/binary-gap/

TP。找一个正整数`N`的二进制表示中，距离最远的两个`1`之间的距离。之间利用`bitset`将问题转化为TP问题。

689: Maximum Sum of 3 Non-Overlapping Subarrays

https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/description/

在数组中找出3个不重叠长度为K的连续子数组要求三个数组的和最大。BF解法，遍历三个子数组所有可能的起始位置，求和，O(KN^3)。
DP解法，使用前缀和记录sum，这应该视作解决连续序列问题的基本方法！三个internval的出现的位置是被限定的，middle的起始位置i处于[k, n - 2k]区间，当middle限定后，left的起点限定在[0, i - 1 - k]区间，right起点限定在[i + k, n - k]区间。从左向右使用缓存记录left的局部最大值，从右向左记录right的局部最大值，当middle的起点i从左向右移动时，只要知道[0, i - 1]区间left的最大值和[i + k, n - 1]区间上right的最大值即可。


535: Encode and Decode TinyURL

https://leetcode.com/problems/encode-and-decode-tinyurl/#/description
比较简单的一道题，但是就是没思路，好烦，做的题还是不够多，很多C++的STL操作都忘掉了，上周写了不少python之后，现在写C++老是忘记写；在不同的语言之间来回切换容易精神错乱！一刷没AC。


508: Most Frequent Subtree Sum

https://leetcode.com/problems/most-frequent-subtree-sum/#/description
不算难，现在衡量难与不难的标准是看了有没有思路。有思路但是花很长时间肉眼debug才A掉这个题。而且思路没有简化到极致。最大的那个count可以在遍历树的过程中找到，我是遍历完树之后再遍历map找的，map中的元素可以自动初始化，这种情况和python不一样，不用判断键是否存在！经过优化之后，代码非常简洁而且效率提高了一倍。一刷没有AC！二刷没有一次AC，注意iterator的操作不能使用<，只能使用!=和=。


1: Two Sum

https://leetcode.com/problems/two-sum/description/

* 方法一： Map。对于数组中的每一个元素$A_i$，使用multimap存储键值对$(target - A_i, i)$。再次遍历数组的每个元素$A_j$, 如果$A_j$是multimap的key且对应的value不等于$j$。因为题目的限制，multimap也可以用map代替。基于map的时间复杂度为$O(N)$。

* 方法二：TP。先拷贝数组$A$到$copy$中，sort $copy$，首尾指针$l$和$r$分别向中间移动使首尾指针指向的元素的和$sum$逐渐向$taret$靠拢。最后再$A$中分别查找$copy$数组的首尾指针$l$和$r$指向的元素在$A$中对应的元素。时间复杂度为$O(N\log{N})$。


15: 3Sum

https://leetcode.com/problems/3sum/description/

TP/MP。类似上题的**方法二**，先对数组排序，前向遍历数组先固定一个指针`i`，这样$sum$中的一个元素就有了，剩下的问题就是一个 **Two Sum**问题了。

注意去重，`i`,`l`,`r`三个指针都要去重。

16: 3Sum Closest

https://leetcode.com/problems/3sum-closest/?tab=Description

TP/MP。同15，先sort，然后逐个确定`i`,`l`,`r`三个指针，注意三个指针都要去重。**和15相同，去重的原则是计算过的组合不必继续计算，这种情况下解空间树仍然有很好的作用，非常清晰！**

18: 4Sum

https://leetcode.com/problems/4sum/?tab=Description

TP/MP。先进行sort，然后逐个确定i,j,l,r四个指针，注意去重和剪枝(非必须)。


454: 4Sum II

https://leetcode.com/problems/4sum-ii/#/description

TP/MP，HashMap。同上题，由于题目不需要找出符合条件的各个数的index，可以先遍历两个指针的结果并用HashMap存储，之后遍历另外两个指针并在HashMap中查找。这样一个$O(N_4)$的问题就降到了$O(N_2)$。

500: Keyboard Row

https://leetcode.com/problems/keyboard-row/#/description

HashMap。使用vector表示map，`tolower()`、`toupper()`、`isupper()`、 `islower()`和`isalpha()`这一系列处理char的函数都处于相同的命名空间。

451: Sort Characters By Frequency

https://leetcode.com/problems/sort-characters-by-frequency/#/description

HashMap。`Solution`类内部定义的`MyCompare`要用static关键字，因为在调用排序函数的时候编译器没有`Solution`类对象信息!map使用[]操作查询时，不存在的键会自动生成！而值会调用相应的默认构造函数！。


438: Find All Anagrams in a String

https://leetcode.com/problems/find-all-anagrams-in-a-string/#/description

没思路，一刷没AC，注意滑动窗口，这是个等大小的窗口，只是用vector而不是用map的算法效率不高。


380: Insert Delete GetRandom O(1)

https://leetcode.com/problems/insert-delete-getrandom-o1/#/description

一刷没AC，注意get_random的时候index不能为0！


274: H-Index

https://leetcode.com/problems/h-index/#/description

一刷没思路！注意vector和Hashmap的查找复杂度都是O(1)！开数组，多加一个元素用于存储引用数大于size的个数。


166: Fraction to Recurring Decimal

https://leetcode.com/problems/fraction-to-recurring-decimal/#/description

一刷没AC，磕磕碰碰，花了很长时间，但是最后肉眼debug成功了。再刷！ 注意极端情况如0，如负数，还有超出界限的问题。效率不高。
discuss区c++第一名的算法非常简洁，和我思路一样。


138: Copy List with Random Pointer

https://leetcode.com/problems/copy-list-with-random-pointer/#/description

HashMap。使用hashmap记录就链表节点到新链表节点的对照，然后按单链表的顺序复制即可。

133: Clone Graph

<https://leetcode.com/problems/clone-graph/description/>

graph的dfs, 注意图中可能有环，和138非常相似。

822: Card Flipping Game

https://leetcode.com/contest/weekly-contest-81/problems/card-flipping-game/

Hashmap。要求正面字符不能出现在反面，考察规律，出去正反面数字相同的牌，一定有一种方式，将所有相同数字全都排在正面。因此只要记录正反面相同的牌的数字，除去这些数字，找牌上出现的最小的数字即可。

94: Binary Tree Inorder Traversal

https://leetcode.com/problems/binary-tree-inorder-traversal/#/description

二叉树的前、中、后遍历的递归和非递归算法都要很熟悉。


49: Group Anagrams

https://leetcode.com/problems/anagrams/#/description

HashMap。`map`使用红黑树实现，而`unordered_map`基于hash table，使用hash型数据结构必须保证key的类型有`hash()`方法，容器类型除了string外默认是没有`hash()`方法的，而非hash型数据结构没有限制！c++中对于`map`和`unordered_map`，使用[]方法访问当key不存在时调用value的默认构造函数。


328: Odd Even Linked List

https://leetcode.com/problems/odd-even-linked-list/#/description
很简单的一道题，题意理解错误，正确理解题意后一次AC。


148: Sort List

https://leetcode.com/problems/sort-list/#/description

TP。双指针找到中点，递归排序再merge。


147: Insertion Sort List Add to List

<https://leetcode.com/problems/insertion-sort-list/#/description>

TP。使用dummy node作为新的头结点，将原链表的节点依次插入到新链表中。


143: Reorder List

https://leetcode.com/problems/reorder-list/#/description
TP。用快慢指针分离前段和后段链表，将后段倒置，之后将后段链表每个节点逐个插入到前段中。


19: Remove Nth Node From End of List

https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

TP，先将快指针定位到n + 1处，维持快慢指针的间隔，直到快指针到了fast处，将慢指针后面的节点删除。注意要使用dummy节点作为新的头结点。


26: Remove Duplicates from Sorted Array

https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

TP。


80: Remove Duplicates from Sorted Array II

https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

TP。同26。遍历元素，更新len。使用count记录重复个数，只有重复个数为1或2时更新len。


27: Remove Element
原地操作，删除数组中的固定值的元素。
TP。


142: Linked List Cycle II

https://leetcode.com/problems/linked-list-cycle-ii/#/description

链表成环检测。快慢指针，快指针每次走两步，慢指针每次走一步，如果两者相遇则有环。此时令快指针从头开始走，快慢指针一次走一步，知道两者相遇，相遇点就是环的起点。

数学解释：记链表起点`head1`到环的起点`head2`的距离为$l$，从环起点`head2`出发到快慢指针相遇点`P`至少要经过的距离为$x$，环长为$c$，则有一下推论:
$$l + x + mc = 2(l + x + nc) $$
$$l + x = kc$$
* 链表环相关问题：
  1. 是否有环（slow和fast是否相遇）
  2. 环长（相遇后以原方式继续走，到两者再次相遇（还是到碰撞点，可画函数图像），记录走过的距离即可）
  3. 环起点位置（相遇后slow从head开始，fast从碰撞点出发，一次走一步，相遇处就是连接点位置）
  4. 链表长度（基于2和3可得）
* 引申的链表相交问题：可以根据两个链表是否成环分为三类
    1. 两个都没环：判断两者最后一个节点是否相同
    2. 一个有环，一个没环，不可能相交
    3. 两个都有环，看一个链表的碰撞点是否在另一个链表的环内，因为若相交，环一定共享！

143: Reverse Linked List
链表头插法。


92: Reverse Linked List II

https://leetcode.com/problems/reverse-linked-list-ii/#/description

TP，头插法。分别用pre和end记录要翻转的部分的前一个节点和后一个节点，然后使用头插法即可。


25: Reverse Nodes in k-Group

https://leetcode.com/problems/reverse-nodes-in-k-group/description/

链表分组反转，头插法。使用`pre`和`cur`分别记录当前组和下一组的头结点，设置dummy node作为结果链表的起始，记录新链表的尾部，因为没插入一个新的组之后就要更新这个尾部，再进行头插法。


61: Rotate List

https://leetcode.com/problems/rotate-list/#/description

TP。注意要首先得出链表长度`len`，再将旋转次数对`len`取模，避免多余计算和可能的错误。指针先走`k%len`步，慢指针跟上，一直走到快指针走到尾节点，将尾节点链到头结点上，慢指针指向的节点就是新的头结点！


83: Remove Duplicates from Sorted List

https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

TP。用`pre`和`cur`两个指针，每次循环让`cur`走到`cur`和`cur->next`不等，`pre = cur，pre=cur->next, cur=cur->next`。


82: Remove Duplicates from Sorted List II

https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/#/description

TP。同83，记录`cur`的重复次数，只重复一次将`cur`添加到结果链表中，重复多次直接将`cur`跳过。


86: Partition List

https://leetcode.com/problems/partition-list/#/description

TP。设置两个dummy node对于两部分分别进行尾插法，形成两个链表然后接上。


523: Continuous Subarray Sum

https://leetcode.com/problems/continuous-subarray-sum/#/description

思路不是自己的，一刷没AC，因为变量写错CE，因为没考虑K会是负数而WA，还要再刷！


462: Minimum Moves to Equal Array Elements II

https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/#/description

这个问题中数列的平衡杆不一定就是均值，因为经过排序后两端每对数字移动的总距离和均值无关。当数字有偶数个时，以均值直接算作平衡杆正确；当数字有奇数个且中间那个数恰好为均值时，用均值作为平衡杆也正确；但是当中间那个数不是均值时，就应该用中间那个数作为平衡杆，亦即中间那个数不需要移动！
一次AC，但是思路不是自己的，还要再刷！


441: Arranging Coins

https://leetcode.com/problems/arranging-coins/#/description

很简单的数学问题，就是个一元二次方程求解的问题，我忘记用公式了。用了个O(logN)的方法，用公式一次一次开方就OK了。一次AC。


423: Reconstruct Original Digits from English

https://leetcode.com/problems/reconstruct-original-digits-from-english/#/description

比较简单的多元方程组的问题，一刷没AC，因为string和int的互换方法不清CE了，算法效率也不是很高。


415: Add Strings

https://leetcode.com/problems/add-strings/#/description

很简单，看了就有思路，一次AC。算法效率好像不太行。


400: Nth Digit

https://leetcode.com/problems/nth-digit/#/description

思路不是自己的。一刷没AC，因为base设为int类型越界导致WA。再刷！


413: Arithmetic Slices

https://leetcode.com/problems/arithmetic-slices/#/description

比较简单，一刷没有AC，不用设置两个begin和end两个变量，只需一个middle就可以了，注意middle从1到A.size() - 2，因为这个WA。因为==写成=CE。


372: Super Pow

https://leetcode.com/problems/super-pow/#/description

思路不是自己的，一刷AC，还要再刷！递归设计的很好！


368: Largest Divisible Subset

https://leetcode.com/problems/largest-divisible-subset/#/description

思路不好，有漏洞，看了讨论区的C++算法，一刷没AC。因为开始没对数组没排序得了WA。对大神的思路理解的不够深入，再刷！！


367: Valid Perfect Square

https://leetcode.com/problems/valid-perfect-square/#/description

一道简单的二分查找，一刷没有AC。注意一个公式1 + 3 + 5 + 7 + 9 + …… = n^2!因为mid设为int，结果溢出得了WA。


365: Water and Jug Problem

https://leetcode.com/problems/water-and-jug-problem/#/description

巨硬笔试题，数论问题，挺难的！证明还挺复杂……。最大公约数GCD和最小公倍数LCM还不太会弄！一刷一次AC。但是思路理解起来还是挺费劲的！再刷！


343: Integer Break

https://leetcode.com/problems/integer-break/#/description

一道规律题，一刷没有AC，以为大于号写成小于号得了WA，需要用导数来推导，果然是数学题！再刷！


319: Bulb Switcher

https://leetcode.com/problems/bulb-switcher/#/description

规律题，发现了一部分规律，但是没有继续深入，发现的规律还比较浅层。一刷一次AC。


69: Sqrt(x)

https://leetcode.com/problems/sqrtx/#/description

BS。注意0和mid * mid == x的情况。需要求更精确的平方根时可以用Newton法。

Newton法：求$x$的平方根即求$f(t) = t^2 - x$的根，根据牛顿法的思想，在二次方程中，通过迭代切线根会逐渐收敛到曲线根，初始化$t_n = 1.0$，不断地通过$t_{n+1}=t_n - \frac{f(t_n)}{f'(t_n)}$迭代，直到$|t_n - t_{n+1}| <= \epsilon$即可。更细节的推理可以参考[该知乎问题的答案](https://www.zhihu.com/question/20690553)。

313: Super Ugly Number

https://leetcode.com/problems/super-ugly-number/#/description

比较复杂，我有个思路，但是没有想到怎么实现。看了讨论区算法才搞明白，思路不是自己的，一次AC，还要再刷！


279: Perfect Squares

https://leetcode.com/problems/perfect-squares/#/description
没思路，讨论区使用的是DP算法，还有一种数学算法，不太懂，放弃了！一刷没有AC，变量没有定义拿了CE！再刷！


264: Ugly Number II

https://leetcode.com/problems/ugly-number-ii/#/description
和313题很像，我也是用的313题的方法，效率还不错，一刷AC。


50: Pow(x, n)

https://leetcode.com/problems/powx-n/#/description

位操作。直接视为进制题型，指数视为二进制表示，每位的权重是前一位权重的平方。末位的权重为x，从后向前依次遍历指数的每一位即可。注意先将负数转为整数，负指数转我正指数。


60: Permutation Sequence

<https://leetcode.com/problems/permutation-sequence/#/description>

Math。$N$个数字的所有排列方式为$N!$种，在由前到后确定每一位上的数字的过程中，单位不同，根据单位和当前剩余的`k`决定填充哪个数字，并用`set`记录已经使用过的数字。


43: Multiply Strings

https://leetcode.com/problems/multiply-strings/#/description

math。大数乘法，给定两个大数$a,b$(字符串表示)，求$c=a*b$。

设$a,b$的长度为别为$n_1,n_2$，则$c$的长度最大为$n_1+n_2$。由低位到高位计算$c$的任意一位$c_k$，对于每一个满足`i+j == k`的有序对`{i,j}`计算$p_{ij}=a_i * b_j$并求和，加上计算$c_{k-1}$产生的进位$carrier_k$对10取模即可，即$c_k=(\sum_{i=0}^{k}{a_i * b_{k-i}} + carrier_k) \% 10$, 且$carrier_{k+1}=(\sum_{i=0}^{k}{a_i * b_{k-i}} + carrier_k) / 10$。初始化$c$长度为$n_1+n_2$的全零字符串，计算结束之后将高位的0抹去，当结果为0要补个0。


29: Divide Two Integers

https://leetcode.com/problems/divide-two-integers/#/description

Bit，math。给定32位整数$a,b$的除法，求$a/b$，要求不能用乘法运算。

视为求商的二进制表示。每次循环寻找除$a$商大于0的最大的$b*2^i$，减掉这部分。重复上述步骤直到$a<b$。时间复杂度$O(\log{N})$。


12: Integer to Roman

https://leetcode.com/problems/integer-to-roman/#/description

HashMap,Math。自己建立map，将阿拉伯数字与罗马数字字符串对应起来。

13: Roman to Integer

https://leetcode.com/problems/roman-to-integer/description/

HashMap,Math。上题的逆过程，扫一遍字符串，如果当前字符比后一个字符的权值大，做减法，否则做加法。

567: Permutation in String

https://leetcode.com/problems/permutation-in-string/#/description

滑动窗口，TP。

532: K-diff Pairs in an Array

<https://leetcode.com/problems/k-diff-pairs-in-an-array/#/description>

很简单，没有一次AC，再刷！

524: Longest Word in Dictionary through Deleting

https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/#/description

思路不是自己的。一刷因为多个变量在同一行中定义写法出错拿个CE！对于pj的增长方式还是没办法提出比较容易理解的模型。再刷！！

3: Longest Substring Without Repeating Characters

<https://leetcode.com/problems/longest-substring-without-repeating-characters/#/description>

滑动窗口，TP。使用一个长为256的`vector`记录每个`char`上次出现的位置，用`start`记录当前无重复字符子串的起始位置，窗口右侧遇到一个已经访问过的`char`，窗口左侧`start`移到该`char`上次出现位置的后一位。

209: Minimum Size Subarray Sum

<https://leetcode.com/problems/minimum-size-subarray-sum/>

TP，滑动窗口。同第3题思路相同，用`i,j`分别记录当前subarray的和与起、止位置，用`sum`记录subarray的和，当`sum >= s`时尽量左移`i`，左移结束更新`ans`。

557: Reverse Words in a String III

https://leetcode.com/problems/reverse-words-in-a-string-iii/#/description

TP。字符串内部单词反转。

用`b`和`e`分别记录每个单词的起始字符的index和末尾字符的下一个index，然后用`reverse(s.begin()+b, s.begin()+e)`反转单词即可。


520: Detect Capital

https://leetcode.com/problems/detect-capital/#/description
一次AC。注意判断逻辑顺序。


541: Reverse String II

https://leetcode.com/problems/reverse-string-ii/#/description
一刷AC。


434: Number of Segments in a String Add to List

https://leetcode.com/problems/number-of-segments-in-a-string/#/description
一刷临界情况没写准，没AC。


551: Student Attendance Record I

https://leetcode.com/problems/student-attendance-record-i/#/description
一刷AC。


459: Repeated Substring Pattern

https://leetcode.com/problems/repeated-substring-pattern/#/description
不难，但是我的解法时间复杂度比较高，一刷没AC.解答区有时间复杂度为O(N)的DP算法。


521: Longest Uncommon Subsequence I

https://leetcode.com/problems/longest-uncommon-subsequence-i/#/description
一行完事，但是很绕！再刷！


5: Longest Palindromic Substring

https://leetcode.com/problems/longest-palindromic-substring/#/description

DP，TP。查找字符串中的最长回文子串。

* DP方法：使用DP判断每个子串是否为回文串，若子串为回文串且长度大于已知最长回文子串的长度，则更新最长回文子串的起止点，时间复杂度和空间复杂度均为$O(N^2)$
* TP：遍历每个字符，沿两侧展开，更新起始点和最大长度，时间复杂度为$O(N^2)$，空间复杂度为$O(1)$。


9: Palindrome Number

https://leetcode.com/problems/palindrome-number/description/

TP或者看逆数与原数是否相等，注意本题中负数不合法。


385: Mini Parser

https://leetcode.com/problems/mini-parser/#/description

不算简单，用到istringstream，不好理解！子函数对流修改后，父函数要clear()才能得到正确的指针！一刷AC但是不太理解递归，再刷！


6: ZigZag Conversion

https://leetcode.com/problems/zigzag-conversion/#/description

比较简单，一刷没AC，没有认真考虑边界条件。numRows为0直接返回原串即可。


556: Next Greater Element III

https://leetcode.com/problems/next-greater-element-iii/#/description

不难，但是忘记怎么求下一个排列的算法了。标准库有api可以用！再刷！

7: Basic Calculator II

https://leetcode.com/problems/basic-calculator-ii/#/description

istringstream非常好用，可以从中直接读取任意数据类型，读取字符串直接用getline操作。注意用op来对term进行正负修饰，只有第一次读入加号或者减号的时候需要。一刷没思路，二刷term的正负没写对位置。

224: Basic Calculator

https://leetcode.com/problems/basic-calculator/description/

和227相似，稍难主要是括号的处理。使用signs的栈存储当前括号计算结果应该乘上的符号，sign只存储一个数字的符号。上题适合使用stringstream，本题不适合使用stringstream。


17: Letter Combinations of a Phone Number Add to List

https://leetcode.com/problems/letter-combinations-of-a-phone-number/#/description

BFS，DFS。我更喜欢用bfs.


336: Palindrome Pairs

https://leetcode.com/problems/palindrome-pairs/#/description

想有个好点的算法比较难，还不太理解讨论区大神的算法，一刷没AC。忘记边界拿了WA，再刷！


539: Minimum Time Difference

https://leetcode.com/problems/minimum-time-difference/#/description

一刷没AC，一开始没看懂题意导致WA。看了解答区的算法手写各种CE！再刷！

583: Delete Operation for Two Strings Add to List

https://leetcode.com/problems/delete-operation-for-two-strings/#/description
一刷没有AC，min函数只能比较两个数，编译错误。DP算法不太懂，再刷！！二刷没有一次AC，j初始化错误。没完全理解算法，再刷！自己手动运行了几遍代码，终于搞懂了。dp的元素矩阵表示应该删除的字符个数，最外围那一行和列表示一个串为子串，而另外一个串为空串！但是没动手再刷一次！再刷！三刷一次AC。


468: Validate IP Address

https://leetcode.com/problems/validate-ip-address/#/description

一刷没AC，getline在这个题目中有妙用！题目不难，但是边界条件非常多！坑很多！再刷！

811: Subdomain Visit Count

string，map。使用istringstream和getline对字符串进行处理，用map进行存储。


522: Longest Uncommon Subsequence II

https://leetcode.com/problems/longest-uncommon-subsequence-ii/#/description
思路不是自己的，一刷废了很大劲没AC。用了两种方法，直接构造带有cmp函数的map失效，还没弄明白原因！再刷！


20: Valid Parentheses

https://leetcode.com/problems/valid-parentheses/description/

stack。判断各种括号的组合是否合法，用栈。遍历字符串，遇左括号入栈，遇右括号如果栈顶为对应的左括号则出栈，否则该括号串非法。遍历结束如果栈空则合法，否则非法。


71: Simplify Path

<https://leetcode.com/problems/simplify-path/#/description>

stack。用`vector`代替`stack`更简单，`stringstream`要用熟，`getline(in_stream, buffer, char)`的第三个参数表示分隔符。最后结果中多出来的一个`"/"`要去掉。

844: Backspace String Compare

<https://leetcode.com/contest/weekly-contest-87/problems/backspace-string-compare/>

stack。使用将string转为stack，遇到'#'且栈非空则删除栈顶元素，否则将字符压入栈中。


93: Restore IP Addresses

https://leetcode.com/problems/restore-ip-addresses/#/description

DFS。count记录ip段数，start记录起始位，path记录当前解析的结果。


22: Generate Parentheses

https://leetcode.com/problems/generate-parentheses/#/description

dfs。左括号只要有剩余就可以选，右括号只有在已生成的串中左括号多于右括号才可以选。


475: Heaters

https://leetcode.com/problems/heaters/#/description

比较简单，但是没有好的思路。一刷没有一次AC，而是各种CE！再刷！从解答区选择的思路也不是最好的！二刷没有一次AC，不太懂upper_bound和lower_bound的区别拿了WA，再刷！三刷一次AC。


436: Find Right Interval

https://leetcode.com/problems/find-right-interval/#/description
比较简单，很久没刷，手很生，一刷没AC，各种CE，WA和RE，思路是对的，但是时间复杂度太高。解答区的算法很好，值得借鉴，但是思路不是自己的，再刷！


275: H-Index II

https://leetcode.com/problems/h-index-ii/#/description
是274的附加题。题意很难懂，真的很难懂！很久没刷，找找感觉先！一刷各种错误，有CE也有WA，再刷！


378: Kth Smallest Element in a Sorted Matrix

https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/

不算难，但是要找到二分查找中间的判定条件比较困难！看了一遍大神解法之后，一刷AC，但是对算法了解其实没那么深，尤其是如何将一个不在matrix中的值逼近到在matrix中的值。二刷对算法理解更透彻一些，对运算优先级把握不准，得了WA。再刷！


392: Is Subsequence

https://leetcode.com/problems/is-subsequence/description/

不难，一刷AC,O(N)复杂度。Follow up需要二分查找，discuss区有java代码可以研究一下！以后刷可以直接看follow up！


658: Find K Closest Elements

https://leetcode.com/problems/find-k-closest-elements/description/

不太难，一刷没AC，思路大致正确但是实现有些细节错误！对lower_bound和upper_bound理解不太对，导致WA。lower_bound得到第一个不小于val的元素的迭代器，而upper_bound得到第一个大于val的元素的迭代器。判断条件有精妙，没能完全理解。二刷代码不需要写，试着解释了一个问题就是为什么要去掉low，保留high，因为low是有问题的，相当于数轴上的空心点！一定是high离得近，所以最后舍弃了low！注意考虑边界问题，感觉现在有种做高中物理题的节奏了！再刷！！


671: Second Minimum Node In a Binary Tree
https://leetcode.com/contest/leetcode-weekly-contest-48/problems/second-minimum-node-in-a-binary-tree/

不算难，是数组求第N大元素的变形，只是使用的数据结构变了，核心算法思想没变，不难，递归解决，但是花了很长时间！


669: Trim a Binary Search Tree
https://leetcode.com/contest/leetcode-weekly-contest-48/problems/trim-a-binary-search-tree/

不难，简单的递归题。怪自己总是把问题忘难了想。


670: Maximum Swap
https://leetcode.com/contest/leetcode-weekly-contest-48/problems/maximum-swap/

不难，但是我的方法不太好，应该有很好很简单的方法，可以专门研究一下discuss区的好方法！


672: Bulb Switcher II
https://leetcode.com/contest/leetcode-weekly-contest-48/problems/bulb-switcher-ii/

一道规律题，挺难的，没思路，也没有发现规律，讨论区算法很简单，但是不是很理解！需要再理解一下！


222: Count Complete Tree Nodes

https://leetcode.com/problems/count-complete-tree-nodes/description/

很快有思路，但是折腾了2小时，遇到各种错误，而且算法效率非常低！再刷！但是通过这道题更深的理解了二分查找算法。判断条件是更新high还是low只跟mid的计算方式有关，无论什么时候，区间一定要包含答案，这是原则！按照我的书写习惯，low不会比high大，终止情况是low = high = mid！

看了discuss区的算法，就是简单的递归，竟然在效率上打败了50%的算法！！惊呆了！


230: Kth Smallest Element in a BST

https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

一刷计算比mid值小的节点个数时逻辑出错，得了WA，再刷！用VS在本地debug就是方便，终于不用自己写很多cout了，而且快了很多！算法效率不高，follow up没看，后面再刷要注意这两个问题！二刷使用非递归的基于树的中序遍历的方法一次AC，效率高出很多，再刷一次，深入理解BST的中序遍历过程，尤其是非递归方法。


401: Binary Watch

https://leetcode.com/problems/binary-watch/description/

一刷没好的思路，看了discuss区之后，发现真的是直接遍历解空间！由于不理解表的的实际运行换算进制搞错得了WA，再刷！


113: Path Sum II

<https://leetcode.com/problems/path-sum-ii/description/>

dfs。遍历解空间，收集合法解。不用去重，比较简单。


124: Binary Tree Maximum Path Sum

https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

dfs。递归函数`f`返回包括根节点`root`在内的单侧路径最大值。在函数体内分别对左子树和右子树调用`f`分别得到左子树上的带根单侧路径最大值`left`和右子树上的带根单侧路径最大值`right`，拿`right + left + root->val`和用于存储全局解的`res`相比，更新`res`，返回`max(left, right) + root->val`。


46: Permutations

https://leetcode.com/problems/permutations/description/

dfs。面试趋势是这种题目变为解决问题其中的一步。


47: Permutations II

https://leetcode.com/problems/permutations-ii/description/

DFS。比46难一点，把解空间画出来会发现其实都是一样的，因为每个问题的子问题规模（分支个数）完全相同，递归深度因为有了重复元素会增大。`map`可以去重，还可以统计频率，`map`的key的个数就是分支数的上线。46中的`visited`的功能在本题中被`map`代替了。


77: Combinations

https://leetcode.com/problems/combinations/description/

dfs。

39: Combination Sum

<https://leetcode.com/problems/combination-sum/?tab=Description>

dfs。可以画出解空间来理解解题过程。


40: Combination Sum II

<https://leetcode.com/problems/combination-sum-ii/?tab=Description>

DFS。首先要排序（对于去重很重要），之后要对照解空间写递归过程。


216: Combination Sum III

https://leetcode.com/problems/combination-sum-iii/

DFS。解空间树画出来就有了。


377: Combination Sum IV

https://leetcode.com/problems/combination-sum-iv/description/

DFS，DP。top-down的DFS超时，加入memo实现DP后，AC。这个题很经典，和之前整理的回溯法有强关联！注意理解DP的含义，我现在仍然不知道这样做是不是就叫做DP。

除了上一种top-down的DP方法，还有一种bottom-up的DP方法，这种方法在我看来更像DP。

两种方法的空间复杂度都是O(N)，时间复杂度均为O(MN)，top-down方法虽然使用递归，但是这个时间复杂度容易分析。


78: Subsets

https://leetcode.com/problems/subsets/

dfs。


90: Subsets II

https://leetcode.com/problems/subsets-ii/description/

dfs，先排序，对着解空间写递归，注意去重。

51: N-Queens

<https://leetcode.com/problems/n-queens/description/>

DFS。让$col$递增，逐个选择合法的$row$，存储$path$，$path$的含义是$(path[i], i)$位置可以放一个Queen，之后将合法$path$转为棋局排列。DFS的解空间是一个N叉树，第$j$层表示第$j$列的可能情况，第$j$层的每个节点的n个分支表示该列的Queen可能处于的行号，遍历解空间的时间复杂度为$O(N^2)$，由于需要判断冲突，所以总的时间复杂度为$O(N^3)$。

判断冲突有三个条件：
1. $row_1 \neq row_2$，两个Queen不在同一行
2. $row_1 + col_1 \neq row_2 + col_2$，两个Queen不在一个斜对角线上
3. $row_1 - col_1 \neq row_2 - col_2$，两个Queen不在一个正对角线上

52: N-Queens II

<https://leetcode.com/problems/n-queens-ii/description/>

dfs，思路与上题完全相同。


131: Palindrome Partitioning

https://leetcode.com/problems/palindrome-partitioning/description/

DP,DFS。先用dp计算任意子串是否为回文，再使用dfs收集合法的partition。

132: Palindrome Partitioning II

https://leetcode.com/problems/palindrome-partitioning-ii/description/

DP。找出将字符串$s$分割为多个palindrome子串的最小的切割次数。

用二维数组$f$记录子串$s[i,j]$是否为palindrome，用一维数组$h$记录子串$s[0,j]$的最小分割。
* 判断palindrome与上题无异
* 若$f[i][j]$`== true`，$h[j] = min (1 + h[i-1], h[j])$。
* 判断palindrome可以先遍历$j$再遍历$i$，两层循环即可。


79: Word Search

https://leetcode.com/problems/word-search/description/

dfs。和maze那道题对比，本题需要回溯，原因是本题中解空间中两个分支同时经过运动空间的一个节点时，表示的含义不同，两个分支很有可能是两个不同的单词（也有可能是一个单词，只是路径不同），因此当第二个分支经过运动空间中的这个节点时，后续状态仍然需要遍历！而maze那道题不需要，因为后续状态一定走不通，结果是必然的！而且回溯不会造成死循环，回溯只是为了确保解空间的完整性！


89: Gray Code

https://leetcode.com/problems/gray-code/description/

Math。从0开始，不断从起始位或者终止位补0和1(从起始位补的话不必补0，更简洁)，当时从终止位补0或1出错，不知道为啥。


674: Longest Continuous Increasing Subsequence My SubmissionsBack to Contest

https://leetcode.com/contest/leetcode-weekly-contest-49/problems/longest-continuous-increasing-subsequence/

比较简单，但是这种题我是比较害怕的！还要继续总结！多总结！这才是进步的捷径！

673: Number of Longest Increasing Subsequence

https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/

LIS，跟上一题很像！怪不得邓邓把上一道题看成这道题！DP难在算法的理解。看了半天没理解，看了大神的注释之后豁然开朗！一刷AC，但是理解不够，再刷！二刷DEBUG了很久，还是理解不够，心不在焉漏洞百出！再刷！


354: Russian Doll Envelopes

https://leetcode.com/problems/russian-doll-envelopes/

LIS的变种，将二维数据其中一个维度升序另一个维度降序排序之后只关注降序排序的维度就是LIS。这个题很有意思，很有思考价值！


676: Implement Magic Dictionary
https://leetcode.com/contest/leetcode-weekly-contest-49/problems/implement-magic-dictionary/

一开始想用set或者vector实现，发现效率太低，就改为用字典树实现，字典树实现太难调试了！之后使用set实现，舒服多了！


675: Cut Off Trees for Golf Event

https://leetcode.com/contest/leetcode-weekly-contest-49/problems/cut-off-trees-for-golf-event/

不太难的一道BFS的题目，但是非常繁琐！DEBUG了非常长的时间！对于树而言BFS就是层序遍历，DFS就是后续遍历！代码我到最后都不知道为什么AC了！这份代码非常经典，要拿出来再刷，再总结！


198: House Robber

https://leetcode.com/problems/house-robber/description/

比较简单，DP一刷AC。时间复杂度和空间复杂度都是O(N)，可以将空间复杂度降至O(1)。二刷使用时间复杂度O(N)，空间复杂度为O(1)的DP算法，一次AC。


213: House Robber II

https://leetcode.com/problems/house-robber-ii/description/

一刷没思路，使用大神的DP思路没有对nums的长度为1时的场景进行判断，WA。关键是将该题转化到上面一题。再刷的时候注意理解，思考留出一个house不rob从而破环的合理性。


96: Unique Binary Search Trees

<https://leetcode.com/problems/unique-binary-search-trees/description/>

DP。

* 初始化: $dp[0] = 1, dp[1] = 1$。
* 递推关系: $dp[i] = \sum_{j=1}^i (dp[j-1] * dp[i-j])$

将1到n分别作为根，左右两侧一个规模更小的子问题，左右两侧结果相乘就是一种情况，枚举所有情况求和即可。

这道题和矩阵相乘的那道题很类似，都是从序列中间取一个元素，分割序列将问题转化为规模更小的子问题，同时分割元素可以是序列中的任意一个元素，这类的递推函数很常见。DP问题的解不仅可以由一个小规模子问题的解得到，还可以由多个甚至所有小规模子问题的解的组合得到。

95: Unique Binary Search Trees II

<https://leetcode.com/problems/unique-binary-search-trees-ii/description/>

BFS，DFS。
* BFS：从1到n，逐渐扩充res，然后遍历上一个节点加入后的res列表，在每棵树上添加新的节点（每个可能的右子树），时间复杂度$O(N^2\log N)$~$O(N^3 \log N)$。
* DFS：递归函数`f`返回由区间$[begin, end]$中所有整数生成的所有BST的列表。`f`内部对$\forall$`i`$\in[begin, end]$，选其为根，对区间$[begin, i-1]$调用`f`生成所有左子树`left`，对区间$[i+1, end]$调用`f`生成所有右子树`right`，然后按照96的思路将所有左、右子树的组合就是结果。

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
		* `s[i-1] == ')'`: 此时如果`s[i - dp[i-1] - 1]`（`'('`）和`s[i]`（`')'`）刚好可以将以`s[i-1]`结尾长度为`dp[i-1]`的合法子串包住，则有`dp[i] = dp[i-dp[i-1]-2] + dp[i-1]+2`。**注意：这种情况下，新的合法子串不仅包括被包住的合法子串，还包括被包住的合法子串之前的能够和新包住的合法子串拼接成更长的合法子串的部分**。
* stack: 栈中保存的是上一个非法字符的index，初始化栈顶为`-1`。
* TP：先后进行两次遍历，正向一次，反向一次，并用`left`记录当前有可能合法的子串中左括号`'('`的个数，用`right`记录当前有可能合法的子串中右括号`')'`的个数，用`result`记录全局的解。
	* 正向遍历会出现三种情况
		1. `left > right`：说明子串有可能合法的，因为后面可能会出现一些`')'`与前面多出的`'('`配对
		2. `left < right`：说明当前子串一定不合法，此时两个变量全部归零；
		3. `left == right`： 说明当前子串完全合法，此时应该更新`result`。
	* 反向遍历也会出现类似的三种情况：
		1. `left < right`：说明子串有可能合法的，因为前方可能会出现一些`'('`与后面多出的`')'`配对
		2. `left > right`：说明当前子串一定不合法，此时两个变量全部归零；
		3. `left == right`： 说明当前子串完全合法，此时应该更新`result`。
	* 一次遍历无法解决问题的原因：举个例子，当输入字符串为`((())`时，前向遍历得到的结果是0，因为最前面的那个`(`在后续遍历过程中一直无法找到可以与之配对的`')'`，而`left > right`始终成立。正向遍历优先匹配`'('`，而反向遍历优先遍历`')'`，这两种情况是互斥的，而且只有这两种元素，因此双向遍历是有效的。

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
	
	* 当前字符`buffer[i]`已经被包含在曾经被判断过的回文串内（即`max_pos>i`)，那么它在这个回文串中相对应的那个字符`buffer[2*ID-i]`，应当已经被计算过以它为中心的回文串可以有多长了。那么以`buffer[i]`为中心的回文串长度，就有了第一个下限`max_len[2*ID-i]`（运用回文串的对称性）。另外以`buffer[2*ID-i]`为中心的回文串，它可能延展到了以`buffer[ID]`为中心的回文串之外。这样我们就不能保证以`buffer[i]`为中心的回文串包括了以`buffer[ID]`为中心的回文串之外的部分，于是我们得到了第二个下限：`max_pos-i`。综上，在`max_pos>i`时，我们就得到了`max_len[i]=min(max_len[2*ID-i],max_pos-i)`。这时我们只得到了一个可怜的下限，因此我们要在这个下限的基础上继续向外扩展。最后更新`max_pos`和`ID`。
	
	* 算法复杂度分析：考虑当前字符`buffer[i]`，我们可以分为三种情况:
		1. `max_len[i]=1`，说明`max_pos`没有覆盖超过`buffer[i]`，那么`max_pos`在这一步后一定会增加。
		2. `max_len[i]=max_pos-i`，说明以`buffer[i]`为中心的回文串至少到达了`max_pos`，那么`max_pos`在这之后不会减少。
		3. `max_len[i]=max_len[ID*2-i]`，说明可怜的以`buffer[i]`为中心的回文子串最长只有这么长，已经匹配不出去了。
	
		Mx的値是单调的，并且始终不会超过字符串长度Len，那么对于所有的`i`，**1**、**2**两种种情况的执行时间总和不会超过`Len`。因此总时间复杂度依旧是O(n)。

416: Partition Equal Subset Sum

<https://leetcode.com/problems/partition-equal-subset-sum/description/>

一刷没AC，使用时间复杂度为O(N!)的backtracing算法，出现很多CE！最后TLE。也有人说时间复杂度为O(pow(2, N))的！这是个典型的0/1背包问题，0/1背包问题的特点是从一组数中选取某些数达到一定的值。对0/1背包问题的一个很好的解释在下面的链接中：

https://discuss.leetcode.com/topic/67539/0-1-knapsack-detailed-explanation

这一题使用的DP解法对标准0/1背包算法进行了优化，因为题目不需要知道更多的信息，数组开一维就可以。数组开二维也可以，但是比较麻烦，需要更多的初始化，操作！

最优化方法是使用bitset的方法，时间复杂度为O(N)，空间复杂度为O(1)!


139: Word Break

<https://leetcode.com/problems/word-break/description/>

DP。将$s[0, j]$分成两部分$s[0, i]$和$s[i+1, j]$，如果`dp[i] == true`且$s[i+1, j]$是字典中的词，则`DP[j] == true`。可以令`i`从`j-1`遍历到`0`，只要发现符合上述情况的`i`就跳出循环，处理下一个`j`。时间复杂度$O(N^2)$，空间复杂度$O(N)$。


140: Word Break II

<https://leetcode.com/problems/word-break-ii/description/>

DFS。dfs+memo，因为要把所有可能的结果都保存下来，加入memo效率更高。dfs照例可以画解空间树来做，递归函数`f`返回当前字符串的所有可能的分离结果`res`，在`f`的函数体内，由后向前找出所有字典里出现的单词`word`，对剩下的部分调用`f`得到子串的分离结果`children`，对于`children`中的每一个字符串`child`在后面拼接上`word`就是`res`的一个元素。
$\forall i, s[i+1,j]\in word\_dict$, $f(s[0, j]) = f(s[0, i]) + s[i + 1, j]$


135: Candy

<https://leetcode.com/problems/candy/description/>

BFS，DP。

* BFS：将问题转化为拓扑排序，O(N^2)的复杂度，超时。
* DP：先从左向右扫描数组，与左侧元素比较更新DP，之后反向扫描数组，根据元素与右侧元素的关系修改DP。时、空间复杂度均为$O(N)$。


845: Longest Mountain in Array

https://leetcode.com/contest/weekly-contest-87/problems/longest-mountain-in-array/

DP。分别使用前向和后向DP记录左侧和右侧能与该元素形成单调递严格减的序列的长度，正向遍历填充前向DP，逆向遍历填充后向DP，最后结合两个DP结果给出答案。


464: Can I Win

https://leetcode.com/problems/can-i-win/description/

自己没思路，大神思路不太理解。时间复杂度为（dfs导致递归，时间复杂度不会分析），空间复杂度为O(2^N)。一刷dfs的循环次数写错WA。再刷！


467: Unique Substrings in Wraparound String

https://leetcode.com/problems/unique-substrings-in-wraparound-string/description/

大神思路理解不透彻，时间复杂度O(N)，空间复杂度O(1)。一刷理解大神思路的基础上自己实现一次AC。再刷一次！但是这个解法真的是DP吗？

97: Interleaving String

https://leetcode.com/problems/interleaving-string/description/

DP。二维DP，`dp[i][j]`表示`s1`的子串$s1[0, i]$和`s2`的子串$s2[0,j]$是否可以组合成`s3`的子串$s3[0, i+j]$。由于`s1`和`s2`组合为`s3`时，来自`s1`和`s2`的字符在源串中的相互顺序不变，因此`dp[i][j] == true`有两种情况：
1. `s3[i+j]`来自`s1`：即`s3[i+j] == s1[i]`，此时还要有`dp[i-1][j] == true`
2. `s3[i+j]`来自`s2`：即`s3[i+j] == s2[j]`，此时还要有`dp[i][j-1] == true`


221: Maximal Square

https://leetcode.com/problems/maximal-square/description/

一刷AC，自己的思路和大神的思路相似，我的思路不够简洁，大神使用square的边长表示square。二刷初始化参数写错，RE。
状态方程的理解：(i, j)是square,则(i-1, j-1), (i-1, j),(i, j-1)必定是size的square！如果三者的size不同，则(i, j)取三者最小的加1。时间复杂度和空间复杂度都是O(M*N)。


576: Out of Boundary Paths

https://leetcode.com/problems/out-of-boundary-paths/description/

一刷按照自己的思路初始时没判断参数有可能的异常，RE。思路正确，效率不高，时间复杂度和空间复杂度均为O(N*n*m)。再刷！二刷使用大神的高效解法。


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

一刷没思路，大神总结了从暴力递归到简化版DP的四种方法，一刷使用暴力递归发现TLE。二刷使用带memo的递归，由于递归深度与字符串长度相同，字符串过长导致栈空间溢出得到MLE。三刷使用DP,一次AC。空间复杂度为O(N^2)，时间复杂度为O(N^2)。四刷使用更高效的DP，一次AC，时间复杂度为O(N^2)，空间复杂度为O(N)。不用再刷，但是可以回顾，这个题目很经典。

暴力递归导致重复计算，于是有了带memo的递归。而随着递归深度增大，栈空间消耗过大，于是有了DP。递归是top-down的思路，而DP则是bottom-up的思路。这道题的关键的状态方程不易理解，需要举个例子，如“bbbab”, 状态方程为("bbbab") = 'b' == 'b' ? 2 + ("bba") ? max("bbba", "bbab")。可以清楚看到"bba"三者都有，而后面两个最大只是("bba") + 1。


322: Coin Change

<https://leetcode.com/problems/coin-change/description/>

DFS，BFS，DP。

* DFS：不能进行贪心剪枝，使用贪心剪枝并不一定得到最优解！如([10, 25, 30], 50)这个反例，
* BFS：因为问题要找最短的解，这相当于提示用BFS，但是BFS会导致MLE。
* DP：对$\forall$`i`$\in[0, amount]$，$DP[i] = \sum_k {DP[i - coins_k]}，i \geq coins_k$。

DP问题首先看问题能否降为子问题，如果能将原始问题分解为两个或更多规模更小的子问题，那就很可能用Buttom-up的DP方法，这里面寻找最优子结构是最难的。一般面试能碰到的DP可以分为几类:
* 一维DP：如LCS、本题，
* 二维DP，`i`和`j`的含义相同：代表的是找回文子串(不用曼彻斯特算法的情况)
* 二维DP，`i`和`j`表示的含义不同：代表是0-1背包问题

518: Coin Change 2

<https://leetcode.com/problems/coin-change-2/description/>

DP。与上题不同的是要去重，这里计算的是目标组合的个数。相比于这题，Climbing Stairs相比，这里因为计算的是合法组合数，去重更困难。思路是先控制使用的coin的面值，逐个加入新面值，改变组合数。


740: Delete and Earn

<https://leetcode.com/contest/weekly-contest-61/problems/delete-and-earn/>

DP，可以降为子问题，典型的0-1背包问题。要继续思考，细嚼慢咽还是很有收获的。


115: Distinct Subsequences

<https://leetcode.com/problems/distinct-subsequences/description/>

DP。二维DP，`dp[i][j]`表示$S$的子串$S[0,i-1]$中包含$T$的子串$T[0,j-1]$这样的子序列的个数。$T[0,0]$表示空串，初始化令$\forall i \in[0, S.size()]$，`dp[i][0]=1`表示$S$的任意子串都包含一个空的子序列。后面分为两种情况：
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

491: Increasing Subsequences

https://leetcode.com/problems/increasing-subsequences/description/

dfs，有点小trick，去重时要遍历之前的所有元素，查看是否有重复，因为题目不允许sort。


304: Range Sum Query 2D - Immutable

https://leetcode.com/problems/range-sum-query-2d-immutable/description/

一刷没有对二维数组的维度进行初始判断，没AC。使用DP，时间复杂度和空间复杂度均为O(M*N)，效率不高，二刷关键是调研更优秀的解法。


474: Ones and Zeroes

https://leetcode.com/problems/ones-and-zeroes/description/

一刷使用暴力DFS，TLE。bitset的使用得到了锻炼，bitset使用set和reset进行赋值，使用test测试位，使用count度量位。二刷使用DP，出了bug，没调通。三刷使用大神的空间复杂度O(M*N)，时间复杂度O(M*N*L)的DP算法，一次AC。大神的思路并不好理解，再刷！注意理解！


375: Guess Number Higher or Lower II

https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/

一刷使用dp思路不对，问题没想清楚，总想着用二分法，事实上二分法的结果并非最优！二刷使用大神的bottom-up的DP，没有一次AC，对DP的更新过程理解不够，再刷，注意理解。


638: Shopping Offers

https://leetcode.com/problems/shopping-offers/description/

一刷使用自己设计的DP方法，WA。二刷使用带memo的dfs，这是top-down的dp，但是我更熟悉bottom-up的dp。由于把变量k写成key（这也是变量名设计问题），一直WA，debug很久。思路比较清晰，我自己两个思路都想明白了，但是手生。再刷！


690: Employee Importance

https://leetcode.com/problems/employee-importance/description/

一刷使用DFS暴力递归AC。效率低，时间复杂度为O(LN)，空间复杂度为O(L)，L为下属员工总个数（包括非直接下属），N为员工总数。再刷尝试高效解法。


513: Find Bottom Left Tree Value

https://leetcode.com/problems/find-bottom-left-tree-value/description/

一刷使用DFS暴力递归AC，效率低。时、空间复杂度O(L^2)，因为递归深度为L，查深度和查最左下元素都要递归到最底层。再刷要使用高效解法。二刷使用大神的DFS解法，不太理解，再刷！


869: Reordered Power of 2

https://leetcode.com/contest/weekly-contest-93/problems/reordered-power-of-2/

DFS。将一个整数$N$的各位上的数字打乱，将这些数字重新组合，是否存在一个组合能使组合得到的数字$n$(0不可以出现在首位)是$2$的幂。这是个典型的DFS的题目，用一个map记录数字到频率的映射，然后DFS遍历所有组合，在DFS的过程中判断$n$是否是$2$的幂，判断依据很简单，当且仅当$n$的二进制表示中只有一位为1时，$n$为$2$的幂。如果$n$是$2$的幂，则立即中断DFS。

我一开始的解法设计是先用DFS遍历出所有可能的组合，再从中查找是否有满足条件的组合，这种做法的时间和空间复杂度都极高，以至于TLE了。


856: Score of Parentheses

https://leetcode.com/contest/weekly-contest-90/problems/score-of-parentheses/

递归。按指定规则计算括号对的分数，递归思路比较容易，用栈找第一个左括号与最左侧匹配的右括号，将原括号组分为左右两部分，并对两个子问题进行递归处理。



693: Binary Number with Alternating Bits

https://leetcode.com/problems/binary-number-with-alternating-bits/description/

一刷没AC，忘记更新ex。时间复杂度为O(log N)，空间复杂度为O(1)。没有再刷的必要。


691: Stickers to Spell Word

https://leetcode.com/problems/stickers-to-spell-word/description/

一刷没思路，套用大神的思路是带memo的DFS，思路很清晰，一刷AC。时、空间复杂度为O(N)，递归深度也是N。手生，再刷。


695: Max Area of Island

https://leetcode.com/problems/max-area-of-island/description/

一刷AC，关键思想是算法核心使用dfs,利用queue存储中间结果，原地更改数组。时间复杂度为O(M*N)，空间复杂度为O(1)。


733: Flood Fill
https://leetcode.com/contest/weekly-contest-60/problems/flood-fill/

dfs, 注意将访问过的节点设置为特殊字符，然后再变回来，防止死循环。


694: Number of Distinct Islands
https://leetcode.com/contest/leetcode-weekly-contest-53/problems/number-of-distinct-islands/

一刷没有想到怎么表示多个岛之间的“translation”的关系，题意不太理解，跟上题很像，只需要用set记录编码之后的island的所有node，最后返回set的长度即可。还学到了访问matrix一个元素四周邻居的更省空间的方式，数组bias设置为[1, 0, -1, 0, 1]即可，每次访问row的bias为bias[i],column的bias为bias[i + 1]，非常巧妙！这个题目对于非付费用户依据封锁了，尽快再刷一次。


496: Next Greater Element I

https://leetcode.com/problems/next-greater-element-i/description/

一刷没思路，借鉴大神基于stack的思路AC。思路很奇妙，还需深入理解。二刷AC，简化了代码。


503: Next Greater Element II

https://leetcode.com/problems/next-greater-element-ii/description/

一刷使用和上题相似的思路，没想清楚，WA。本题中有重复元素，stack和map都要保存index，和上题的区别在于要进行两次遍历，算法效率还可以继续提升。时间和空间复杂度为O(N)。再刷。



341: Flatten Nested List Iterator

https://leetcode.com/problems/flatten-nested-list-iterator/description/

一刷思路不对，使用大神的思路一刷没有AC，跟我的思路相似。再刷，深入理解大神的算法。


173: Binary Search Tree Iterator

https://leetcode.com/problems/binary-search-tree-iterator/description/

一刷按照和上题相似的思路，初始化时，遍历查找最左节点没有更新root，导致内存溢出。时间复杂度为O(N)，空间复杂度为O(H)。二刷一次AC，精简了代码。


394: Decode String

https://leetcode.com/problems/decode-string/description/

一刷使用自己的算法WA。二刷使用大神的算法AC，使用两个stack分别存放“[x]”出现时之前的num和应该加到num * "[x]"之前的string，每个元素只表示一层，跟上层无关。思路理解了，但是还不熟，再刷。三刷使用递归算法，运行时间少于非递归算法，没有AC，思路不是很清楚，再刷。


838: Push Dominoes
https://leetcode.com/contest/weekly-contest-85/problems/push-dominoes/

字符串题型。多米诺骨牌模拟题，一列骨牌，随机选择其中一部分使其左倾或者右倾，每秒传递一张牌的距离。根据一张牌的左右两侧的牌决定其状态，直到状态不变为止。有点BFS的意思。


331: Verify Preorder Serialization of a Binary Tree

https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/description/

一刷使用自己的算法，没AC，看了讨论区，有大佬和我的算法相同，稍微修改了自己的代码AC。注意考虑两点，数的长度不止为1，中间过程如果stack为空，直接返回false即可。再刷一次。


158: Min Stack
hulu面试题。使用s,min两个栈实现，min记录串数加入s之后之后的最小值，只有最小值变化或者连续添加最小值才入min栈，出栈时只有s和min的top相同才出栈。


103: Binary Tree Zigzag Level Order Traversal

https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

BFS。“之”字层序遍历二叉树。

* 双deque实现BFS：
	* 奇数层: q从尾读，next从头写，先写左子树再写右子树
	* 偶数层: q从头读，next从尾写，先写右子树再写左子树 
* 双Stack实现BFS：
	* 奇数层： 先入左子再入右子
	* 偶数层：先入右子再入左子

使用`deque`和`stack`都只有一种顺序是正确的，显然**基于`stack`的方法更简单**。

150: Evaluate Reverse Polish Notation

https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

栈。注意先出栈的第二个操作数，后出栈的是第一个操作数。


456: 132 Pattern

https://leetcode.com/problems/132-pattern/description/

一刷没思路，使用大神的算法，一次AC，但是理解不透彻。关键不太理解为什么要用while循环，是为了使用更大的中间值？再刷。


402: Remove K Digits

https://leetcode.com/problems/remove-k-digits/description/

一刷没思路，使用大神的算法，因为没注意循环过程中k会更新导致WA，debug很久。再刷！


636: Exclusive Time of Functions

https://leetcode.com/problems/exclusive-time-of-functions/description/

一刷没有想清楚怎么将中间退栈时得到的中间时间段存下来WA。二刷使用大神的算法，和我的算法相似，但是使用了stringstream，并且自己设计了新的struct，效率可能会受影响，但是非常清晰。中间没对stack判空RE。再刷。


215: Kth Largest Element in an Array

https://leetcode.com/problems/kth-largest-element-in-an-array/description/

一刷使用快排AC，快排的partition函数不止可以用挖坑填坑的方式写，还可以按照这个算法写，但是有bug，再刷！


347: Top K Frequent Elements

https://leetcode.com/problems/top-k-frequent-elements/description/

一刷使用map统计频率，按频率倒排，使用lambda表达式简化代码，O(NlogN)。二刷使用堆排，O(NlogN)。三刷使用快搜，O(N)。四刷使用priority_queue，O(NlogN),其实就是完全堆排。五刷简化四刷使用的方法，不再使用函数对象。五刷使用桶排序，bucket_size为1，将每个可能的频率都视为一个bucket，O(N)。建堆时间复杂度证明：http://blog.csdn.net/anonymalias/article/details/8807895


692: Top K Frequent Words

https://leetcode.com/problems/top-k-frequent-words/description/

一刷暴力解决，AC。二刷使用基于heap sort的方法，WA。有一点不太理解，为什么最后的结果的顺序和我想的相反？


668: Kth Smallest Number in Multiplication Table

https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/

heap: 用一个小根堆模拟排序过程，小根堆中每个元素是pair，来分别存储乘法表中的基数和乘积，用乘积排序。每次出队列的时候，如果乘积加上基数之后的值在乘法表范围内，将增大的乘积加回队列。

BS: 每一行中比目标值小的数的个数通过一次除法即可算得，这个发现可以直接将算法的计算复杂度降级。我发现了这一点，但是一直想在坐标和排序之间建立联系！BS就是通过一个指标，将一个区间严格分为两半。对于BS的理解又深了一点！


410: Split Array Largest Sum

https://leetcode.com/problems/split-array-largest-sum/

BS：左边界为0，右边界为sum。将数组按连续的方式分组，每组的和不大于mid。分组个数大于m说明mid不够，更新low；否则更新high。BS有两种写法，这两种写法是等价的！

778: Swim in Rising Water

https://leetcode.com/problems/swim-in-rising-water/

BS+DFS:提示比较明显了。用BS找解，用DFS验证解的合理性。注意用DFS验证的时候有一个小trick：可以直接修改visited，不用回溯！因为这道题中回溯是没有意义的！回溯还是过不去！加了回溯超时，去掉立马就AC了！


355: Design Twitter

https://leetcode.com/problems/design-twitter/description/

一刷使用基于堆排序的方法AC，效率并不是很高。明白了为什么有时候会和结果反序，这是因为我写的堆排序的结果是升序，而这种题目一般要求要降序输出结果。


490: Maze
锁定了，写不了。
但是比较简单，至少有两种写法。
一是使用visited，二是将访问过的区域设置为阻隔，有个非常相似的题目，但是我给忘了。


110: Balanced Binary Tree

https://leetcode.com/problems/balanced-binary-tree/description/

dfs。一种优化可以使用memo避开一些重复计算。另一种优化转为计算树的高度的问题，高度为-1表示不平衡，可以实现短路计算。


373: Find K Pairs with Smallest Sums

https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/

heap。要先把所有可能的组合都存下了，然后再用堆排序找出前k个，要注意提升效率。


659: Split Array into Consecutive Subsequences

https://leetcode.com/problems/split-array-into-consecutive-subsequences/description/

一刷没思路，找了一个比较容易理解的思路看了半天！一刷没有写temp[i]--，思路很好，但是还有继续理解！时间和空间复杂度均为O(N)。


100: Same Tree

https://leetcode.com/problems/same-tree/description/

递归，一次AC。


98: Validate Binary Search Tree

https://leetcode.com/problems/validate-binary-search-tree/description/

DFS。根据采用的参数量不同分为两种方法：
* 方法一：使用两个标识量$minValue$和$maxValue$记录BST的值的下界和上界，DFS每次判断时要判断`root->val`是否处于区间$(minValue, maxValue)$内。
* 方法二：利用BST的中序遍历一定是递增序列的性质，使用一个标识量$lastVisited$(初始化为`INT_MIN`)记录DFS中序遍历树时上次访问的节点的值，每次访问一个节点时只要确保`lastVisited < root->val`即可。

以上两种方法的区别在于**方法一**中参数足够，不需要指定DFS的遍历顺序；而**方法二**中必须按照先访问左子树再访问根节点最后访问右子树的中序遍历顺序，因为这个方法利用的就是BST的中序遍历严格递增的性质，全局只有一个参数`last_visited`，而且这个参数依赖遍历过程中的赋值。

230: Kth Smallest Element in a BST

https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

一刷使用基于非递归中序遍历二叉树的方法AC。


144: Binary Tree Preorder Traversal

https://leetcode.com/problems/binary-tree-preorder-traversal/description/

二叉树先序遍历，一刷递归AC。二刷使用非递归算法一次AC，注意入栈的时先对右子树入栈，再对左子树入栈，从而保证左子树优先访问。



200: Number of Islands

https://leetcode.com/problems/number-of-islands/description/

一刷递归没AC，小错误不断，再来一次。效率不高，再想想怎么提高效率。


473: Matchsticks to Square

https://leetcode.com/problems/matchsticks-to-square/description/

一刷递归，效率低，有大量重复计算，自己的逻辑不清晰，TLE。二刷发现大神的DFS思路和我一致，按照大神的思路改完之后效率提高很多，但是仍然有优化的空间，重复计算问题并没有完全解决。


36: Valid Sudoku

https://leetcode.com/problems/valid-sudoku/description/

暴力法：检查行 检查列 检查每个小矩阵就行，这种方法要遍历board3次。
更巧妙的方法：记录每行、每列、每个小方块中每个数字是否使用过，如果使用过了，就是invalid，这种方法只需遍历1次board，用空间换时间。注意数组的初始化！


37: Sudoku Solver

https://leetcode.com/problems/sudoku-solver/description/

dfs。注意使用上题的方式判断valid。注意`row_used`, `col_used`和`box_used`要先初始化！


102: Binary Tree Level Order Traversal

https://leetcode.com/problems/binary-tree-level-order-traversal/description/

双queue实现bfs。


127: Word Ladder

https://leetcode.com/problems/word-ladder/description/

双queue实现BFS。这种需要记录BFS中遍历层数的题不用着急在构建next的时候返回，在访问当前层的时候返回效果没多大差别，而且逻辑会更清晰。


126: Word Ladder II

https://leetcode.com/problems/word-ladder-ii/

方法一：BFS+DFS。先用BFS生成每个次到其前缀的map(string, set<string>)，利用这个map使用DFS生成所有路径,vector前向插入不便的情景可以使用list，方法比较复杂，其实完全不需要使用DFS，纯BFS就行。
方法二：单向BFS。双queue实现BFS，同时用两个对应的queue记录从beginWord到达之前两个queue中每个元素的path。注意visited的修改，层内不用更新visited，要使用layer_visited_words记录每层有哪些新的元素被访问到了，在一层访问完之后用layer_visited_words一并更新visited。其实直接用两个queue存path即可，每个path的终点就是最后一层的元素，也就是说只存元素的queue是完全多余的。
方法三：双向BFS，分别保存从beginWord和endWord两个方向出发的path，如果两条path能接上，则结果找到。有点tricky。


841: Keys and Rooms
https://leetcode.com/contest/weekly-contest-86/problems/keys-and-rooms/

BFS. 从0号房间取钥匙，然后访问0号房间中钥匙对应的房间，以此类推，典型的BFS，一开始没反应过来！


515: Find Largest Value in Each Tree Row

https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/

BFS，一刷AC。


199: Binary Tree Right Side View

https://leetcode.com/problems/binary-tree-right-side-view/description/

BFS，一刷AC。


843: Guess the Word
https://leetcode.com/contest/weekly-contest-86/problems/guess-the-word/

BFS，实际上是个概率题，初始情况下，随机选定一个word作为target，wordlist中的每个词与target match的character的个数分别为0,1,2,...,6。概率分布为$\{1 * 25^6/26^6, 6 * 25^5/ 26^6, ..., 1 * 1/ 26^6\}$，随机选出一个word调用guess，设该word与target match的字母数为r，从原始wordlist中过滤出所有与word match的字母数为r的单词（target一定包含在其中）组成新的wordlist，依次类推，知道找到target或者guess次数超过10次。由初始状态知道，match为0的概率最大，因此每次随机选择的word与target的match的字母数均为0的概率最大，为$26 * 25 * 24 * ,..., * 17 / 26 ** 10 = 6.48e-6$。因此guess一定会得到target。


130: Surrounded Regions

https://leetcode.com/problems/surrounded-regions/description/

DFS，BFS。而是从四条边界出发使用DFS或BFS即可，状态不必回溯。


865: Shortest Path to Get All Keys

https://leetcode.com/problems/shortest-path-to-get-all-keys/description/

BFS。和Maze那一系列的题目非常相似，尤其是MazeII。给定一个由二维字符数组`grid`表示的区域，`'@'`表示起点，`'#'`表示墙，`'.'`表示空白，小写字母表示钥匙，与小写字母对应的大写字母表示锁。计算从起点出发到集齐所有钥匙走的最短步数。我的BFS方法中使用Queue记录需要遍历的状态，每个状态包括当前位置与当前拥有的钥匙串，这个状态是唯一的，可以用visited集合记录已经遍历过的状态，BFS直到状态遍历完或者集齐所有的钥匙为止，BFS的层数就是结果。我的算法效率不高，TLE了。

跟AC算法相比，我对题目的数据限制分析不够到位，AC算法有以下两个优化：
1. 题目限制锁的个数最多为6个，这是一个非常重要的限制条件，这意味着不需要用set记录当前收集到的钥匙，只需要一个整数即可(后6个比特每个比特分别表示一个锁)。
2. 由于`grid`的长和宽均限制在30以内，加上**1**中的分析，state的空间其实不大($30 * 30 * 2^6$)，直接使用一个三维数组`distance`存储即可，`distance`的元素初始化全部为-1，表示没有遍历过，这个条件可以用于判断是否要讲新发现的状态加入下一层要遍历的队列中。另外`distance`还可以记录起点到当前点的距离，用于返回结果。

以上这两点优化非常重要，将BFS过程中非常频繁的查找操作的时间复杂度从$O(logN)$降到了$O(1)$。


301: Remove Invalid Parentheses

https://leetcode.com/problems/remove-invalid-parentheses/description/

一刷使用DFS,注意从左向右走，分三种情况考虑，左括号，右括号和字母。二刷使用BFS，没有更新max导致WA。

851: Loud and Rich
https://leetcode.com/contest/weekly-contest-88/problems/loud-and-rich/

BFS。 拓扑排序，可以使用visit记录下一步要访问的节点优化执行速度。


297: Serialize and Deserialize Binary Tree

https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

一刷使用基于先序遍历的递归方法没AC，没有将val转为string。思路就是先用pre_order遍历，生成字符串，再按pre_order顺序还原二叉树。

99: Recover Binary Search Tree

https://leetcode.com/problems/recover-binary-search-tree/description/

递归。BST的中序遍历结果必定是单调递增的，错误发生时，一定两次出现前一个节点的`val`比后一个节点的`val`大的情况。第一次出现时，出错的是较大的那个；第二次出现时，出错的是较小的那个。用`first`,`second`,`pre`分别记录出错的两个节点和中序遍历过程中上一次访问的节点，遍历完之后调换`first`和`second`节点的`val`即可。**注意二重指针的使用**。

87: Scramble String

https://leetcode.com/problems/scramble-string/description/

一刷递归TLE，没有先sort判断字符串是否相同减少递归深度。二刷使用sort之后AC，不是很理解思路，再刷。三刷使用java刷AC。四刷使用DP，思路和递归差别不大，边界参数错了好几个WA。使用if进行短路优化时间比不用短路优化还要长，猜是因为if破坏了流水线结构。


546: Remove Boxes

https://leetcode.com/problems/remove-boxes/description/

一刷递归思路有漏洞，二刷使用DFS，代码看了很久才理解，主要是k参数表示的是起始元素（第i个元素）的重复次数。数据的删除过程很精妙，将两个相同元素之间的子序列进行递归，起始元素就是k记录的重复元素。参数设置出错WA。三刷使用DP参数设置错了好多WA，代码看了好久才明白，看了  https://discuss.leetcode.com/topic/84687/java-top-down-and-bottom-up-dp-solutions 链接里的解释，写的非常详细，非常感谢！


452: Minimum Number of Arrows to Burst Balloons

https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/

贪心算法，自己陷入了一个有多种解需要遍历的怪圈，其实不需要。按终点大小排序后直接从直径终点射出就可以了！再刷！我的思路是每次找到重合最多的坐标点，刺破覆盖该位置的所有气球。重复以上步骤直到气球全部被刺破，这个方法一定奏效，但是复杂度极高。为什么贪心算法能work呢？


435: Non-overlapping Intervals

https://leetcode.com/problems/non-overlapping-intervals/description/

与452非常相似，但是并没有想到怎么做，看[Wikipedia](https://en.wikipedia.org/wiki/Interval_scheduling#Interval_Scheduling_Maximization)没看太明白，对于贪心还是不太理解，再刷。


870: Advantage Shuffle

https://leetcode.com/contest/weekly-contest-93/problems/advantage-shuffle/

贪心算法。给定两个大小相同的数组`a`和`b`，随意调整`a`中元素的顺序，找出一种排列顺序使同位置上的`a`中元素比`b`中元素大的个数最多。分析题目的测试用例的数据规模，不能用DFS，结合之前参加校级ACM决赛的经验，这个题是有迹可循的，当时的解决方法也是贪心算法。

* 我的思路：先将`b`排序，然后遍历`a`，为`a`中每个元素$x$在`b`中找出第一个比$x$小且没有被分配过的元素$y$。这种做法比较低效,较好状况下时间复杂度为$O(N\log N)$， 这种情况下每次BS找到的$y$都是距离$x$最近的，最坏情况下的时间复杂度为$O(N^2)$。
	* 最好情况下的例子: `a`=$[12,24,8,32]$，`b`=$[13,25,32,11]$
	* 最差情况下的例子: `a`=$[15,16,17,18]$，`b`=$[13,12,14,11]$，这种情况下每个`a`中的每个数字找到的都是距离自己最远的，需要往回走继续找。
* 最优思路：将`a`和`b`同时降序排序，记录`b`中元素原始的位置。然后使用滑动窗口方式，遍历`a`和`b`，分别用`i`和`j`来记录`a`和`b`中下次匹配的起始位置，`j`一定会比`i`率先到达终点，这表示`a`中能在`b`找到对应元素$y$的$x$都已经找到对应的元素(距离最近的较小的元素)了，然后`j`从0重新开始，`i`不变，继续滑动窗口遍历，将`b`中没有用掉的$y$随意塞给`a`中的$x$。这其实是一种TP算法，但是算法的思想有一点贪心在。

621: Task Scheduler

https://leetcode.com/problems/task-scheduler/description/

Math。找出最频繁的字母，按公式给出结果。公式是：循环体size * 循环次数(频繁字母频率-1) + 剩余的频繁字母个数。公式有特例如3个A，3个B，3个C，1个D，n=2时就不对，此时res=tasks.size()。


121: Best Time to Buy and Sell Stock

<https://leetcode.com/problems/best-time-to-buy-and-sell-stock/>

DP。给定一段时间内一支股票每天的价格数组$P$，计算本金充足只允许一次买入和一次卖出的条件下能获得的最大收益。

可以这么思考：卖出操作可以在任意一天进行，而只能在卖出日之前买入。遍历每天的股价$P_i$，尝试在这天卖出，记录历史(包括今天的)最低价$min\_price$作为买入价格，计算出收益就是今天卖出的最大收益，全局最大收益就是每天的最大收益的最大值。

122: Best Time to Buy and Sell Stock II

<https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/>

贪心算法，DP。给定一段时间内一支股票每天的价格数组$P$，计算本金充足允许多次买入和一次卖出的条件下能获得的最大收益。

* 贪心算法：由于我们知道了股票最终的走势，在不限制交易次数，仅限制买入在卖出之前的话，穷举所有可能的操作，我们可以获得这支股票的理论收益最大值，这个问题其实跟买入卖出操作关系不大。在已知未来的情况下，我们可以根据未来发生的事情选择现在的行为，如果已知明天要涨，今天买然后明天卖掉就行，每天都这么操作，见涨就执行买入和卖出交易各一次就可以获得理论上的收益最大值。
* DP：使用`buy`和`sell`数组分别记录**上一次执行的操作是买入或卖出得到的最大收益**，初始化`sell[0] = 0`，`buy[0]=INT_MIN`，递推公式为：
`sell[i] = max(sell[i-1], buy[i-1] + prices[i])`
`buy[i] = max(buy[i-1], sell[i-1] - prices[i])`


123: Best Time to Buy and Sell Stock III

<https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/>

DP，AC自动机。同122，用`buy1,sell1,buy2,sell2`分别记录买1次，买2次，卖1次和卖2次的最大收益。上述4个变量表示4种状态，这些状态呈链式连接关系，如下图所示:![image](https://github.com/igoingdown/public-notes/blob/master/images/ac_auto_machine.png?raw=true)

`sell2 = max(sell2, buy2 + prices[i])`
`buy2 = max(buy2, sell1 - prices[i])`
`sell1 = max(sell1, buy1 + prices[i])`
`buy1 = max(buy1, - prices[i])`

188: Best Time to Buy and Sell Stock IV

<https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/>

greedy，DP，AC自动机。本题实际上是122和123的合体。

* 当限制交易的次数`k`$\in$`[0, prices.size() / 2)`时：用123中的AC自动机解法可解决，区别是这里的状态转移链更长，共计`2*k`个状态，其中`buy`和`sell`分别占`k`个。
* 当`k >= prices.size()/2`时：这个题退化到122，用贪心算法直接计算最大收益即可。


714: Best Time to Buy and Sell Stock with Transaction Fee

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

一刷使用自己设计的贪心算法：先买，涨了就卖，这样是不对的！[1,3,7,5,10,3]这个case就不对。二刷使用s0和s1分别记录两种状态，这是有限状态自动机的概念，s0是手里没有股票的收益，s1是手里有一支股票的收益，在两个状态之间切换，和309很像。

309: Best Time to Buy and Sell Stock with Cooldown

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

DP。使用基于有限状态机的DP，时间复杂度和空间复杂度均为$O(N)$。`s0,s1,s2`三个状态分别表示最后一个操作为`rest`, `buy`, `sell`的当天`max_profit`。

649: Dota2 Senate

https://leetcode.com/problems/dota2-senate/description/

queue。用queue对游戏进行模拟，一方将另一方ban掉，靠前的那一方ban，靠后的那一方被ban，而且ban的那一方经过这一轮之后下一轮仍然可以投票，所以要将这个数加上N之后放到队列末尾。二刷AC。

134: Gas Station

https://leetcode.com/problems/gas-station/description/

math。在一个单向成环的道路(类比单链表成一个完整环)上有$N$个加油站，对于每个加油站$G_i$，有两个重要参数:分别是加油站储油量$g_i$和从第$i$个加油站到第$i+1$个加油站需要消耗的油量$c_i$，给定一辆油箱无限大的卡车，问从哪个加油站出发可以绕环路一圈回到起点。

定义$l_i = g_i - c_i$，遍历每个加油站$G_i$(尝试以$G_i$为起点)，如果$G_i$可以成为起点则返回$i$，如果$G_i$不能成为起点，即从$G_i$出发最远只能到达$G_j$，则$[G_i, G_{i+1}, \cdots ,G_j]$中任意一个加油站都不能成为起点，这是因为：

1. 对于$[G_i, G_{i+1}, \cdots ,G_j]$的任意一个加油站$G_k$，有$\sum_{k=i}^j l_k < 0$和$\sum_{x=i}^k l_x \geq 0$
2. 根据**1**，有$l_j < 0$，$\sum_{k=i}^{j-1} l_k \geq 0$和$|l[j]|> \sum_{k=i}^{j-1} l_k$
3. 故$\sum_{x=k}^{j-1} l_x < \sum_{x=i}^{j-1} l_x$
4. 于是$\sum_{x=k}^j l_x<0$，即从$G_k$不可能到达$G_j$。

重复以上过程直到遍历结束，如果$\sum_{i=1}^N l_i >= 0$，则一定有解，且最后一次选中的作为起点的$G_i$就是一个解。

808: Soup Servings

math，DP，DFS，BFS。难点在于空间和时间限制很死，而题目结果是有极限的，要发现问题的结果的规律，简化求解过程。概率随着N的增大而显著增大，概率最大值为1，这就要自己去试探边界。BFS导致TLE，DFS + memo可以接近临界情况，但是还是不够，必须发现概率随N递增规律才能解出这道题。DP要考虑空间开销，我用的二维DP，有解法优化到了一维DP。


179: Largest Number

https://leetcode.com/problems/largest-number/description/

一刷基于sort做，AC。可以直接对数字排序，然后逐个加进来。要更深入地理解为什么这样能work！


324: Wiggle Sort II

https://leetcode.com/problems/wiggle-sort-ii/description/

一刷使用笨方法，没AC，完全招架不住Follow up。再刷。


225: Implement Stack using Queues

https://leetcode.com/problems/implement-stack-using-queues/submissions/1

queue。`pop`函数和普通的`stack`的`pop`不同，要返回栈顶元素。


42: Trapping Rain Water

<https://leetcode.com/problems/trapping-rain-water/description/>

stack，单调递减栈。

栈中存放的是可以作为当前水槽的左边界或底板的数的index，如果后面出现了较大的数，则新的数可以作为水槽的右边界。对于要出栈的情况，即出现右边界时，如果栈中有两个及以上的元素，则当前栈顶可以作为水槽底板，底板出栈后的那个栈顶就是左边界，当前水槽可以容纳的水就是`min(left_bound, right_bound) - bottom * width`。

739: Daily Temperatures

<https://leetcode.com/contest/weekly-contest-61/problems/daily-temperatures/>

stack，单调递减栈。

类似42，栈中存放的是可能有更高温度出现的日期的index。

246: Sliding Window Maximum

https://leetcode.com/problems/sliding-window-maximum/description/

queue，单调递减双端队列或堆。

* 使用deque: 类似42，维护一个单调递减栈（存索引）可以知道一定范围的数组的最大值，而且最大值就是栈的最底端的元素。由于需要取出窗口中的最大值（即需要访问栈的最底端元素），另外当窗口滑过当前最大值所在的位置时，需要将最大值删除（删除栈的最底端元素），综合以上需求，双端队列是最理想的数据结构！
* 使用优先级队列: 直接存索引，按照数字大小构建大根堆即可。注意c++实现优先级队列不好写，需要构造一个带参数的函数类。

84: Largest Rectangle in Histogram

<https://leetcode.com/problems/largest-rectangle-in-histogram/description/>

stack，单调递增栈。

栈中存储的是可能作为矩形的高使矩形可以向右延伸的数的index。在需要出栈的情况下，
* 如果栈中元素个数大于1: 矩形的高为`arr[s.top()]`，矩形的长是`(i - 出栈后的栈顶 + 1)`。
* 如果栈中元素个数为1：当前栈顶为全局洼地！矩形高为`arr[s.top()]`，长为`arr.size()`。

735: Asteroid Collision

<https://leetcode.com/contest/weekly-contest-60/problems/asteroid-collision/>

利用stack的特性，注意分类！


296: Best Meeting Point

这是一道锁定题。横轴纵轴互不影响，可以将两个维度直接拆开，每个维度排序之后去掉单个的中间节点，加上剩余配对的节点之间的距离即可。

164: Maximum Gap

https://leetcode.com/problems/maximum-gap/description/

Bucket Sort。 

* 暴力算法：先sort然后遍历，O(NlogN)的时间复杂度。
* Bucket sort: 题目要求O(N)的时间和空间复杂度，桶排序可以满足要求，时间和空间复杂度都是O(N)。每个bucket的size并不是非常重要的参数，bucket的个数也不需要非常严格，但是一定要保证大于需要的桶的个数。


23: Merge k Sorted Lists

https://leetcode.com/problems/merge-k-sorted-lists/description/

Heap。炒鸡经典的考题！`priority_queue`的构造函数中第三个参数不可以使用lambda表达式，但是可以自己构造函数类从而生成函数对象、或者直接传递一个函数指针。时间复杂度为$O(NK\log{K})$


632: Smallest Range

https://leetcode.com/problems/smallest-range/description/

Heap。和merge sort的merge算法类似，区别在于本题需要访问priority_queue的队尾元素，因此使用了map，map基于红黑树实现，自动对key进行排序，而且可以通过迭代器随时访问头和尾。保证队列中存有每个list中的最小的数，队列的队头和队尾之间的距离的最小值就是题目的解，每次更新结果后，扔掉队头，并将队头所在的list中下一个元素添加到队列中。将map作为可以两端同时访问的priority_queue的想法真是要逆天了！


846: Hand of Straights

https://leetcode.com/contest/weekly-contest-87/problems/hand-of-straights/

map。跟上面的那道题有异曲同工之妙，因为map基于红黑树实现，默认根据key的大小排序！用map记录数组中数字的频率，每组的起点一定是当前map的key的起点，每组要消耗一个数，消耗完就将其移除这个key。只要出现一次key的缺失，则失败！


239: Sliding Window Maximum

https://leetcode.com/problems/sliding-window-maximum/description/

一刷使用java优先级队列（因为c++中的优先级队列没有remove接口）没有判空CE，时间复杂度为O(NlogK)，时间复杂度不够好，最好的算法是递归。


295: Find Median from Data Stream

https://leetcode.com/problems/find-median-from-data-stream/description/

Heap。分别使用小根堆和大根堆存储较大的部分和较小的部分，控制大根堆的size = 小根堆的size或者小根堆的size + 1。一刷没处理好插入元素的大小和大根堆小根堆的size的限制关系，WA。


857: Minimum Cost to Hire K Workers

https://leetcode.com/contest/weekly-contest-90/problems/minimum-cost-to-hire-k-workers/

Heap。这是个非常好的题目！场景是给公司制定招人策略，给定一组候选人，每个员工有两个参数：quality和期望最低wage。要求招K个人，招的人的wage按quality的比例给，要求招人花费的钱最少。直观感受是对每个员工按`wage/quality`升序排序，因为还钱最少，肯定要招性价比最高的员工。但是由于所有员工的实际按招的人的quality的比例给，如果招了一个quality非常高，同时期望最低wage也很高的人，那这组解就不一定是最优解。于是我们可以得到总体的招人原则：
1. 招的人的`wage/quality`尽可能低（要求候选人对自己的认识足够清晰）

2. 招的人quality不能太高（招尽可能平庸的人！）

于是解法就比较清晰了，构建quality的大根堆q，遍历按wage/quality升序排序后的候选人（包括wage和quality属性）列表，每次将当前候选人插入q中，用sum记录当前q中候选人quality的总数，当q中候选人的个数为K时，招这K个人要花的钱是sum * 当前候选人的`wage/quality`，这是因为当前候选人的`wage/quality`一定是最大的。当q的候选人数大于K(为K+1)时，先把quality最大的候选人出队列(不要他了，因为他太优秀了)，然后按前一种情况处理即可。

332: Reconstruct Itinerary

https://leetcode.com/problems/reconstruct-itinerary/description/

dfs和heap结合，时间复杂度？思想是path先添加无路可走的节点，使用链表的头插法。c++的list数据结构基于链表实现，接口很多，非常方便，相当于java中的LinkedList。分别使用c++和java刷过，但是都没有一次AC。三刷忘记了基于heap的方法，使用纯DFS加排序。两种算法的时间复杂度在搜索解空间时有较大区别，还需要认真分析。

146: LRU Cache

<https://leetcode.com/problems/lru-cache/description/>

`Hashmap`和`list`。

* 主要利用了`STL`的`list`基于双向循环链表实现的性质及其提供的`splice`接口，因为`list`底层使用了双向循环链表，插入、删除都可以控制在O(1)。`splice`接口可以直接将`list`中刚刚使用过的元素调度到`list`的首部，这是LRU的核心思想。
* 而基于`hashmap`的查找、插入和删除同样是O(1)。
* `put`操作的实现中，不仅要修改`list`和相应的迭代器，还有`list`中的值和`map`。
* 这种实现中元素优先级越高，使用越频繁，在`list`中的位置越靠前，删除只会在`list`的尾部进行，而`hashmap`的删除操作随时随时都可以进行。
* `list<pair<int, int>> items`存储K-V对
* `unordered_map<int, list<pair<int, int>>::iterator> cache`存储key到`list`中key-value对的迭代器的map，可以脑补图形。
* `splice`函数的三种原型:
	* `void splice (iterator position, list& x);`
	* `void splice (iterator position, list& x, iterator i);`
	* `void splice (iterator position, list& x, iterator first, iterator last);`
	三种原型的作用都是将`x`中的一个或多个元素插入到`position`处，并将`x`中原来的元素删除，这个函数很好实现，就是双向循环链表的拼接。

290: Word Pattern

https://leetcode.com/problems/word-pattern/description/

双map，一次AC。


291: Word Pattern II

https://www.programcreek.com/2014/07/leetcode-word-pattern-ii-java/

双map和dfs结合。strStart应该更新为i + 1而不是i。


734: Sentence Similarity

https://leetcode.com/contest/weekly-contest-60/problems/sentence-similarity/

map，没理解题意，sentence相似要求每个位置的word都相似！第一次用python刷题，比c++快多了，在数据结构涉及set，string等结构时，python非常方便。


525: Contiguous Array

https://leetcode.com/problems/contiguous-array/description/

核心公式diff[i, j] = diff[0,j] - diff[0,i]，diff表示1比0多的个数，数组的一小段的diff等于整个数组的起始位置到段结尾的diff减去全数组起始位置到段起始的diff。当两个diff相等，表示中间的小段0和1的个数相同，更新结果。一刷没AC，注意处理空数组（diff要多加一个空位，map也要！）。


76: Minimum Window Substring

<https://leetcode.com/problems/minimum-window-substring/description/>

TP，将直通硅谷老师的思路改进如下：
1. 分别用`aMap`与`tMap`存储符合条件的子串($S[i,j]$)与$T$中的字符及对应的频率。 
2. for循环优先开拓右边界`j`，如果左、右边界限定范围内的子串包含$T$，然后逐渐压缩左边界`i`至无法压缩为止，此时的子串$S[i,j]$为一个候选解:
	1. 先将$S[j]$添加到`aMap`中
	2. 尝试更新`count`（记录当前时刻$T$中没有被子串$S[i,j]$包含的字符个数）
	3. 如果子串$S[i,j]$满足条件`count == 0`,使用`while`循环右移`i`至无法右移为止，右移结束后，更新`min_len`和`min_start`。


207: Course Schedule

https://leetcode.com/problems/course-schedule/description/

graph拓扑排序，算法复杂度有点高，可继续优化！一次AC。


210: Course Schedule II

https://leetcode.com/problems/course-schedule-ii/description/

graph拓扑排序，和上一道比仅仅是输出结果有变化。


269: Alien Dictionary
http://blog.csdn.net/qq508618087/article/details/50981000
这是一道有锁题，graph的拓扑排序。


310: Minimum Height Trees

https://leetcode.com/problems/minimum-height-trees/description/

graph的拓扑排序。


399: Evaluate Division

https://leetcode.com/problems/evaluate-division/description/

图的dfs,一刷虽然有些typo，但是一次AC！我感觉自己刷题真的变厉害了，套路题我不怕了！


738: Monotone Increasing Digits
https://leetcode.com/contest/weekly-contest-61/problems/monotone-increasing-digits/

数学题，没认真想，思路不好，不要怕开空间！


740: Delete and Earn
https://leetcode.com/contest/weekly-contest-61/problems/delete-and-earn/

DP，可以降为子问题，典型的0-1背包问题。要继续思考，细嚼慢咽还是很有收获的。


393: UTF-8 Validation

https://leetcode.com/problems/utf-8-validation/description/

dfs，1，2，3，4个字符表示一个UTF8码分别对应4个子问题。注意位运算的优先级没有判断符号优先级高！位运算的优先级很低！注意递归要先设定基础情况，注意判断index不能越界！


617: Merge Two Binary Trees

https://leetcode.com/problems/merge-two-binary-trees/description/

简单递归


637: Average of Levels in Binary Tree

https://leetcode.com/problems/average-of-levels-in-binary-tree/description/

双queue层序遍历


653: Two Sum IV - Input is a BST

https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

递归，BST查找，想复杂了！


538: Convert BST to Greater Tree

https://leetcode.com/problems/convert-bst-to-greater-tree/description/

一开始思路不好，只想着记录父节点，导致重复计算，要再想一下为什么！使用sum记录当前访问的最大值，是最吼的，逆先序遍历即可。


563: Binary Tree Tilt

https://leetcode.com/problems/binary-tree-tilt/description/

BST的递归，自己的思路RE，想破头没想明白，大佬的思路比我的简洁，只用了一个递归！我的用了两个递归！


572: Subtree of Another Tree

https://leetcode.com/problems/subtree-of-another-tree/description/

两个递归，效率略低。


437: Path Sum III

https://leetcode.com/problems/path-sum-iii/description/

双递归，注意空节点的处理。不能靠子节点判断父节点的值的情况，因为子节点有两个，这样容易导致重复。


501: Find Mode in Binary Search Tree

https://leetcode.com/problems/find-mode-in-binary-search-tree/description/

双递归，子递归设计要注意Mode中的数字对应节点不一定都连着，利用BST的性质！


687:  Longest Univalue Path

https://leetcode.com/problems/longest-univalue-path/description/

双递归。


654: Maximum Binary Tree

https://leetcode.com/problems/maximum-binary-tree/description/

树的递归。


101: Symmetric Tree

<https://leetcode.com/problems/symmetric-tree/description/>

递归。对左右子树判断对称性。


145: Binary Tree Postorder Traversal

https://leetcode.com/problems/binary-tree-postorder-traversal/description/

二叉树后续遍历递归与非递归实现。多做是有用的，非常有用，做这个题的时候深有体会！

872: Leaf-Similar Trees

<https://leetcode.com/contest/weekly-contest-94/problems/leaf-similar-trees/>

递归。定义如果两棵树的叶子节点按从左到右的顺序访问，得到结果列表相同，则两棵树相似。给定两棵树，判断两棵树是否相似。

中序递归遍历两棵树，记录叶子节点的访问列表，判断访问列表是否完全相同即可。

655: Print Binary Tree

<https://leetcode.com/problems/print-binary-tree/description/>

合并左右子树的时候思路要清晰，分情况，不是两边一直用空串填充，而是每个元素两侧都使用空串填充！一步步简化代码，对容器的insert函数用熟了！


623: Add One Row to Tree

https://leetcode.com/problems/add-one-row-to-tree/description/

树的层序遍历（双queue），注意要保存更上一层的节点，添加子树时不必考虑子树是否为空！


337: House Robber III

https://leetcode.com/problems/house-robber-iii/description/

递归，有点0-1背包的意思。


662: Maximum Width of Binary Tree

https://leetcode.com/problems/maximum-width-of-binary-tree/description/

一刷使用BFS，当树的高度过大时，内存溢出。二刷基于BFS，利用满二叉树的性质（子节点和父节点index之间的关系，$left\_child\_node\_index = parent\_node\_index * 2$， $right\_child\_node\_index = parent\_node\_index * 2 + 1$。


129: Sum Root to Leaf Numbers

https://leetcode.com/problems/sum-root-to-leaf-numbers/description/

dfs，遇到叶子节点就把num(表示path)加到res上。如果follow up将节点的数只有1位的限制去掉，可以使用vector表示path。


450: Delete Node in a BST

https://leetcode.com/problems/delete-node-in-a-bst/description/

好题！删除BST中的节点，上课讲过，自己做还是废了不少时间。递归删除节点，找到节点后分情况讨论，找左子树的最大值或者右子树的最小值作为新的根的值，并删除原节点，findAndDelete函数要注意删除节点不能直接将父节点的右子树设为NULL，要设为删除节点的左子树！


116: Populating Next Right Pointers in Each Node

<https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/>

BFS。双queue实现的BFS空间复杂度为O(N)，不满足要求。利用next指针可以实现BFS，空间复杂度仅为O(1)。

使用三个指针即可实现BFS，`cur`记录本层的访问位置，`next_start`指向下一层的起始位置，`next_end`指向下一层的末端。每次访问`cur`，如果有左子或右子，都要根据`next_start`进行判断：
1. `next_start == NULL`:将该子节点作为`next_start`并且让`next_end`也指向该节点
2. `next_start != NULL`: 将该子节点添加到`next_end`之后。 


117: Populating Next Right Pointers in Each Node II

<https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/>

BFS。和116完全相同。


847: Shortest Path Visiting All Nodes

https://leetcode.com/contest/weekly-contest-87/problems/shortest-path-visiting-all-nodes/

BFS + DP。使用2进制的方法记录每个节点是否被访问，相当于中间状态。每次访问一条边，如果经过头结点的状态到达尾节点的距离大于经过头结点的状态到头结点 + 1，则更新经过头结点状态到达尾节点的距离。

871: Minimum Number of Refueling Stops

https://leetcode.com/problems/minimum-number-of-refueling-stops/description/

BFS。题目的场景和**leetcode 134**很像，给定一辆油箱无限大的卡车，初始油量为$G$，需要前往离起点$S$距离为$T$的目的地$D$，起点和终点之间有若干加油站，加油站$G_i$到起点的距离和储油量分别记为$d_i和g_i$，求从起点到终点需要加油的最少次数。

分析可知这是个BFS的题目，遍历解空间一定可以得到解，我用双queue实现了BFS，但是很遗憾空间复杂度过高，内存超了。分析可知这个题目有一个性质在提示我们可以用`priority_queue`代替`queue`实现BFS，这个性质就是：在BFS的过程中，解空间中一个父节点的所有子节点是有优劣比较的，因为目标是要加油的次数最少，我们必须要优先选择储油量最大的子节点(加一次油可以撑到更远的距离)，只有当储油量最大的子节点的储油量不足够到达下一个加油站的时候，才会继续选择储油量更小的节点，就是说最好的情况是加一次(选择储油量最大的子节点)就可以撑到下一个加油站，最坏的情况是所有子节点都选中了，即上次加油后，沿途的每个加油站都停下加油，结果还是撑不到下一个加油站，这种情况下就必然无法到达目的地了！因此可以用`priority_queue`来实现BFS。每次访问一个父节点，将所有可能的子节点都加入`priority_queue`中，选择储油量最大的子节点，更新这次加油后能到达的最远距离$d$和加油次数$c$，直到$d \geq T$为止。`priority_queue`实际保存了从起点到当前位置为止，沿途没有加过油的加油站按储油量由大到小排序的优先级队列。


236: Lowest Common Ancestor of a Binary Tree

https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

两个节点的LCA，非常经典！O(N)时间复杂度，递归找path，选出最后一个相同节点，这是最蠢的方法！

866: Smallest Subtree with all the Deepest Nodes

https://leetcode.com/contest/weekly-contest-92/problems/smallest-subtree-with-all-the-deepest-nodes/

dfs，多个节点的LCA。递归找path，选出最后一个相同节点，在这个场景下这个解法还不错。


297: Serialize and Deserialize Binary Tree

https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

树的序列化与反序列化，非常经典！先序遍历的递归。


449: Serialize and Deserialize BST

https://leetcode.com/problems/serialize-and-deserialize-bst/description/

BST的序列化与反序列化，和上题使用完全相同的思路AC，应该可以结合BST的特征进行简化！


652: Find Duplicate Subtrees

https://leetcode.com/problems/find-duplicate-subtrees/description/

利用树的遍历先进行序列化，在序列化过程中将序列化结果和根节点对应起来，注意树的序列化结果要有唯一性，必须加入额外信息：如两侧加括号。


752: Open the Lock

https://leetcode.com/contest/weekly-contest-64/problems/open-the-lock/

BFS，很简单，比赛的时候网站报的出问题case不对，出问题的原因是没有对"0000"这一状态进行检测就加入了队列，但是网站上给的提示case不是这个。感觉DP也能做，但是想不到能从小到大填空的思路。


747: Largest Number Greater Than Twice of Others

https://leetcode.com/contest/weekly-contest-64/problems/largest-number-greater-than-twice-of-others/

数组最大值，简单题


284: Peeking Iterator

https://leetcode.com/problems/peeking-iterator/description/

系统设计题，考的是拷贝构造函数的应用。


208: Implement Trie (Prefix Tree)

https://leetcode.com/problems/implement-trie-prefix-tree/description/

Trie。系统设计题，实现前缀树。注意要用`c - 'a'`而不是直接用`c`来索引后继节点！


14: Longest Common Prefix

https://leetcode.com/problems/longest-common-prefix/description/

Trie。


648: Replace Words

https://leetcode.com/problems/replace-words/description/

Trie。

211: Add and Search Word - Data structure design

https://leetcode.com/problems/add-and-search-word-data-structure-design/description/

Trie。注意查找的时候如果碰到`'.'`，需要使用DFS，把所有可能的路径均遍历结束后如果都没有找到正确结果，返回`false`。

307: Range Sum Query - Mutable

https://leetcode.com/problems/range-sum-query-mutable/description/

一刷使用暴力解法AC，时间复杂度为O(N)。用线段树和二分索引树做时间复杂度可以降到O(log N)。

530: Minimum Absolute Difference in BST

https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/

一刷递归一次AC。


729: My Calendar I

https://leetcode.com/problems/my-calendar-i/description/

TreeMap。判断多条线段是否存在交集，可以用java的TreeMap轻松实现。对于任意一个新加入的线段，分别判断起点start的floorKey和ceilingKey记录的线段与新加入的线段是否有重叠即可。

731: My Calendar II

https://leetcode.com/problems/my-calendar-ii/description/

这是一道什么类型的题？还有什么其他方法？这类interval的题目还是比较多的。一刷使用逐一重叠并记录的方法。



220: Contains Duplicate III

https://leetcode.com/problems/contains-duplicate-iii/description/

一刷暴力法，O(NK)的时间复杂度，TLE。二刷使用基于bucket的方法AC。


382: Linked List Random Node

https://leetcode.com/problems/linked-list-random-node/description/

概率，math。for循环每次以1/k概率将原值覆盖，$(1-1/k)$的概率保留原值。当链表中的数字为：{1， 2， 3， 4}时,概率分布如下：
$$P(res = 1) = 1 * 1/2 * 2/3 * 3/4$$
$$P(res = 2) =     1/2 * 2/3 * 3/4$$
$$P(res = 3) =           1/3 * 3/4$$
$$P(res = 4) =                 1/4$$


398: Random Pick Index

https://leetcode.com/problems/random-pick-index/description/

同上一题，O(N)。


560: Subarray Sum Equals K

https://leetcode.com/problems/subarray-sum-equals-k/description/

一刷使用二维DP内存超了，改为一维DP之后AC，这两种方法都是O(N^2)时间复杂度，空间复杂度一个为O(N^2)，一个为O(N)。二刷三刷用map存储累积和，map的查找替换了vector的查找，时间复杂度从O(N^2)降到了O(N)。仍然不太理解初始时"m[0]=1"的设置！


760: Find Anagram Mappings
https://leetcode.com/contest/weekly-contest-66/problems/find-anagram-mappings/

map，key为元素值，value为vector的iterator。


758: Bold Words in String
https://leetcode.com/contest/weekly-contest-66/problems/bold-words-in-string/

转化为合并interval


759: Employee Free Time
https://leetcode.com/contest/weekly-contest-66/problems/employee-free-time/

同上题，转化为合并interval。


2018.1.10.1 Eat Cheese I
房间里有多块奶酪(x,y)，小老鼠一开始在(0,0)，问小老鼠吃掉所有奶酪要走的最短距离。
dfs + 剪枝。

2018.1.10.2 Eat Cheese II
房间表示为二维数组, 元素值0，1，2分别不可走，可走，奶酪。小老鼠从左上起点出发，吃掉所有奶酪，到达右下终点需要的最短路径。
dfs + bfs。


2018.1.11.1 Round Robin
轮询调度，带权重的轮询调度
最大公约数、多个数的最大公约数、轮询调度


28: Implement strStr()

https://leetcode.com/problems/implement-strstr/description/

暴力匹配和KMP算法，KMP算法关键在于求解next数组。求解next数组和模式匹配过程相似，模式匹配中i,j均初始化为0；求解过程需要修改next数组,i,j初始化为0和-1，next数组初始化为全零，next[0]=-1。


762: Prime Number of Set Bits in Binary Representation
给定一个范围，判断范围内的每个数的二进制表示中1的个数是否为质数
bitset


763: Partition Labels
将仅含有小写字母的字符串，要求划分后子串尽可能多而且每个字母最多出现在一个划分中。
DFS超时，贪心AC。


764: Largest Plus Sign
判断仅含有0和1的矩阵中，1的位置能够组成的最大“十字架”的形状大小。
DP。


65: Valid Number

https://leetcode.com/problems/valid-number/description/

正则表达式，注意trim之后再进行正则表达式匹配。


70: Climbing Stairs

https://leetcode.com/problems/climbing-stairs/description/

DP，递归。递归超时，可以使用迭代替换递归，实质是斐波那契数列，计算的是合法的排列数。


91: Decode Ways

https://leetcode.com/problems/decode-ways/#/description

线性DP。注意处理非法输入，每个原问题最多有两个最优子问题：
1. `f[0] = 0`，空串结果为0
2. `f[i] = s[i] == '0' ? 0 : f[i - 1] + "10" < s[i-1,i] <= "26" ? f[i-2] : 0`，如果当前字符是`1-9`，则该字符可以单独decode，这是`f[i]`应该加上`f[i-1]`，如果当前字符和前一个字符组成的字符串属于`["10", "26"]`，这两个字符可以连在一起decode，此时`f[i]`应该加上`f[i-2]`，于是这个题目的实质就和斐波那契数列一致了。

88: Merge Sorted Array

https://leetcode.com/problems/merge-sorted-array/description/

TP。我用了堆，用了temp，空间复杂度高。最优解是将较长的数组扩充，然后倒着插入，思路类似快排，挖坑填坑。


125: Valid Palindrome

https://leetcode.com/problems/valid-palindrome/description/

字符相关API如：isdigit,isalpha,isalnum,isupper,islower要用熟。


4: Median of Two Sorted Arrays

https://leetcode.com/problems/median-of-two-sorted-arrays/description/

BS，TP。查找两个有序数组$a_1,a_2$组成的大数组$a$的中位数，时间复杂度要求$O(\log{(m+n)})$。
* TP: 模拟归并排序的merge过程，分别查找使用两个指针$p,q$排序后的$a$中的元素$a_{(m + n + 1) / 2}$和$a_{(m + n + 2) /2}$，求两者的平均数，时间复杂度$O(m+n)$。
* BS: 递归实现BS，与TP类似，在查找两个元素的过程中，比较的关键步骤，分别从$a_1,a_2$中取出中位数$a_1[i]$和$a_2[j]$，比较两者，小的那个所在的数组的前一半可以舍弃掉，这样就讲问题的规模缩减了一半，时间复杂度$O(\log{m + n})$。


10: Regular Expression Matching

https://leetcode.com/problems/regular-expression-matching/description/

DP，DFS。正则表达式匹配，频率超高！同频的还有四则运算表达式的计算，前、中、后缀表达式切换和运算！

* DFS：分char和`.`，之后在内部讨论后面是否有`'*'`。
* DP：对于$p$中的任意字符$p_j$和要与$p_j$匹配的$s$中的字符$s_i$,先考虑$p_j$是否为`'*'`：
	1. $p_j$`== '*'`：此时分$s_{i}$是否为$p_{j-1}$的重复：
		* $s_i$是$p_{j-1}$的重复：此时应有$s[0,...,i-1]$和$p[0,...,j]$匹配成功，`dp[i][j] =  dp[i-1][j] && s[i] == p[j-1]`
		* $s_i$不是$p_{j-1}$的重复：此时可以视为$p_{j-1}$在$s[i]$后重复了0次，应有$s[0,...,i]$和$p[0,...,j-2]$匹配成功，`dp[i][j] = dp[i][j - 2]`
	2. $p_j$`!= '*'`：如果成功匹配，则$p[j]$必为通配符`'.'`或者$s[i]$`==`$p[j]$，`dp[i][j] = p[j] == '.' || s[i] == p[j]`。


44: Wildcard Matching

https://leetcode.com/problems/wildcard-matching/description/

DP,DFS,TP。与**10**不同的地方在于匹配规则是`'*'`可以匹配任意长度的字符串，`'?'`可以匹配单一字符。

* DFS超时。
* DP思路甚至公式和上题都非常相似:
	1. $p[j]$`=='*'`:`dp[i][j] = dp[i-1][j] || dp[i][j-1]`
	2. $p[j]$`!='*'`: `dp[i][j] = dp[i-1][j-1] && (s[i] == p[j] || p[j] == '?')`
* TP才是这道题的最优解，但是DP也不错，可以参考[这篇博客](https://yucoding.blogspot.com/2013/02/leetcode-question-123-wildcard-matching.html)。



766: Toeplitz Matrix

查看矩阵的每条斜向下对角线上的元素是否相同


767: Reorganize String

将字符串重排，要求相邻的两个字母不同，dfs超时，应该用优先级队列。


769: Max Chunks To Make Sorted (ver. 1)

给定数组为下标的一种排列，将数组进行partition，要求每个子数组排序后整个数组也有序，给出合法的partition后最多的子数组个数。


768: Max Chunks to Make Sorted (ver. 2)

与上题不同的地方在于数组中元素可以有重复。


771: Jewels and Stones
https://leetcode.com/contest/weekly-contest-69/problems/jewels-and-stones/

HashMap。


773: Sliding Puzzle
https://leetcode.com/contest/weekly-contest-69/problems/sliding-puzzle/

BFS。


774: Minimize Max Distance to Gas Station
https://leetcode.com/contest/weekly-contest-69/problems/minimize-max-distance-to-gas-station/

BS。与其他题目不同的是本题需要在整个限制范围内部进行BS，MSRA有一道题和本题相似，都是在整个限制范围内找解，这是一种很重要的思路，DP有时候也会用到这种思想。


775: Global and Local Inversions
https://leetcode.com/contest/weekly-contest-69/problems/global-and-local-inversions/

array。

hulu_wushen_1.1
使用两个stack实现queue和deque，两个stack形成了一个“U”字。pop时不用每次都要把s1倒到s2,再把剩余地倒回来，需要的时候(s2为空的时候)倒一次就行。


796: Rotate String
字符串旋转。先判断字母表是否相同，然后逐位旋转一个字符串，看是否与另一个相同，O(N^2)。要旋转字符串s的一部分s[i,j]，需要调用reverse(s.begin() + i, s.begin() + j + 1)，c++的尾迭代器都是一个字符的下一个，可以参考s.end()迭代器的使用。


797: All Paths From Source to Target
dfs。从指定起点出发到达指定终点。


798: Smallest Rotation with Highest Score
DP。一刷使用暴力法O(N^2)超时。大神的DP方法没看懂，继续攻克DP解法。


715: Range Module

https://leetcode.com/problems/range-module/description/

TreeMap。使用key记录区间[start, end)的起点，value记录终点。添加、删除、查询区间都可以很快完成。TreeMap适合这个场景，floorKey和ceilingKey两个API非常好用，可以用这两个API遍历不相邻的区间。




































