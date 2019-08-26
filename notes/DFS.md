#### leetcode DFS专题


2018.1.10.1 Eat Cheese I

房间里有多块奶酪(x,y)，小老鼠一开始在(0,0)，问小老鼠吃掉所有奶酪要走的最短距离。

dfs + 剪枝。

---------

2018.1.10.2 Eat Cheese II

房间表示为二维数组, 元素值0，1，2分别不可走，可走，奶酪。小老鼠从左上起点出发，吃掉所有奶酪，到达右下终点需要的最短路径。

dfs + bfs。


---------

834: Sum of Distances in Tree

<https://leetcode.com/contest/weekly-contest-84/problems/sum-of-distances-in-tree/>

DFS。有两种方法，第一种为暴力法，第二种方法是暴力法的优化，复用了暴力法计算出的结果。
* 暴力法：枚举。分别以每个节点为根节点，令该节点为`i`，DFS计算出节点`i`到其他所有节点的距离之和ans[i]
* 优化方法：用暴力法中的DFS先计算出`ans[0]`，
DFS过程中同时算出以任意节点`i`为根节点的子树的节点个数
![](http://latex.codecogs.com/gif.latex?{{treeNodes}_i})，这两个问题都是比较简单的问题。
然后再利用上述结果，一次DFS计算出所有的ans。具体做法是DFS遍历所有节点，已知`ans[parent]`的情况下，
`parent`节点的任意一个子节点`child`对应的`ans[child]`的公式是: 
`ans[child] = (ans[parent] - treeNodes[child]) + (N - treeNodes[child])`。
这是因为已知`ans[parent]`，求所有其他节点到一个子节点`child`的距离之和`ans[child]`时，
可以将所有节点分为两部分，一部分是以`child`为根节点的子树，记为`a`；另一部分记为`b`。
`a`中的每个节点到`parent`的距离减1就是这些节点到`child`的距离，
`b`中每个节点到`parent`的距离+1就是该节点到`child`的距离。
反映在`ans`上时，`a`部分需要在`ans[parent]`的基础上减掉`treeNodes[child]`，
`b`部分需要在`ans[parent]`的基础上加上`(N - treeNodes[child])`，于是就有了上面的公式。


---------

778: Swim in Rising Water

https://leetcode.com/problems/swim-in-rising-water/

BS+DFS:提示比较明显了。用BS找解，用DFS验证解的合理性。注意用DFS验证的时候有一个小trick：
可以直接修改visited，不用回溯！因为这道题中回溯是没有意义的！过不去的情况下回溯了还是过不去！
这个条件有点像Maze那道题，可以找出来看看。


---------

797: All Paths From Source to Target

dfs。从指定起点出发到达指定终点。

---------

399: Evaluate Division

https://leetcode.com/problems/evaluate-division/description/

DFS。图的dfs。


---------

98: Validate Binary Search Tree

https://leetcode.com/problems/validate-binary-search-tree/description/

DFS。根据采用的参数量不同分为两种方法：
* 方法一：使用两个标识量$minValue$和$maxValue$记录BST的值的下界和上界，
DFS每次判断时要判断`root->val`是否处于区间$(minValue, maxValue)$内。
* 方法二：利用BST的中序遍历一定是递增序列的性质，
使用一个标识量$lastVisited$(初始化为`INT_MIN`)记录DFS中序遍历树时上次访问的节点的值，
每次访问一个节点时只要确保`lastVisited < root->val`即可。

以上两种方法的区别在于**方法一**中参数足够，不需要指定DFS的遍历顺序；
而**方法二**中必须按照先访问左子树再访问根节点最后访问右子树的中序遍历顺序，
因为这个方法利用的就是BST的中序遍历严格递增的性质，
全局只有一个参数`last_visited`，而且这个参数依赖遍历过程中的赋值。

---------

842: Split Array into Fibonacci Sequence

<https://leetcode.com/contest/weekly-contest-86/problems/split-array-into-fibonacci-sequence/>

DFS. 记录起始位置和分离结果，设置终止条件，将问题转为子问题，注意处理起始字符为`0`和解析出的数`>= INT_MAX`的情况。

---------

743: Network Delay Time

<https://leetcode.com/problems/network-delay-time/description/>

DFS，BFS，Dijkstra。Dijkstra算法效率不如BFS，问题在于我实现的版本效率不高，可以继续改进。BFS是Dijkstra的降级。
很经典的问题，pony的面试也考到了，要精练dijkstra算法的写法。

---------

417: Pacific Atlantic Water Flow

<https://leetcode.com/problems/pacific-atlantic-water-flow/description/>

DFS，位操作。从外侧（海洋）向内部蔓延。用`visited`数组中的元素最后一位表示能否从大西洋过来，
倒数第二位可以用于表示能否从太平洋过来，如果两个都可以过来，标识为3，
只能从大西洋过来标识为1，只能从太平洋过来标识为2，都过不来标识为0。

---------

110: Balanced Binary Tree

https://leetcode.com/problems/balanced-binary-tree/description/

dfs。一种优化可以使用memo避开一些重复计算。另一种优化转为计算树的高度的问题，高度为-1表示不平衡，可以实现短路计算。

---------

733: Flood Fill

https://leetcode.com/contest/weekly-contest-60/problems/flood-fill/

dfs, 注意将访问过的节点设置为特殊字符，然后再变回来，防止死循环。

---------

690: Employee Importance

https://leetcode.com/problems/employee-importance/description/

DFS暴力递归AC。效率低，时间复杂度为O(LN)，空间复杂度为O(L)，
L为下属员工总个数（包括非直接下属），N为员工总数。再刷尝试高效解法。

---------

513: Find Bottom Left Tree Value

https://leetcode.com/problems/find-bottom-left-tree-value/description/

DFS暴力递归AC，效率低。时、空间复杂度O(L^2)，因为递归深度为L，
查深度和查最左下元素都要递归到最底层。再刷要使用高效解法。二刷使用大神的DFS解法，不太理解，再刷！

---------

104: Maximum Depth of Binary Tree

<https://leetcode.com/problems/maximum-depth-of-binary-tree/>

BFS，DFS。

---------

226: Invert Binary Tree

<https://leetcode.com/problems/invert-binary-tree/>

DFS，递归。

---------

100: Same Tree

<https://leetcode.com/problems/same-tree/>

DFS，递归。

---------

133: Clone Graph

<https://leetcode.com/problems/clone-graph/description/>

DFS。graph的dfs, 注意图中可能有环，和138非常相似。

---------

17: Letter Combinations of a Phone Number Add to List

https://leetcode.com/problems/letter-combinations-of-a-phone-number/#/description

BFS，DFS。我更喜欢用bfs.

---------

93: Restore IP Addresses

https://leetcode.com/problems/restore-ip-addresses/#/description

DFS。count记录ip段数，start记录起始位，path记录当前解析的结果。

---------

22: Generate Parentheses

https://leetcode.com/problems/generate-parentheses/#/description

DFS。左括号只要有剩余就可以选，右括号只有在已生成的串中左括号多于右括号才可以选。

---------

113: Path Sum II

<https://leetcode.com/problems/path-sum-ii/description/>

DFS。遍历解空间，收集合法解。不用去重，比较简单。

---------

124: Binary Tree Maximum Path Sum

https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

DFS。递归函数`f`返回包括根节点`root`在内的单侧路径最大值。
在函数体内分别对左子树和右子树调用`f`分别得到左子树上的带根单侧路径最大值`left`和
右子树上的带根单侧路径最大值`right`，拿`right + left + root->val`和
用于存储全局解的`res`相比，更新`res`，返回`max(left, right) + root->val`。

---------

46: Permutations

https://leetcode.com/problems/permutations/description/

dfs。面试趋势是这种题目变为解决问题其中的一步。

---------

47: Permutations II

https://leetcode.com/problems/permutations-ii/description/

DFS。比46难一点，把解空间画出来会发现其实都是一样的，因为每个问题的子问题规模（分支个数）完全相同，
递归深度因为有了重复元素会增大。`map`可以去重，还可以统计频率，
`map`的key的个数就是分支数的上线。46中的`visited`的功能在本题中被`map`代替了。

---------

77: Combinations

https://leetcode.com/problems/combinations/description/

dfs。

---------

39: Combination Sum

<https://leetcode.com/problems/combination-sum/?tab=Description>

dfs。可以画出解空间来理解解题过程。

---------

40: Combination Sum II

<https://leetcode.com/problems/combination-sum-ii/?tab=Description>

DFS。首先要排序（对于去重很重要），之后要对照解空间写递归过程。

---------

216: Combination Sum III

https://leetcode.com/problems/combination-sum-iii/

DFS。解空间树画出来就有了。

---------

377: Combination Sum IV

https://leetcode.com/problems/combination-sum-iv/description/

DFS，DP。top-down的DFS超时，加入memo实现DP后，AC。这个题很经典，和之前整理的回溯法有强关联！
注意理解DP的含义，我现在仍然不知道这样做是不是就叫做DP。

除了上一种top-down的DP方法，还有一种bottom-up的DP方法，这种方法在我看来更像DP。
两种方法的空间复杂度都是O(N)，时间复杂度均为O(MN)，top-down方法虽然使用递归，但是这个时间复杂度容易分析。

---------

78: Subsets

https://leetcode.com/problems/subsets/

dfs。

---------

90: Subsets II

https://leetcode.com/problems/subsets-ii/description/

dfs，先排序，对着解空间写递归，注意去重。

---------

51: N-Queens

<https://leetcode.com/problems/n-queens/description/>

DFS。让`col`递增，逐个选择合法的`row`，存储`path`，`path`的含义是`(path[i], i)`
位置可以放一个Queen，之后将合法`path`，转为棋局排列。
DFS的解空间是一个N叉树，第`j`层表示第`j`列的可能情况，
第`j`层的每个节点的N个分支表示该列的Queen可能处于的行号，遍历解空间的时间复杂度为![](http://latex.codecogs.com/gif.latex?{O(N^2)})，
由于需要判断冲突，所以总的时间复杂度为![](http://latex.codecogs.com/gif.latex?{O(N^3)})。

判断冲突有三个条件：
1. ![](http://latex.codecogs.com/gif.latex?{row_1\neq{row_2}})，两个Queen不在同一行
2. ![](http://latex.codecogs.com/gif.latex?{row_1+col_1\neq{row_2+col_2}})，两个Queen不在一个斜对角线上
3. ![](http://latex.codecogs.com/gif.latex?{row_1-col_1\neq{row_2-col_2}})，两个Queen不在一个正对角线上

---------

52: N-Queens II

<https://leetcode.com/problems/n-queens-ii/description/>

dfs，思路与上题完全相同。

---------

79: Word Search

https://leetcode.com/problems/word-search/description/

dfs。和maze那道题对比，本题需要回溯，
原因是本题中解空间中两个分支同时经过运动空间的一个节点时，
表示的含义不同，两个分支很有可能是两个不同的单词（也有可能是一个单词，只是路径不同），
因此当第二个分支经过运动空间中的这个节点时，后续状态仍然需要遍历！
而maze那道题不需要，因为后续状态一定走不通，结果是必然的！
而且回溯不会造成死循环，回溯只是为了确保解空间的完整性！

---------

393: UTF-8 Validation

https://leetcode.com/problems/utf-8-validation/description/

DFS。1，2，3，4个字符表示一个UTF8码分别对应4个子问题。注意位操作的优先级没有判断符号优先级高！
位操作的优先级很低！注意递归要先设定基础情况，注意判断index不能越界！

---------

140: Word Break II

<https://leetcode.com/problems/word-break-ii/description/>

DFS。dfs+memo，因为要把所有可能的结果都保存下来，加入memo效率更高。
dfs照例可以画解空间树来做，递归函数`f`返回当前字符串的所有可能的分离结果`res`，
在`f`的函数体内，由后向前找出所有字典里出现的单词`word`，
对剩下的部分调用`f`得到子串的分离结果`children`，
对于`children`中的每一个字符串`child`在后面拼接上`word`就是`res`的一个元素。
$\forall i, s[i+1,j]\in word\_dict$, $f(s[0, j]) = f(s[0, i]) + s[i + 1, j]$

---------

491: Increasing Subsequences

https://leetcode.com/problems/increasing-subsequences/description/

dfs，有点小trick，去重时要遍历之前的所有元素，查看是否有重复，因为题目不允许sort。

---------

95: Unique Binary Search Trees II

<https://leetcode.com/problems/unique-binary-search-trees-ii/description/>

BFS，DFS。
* BFS：从1到n，逐渐扩充res，然后遍历上一个节点加入后的res列表，
在每棵树上添加新的节点（每个可能的右子树），时间复杂度$O(N^2\log N)$~$O(N^3 \log N)$。
* DFS：递归函数`f`返回由区间$[begin, end]$中所有整数生成的所有BST的列表。
`f`内部对$\forall$`i`$\in[begin, end]$，选其为根，对区间$[begin, i-1]$
调用`f`生成所有左子树`left`，对区间$[i+1, end]$调用`f`生成所有右子树`right`，
然后按照96的思路将所有左、右子树的组合就是结果。

---------

869: Reordered Power of 2

https://leetcode.com/contest/weekly-contest-93/problems/reordered-power-of-2/

DFS。将一个整数`N`的各位上的数字打乱，将这些数字重新组合，是否存在一个组合能使组合得到的数字`n`(0不可以出现在首位)是`2`的幂。
这是个典型的DFS的题目，用一个map记录数字到频率的映射，然后DFS遍历所有组合，在DFS的过程中判断`n`是否是`2`的幂，
判断依据很简单，当且仅当`n`的二进制表示中只有一位为1时，`n`为`2`的幂。如果`n`是`2`的幂，则立即中断DFS。

我一开始的解法设计是先用DFS遍历出所有可能的组合，再从中查找是否有满足条件的组合，这种做法的时间和空间复杂度都极高，以至于TLE了。 

---------

866: Smallest Subtree with all the Deepest Nodes

https://leetcode.com/contest/weekly-contest-92/problems/smallest-subtree-with-all-the-deepest-nodes/

dfs，多个节点的LCA。递归找path，选出最后一个相同节点，在这个场景下这个解法还不错。

---------

37: Sudoku Solver

https://leetcode.com/problems/sudoku-solver/description/

dfs。注意使用上题的方式判断valid。注意`row_used`, `col_used`和`box_used`要先初始化！

---------

130: Surrounded Regions

https://leetcode.com/problems/surrounded-regions/description/

DFS，BFS。而是从四条边界出发使用DFS或BFS即可，状态不必回溯。

---------

332: Reconstruct Itinerary

https://leetcode.com/problems/reconstruct-itinerary/description/

dfs和heap结合，时间复杂度？思想是path先添加无路可走的节点，使用链表的头插法。
c++的list数据结构基于链表实现，接口很多，非常方便，相当于java中的LinkedList。
分别使用c++和java刷过，但是都没有一次AC。三刷忘记了基于heap的方法，使用纯DFS加排序。
两种算法的时间复杂度在搜索解空间时有较大区别，还需要认真分析。

---------

129: Sum Root to Leaf Numbers

https://leetcode.com/problems/sum-root-to-leaf-numbers/description/

dfs，遇到叶子节点就把num(表示path)加到res上。如果follow up将节点的数只有1位的限制去掉，可以使用vector表示path。



691: Stickers to Spell Word

https://leetcode.com/problems/stickers-to-spell-word/description/

带memo的DFS。时、空间复杂度为O(N)，递归深度也是N。


473: Matchsticks to Square

https://leetcode.com/problems/matchsticks-to-square/description/

* 递归，效率低，有大量重复计算，TLE。
* DFS: 仍然有优化的空间，重复计算问题并没有完全解决。


695: Max Area of Island

https://leetcode.com/problems/max-area-of-island/description/

DFS，利用queue存储中间结果，原地更改数组。时间复杂度为O(M\*N)，空间复杂度为O(1)。


694: Number of Distinct Islands

https://leetcode.com/contest/leetcode-weekly-contest-53/problems/number-of-distinct-islands/

一刷没有想到怎么表示多个岛之间的“translation”的关系，题意不太理解，跟695很像，
只需要用set记录编码之后的island的所有node，最后返回set的长度即可。
还学到了访问matrix一个元素四周邻居的更省空间的方式，数组bias设置为[1, 0, -1, 0, 1]即可，
每次访问row的bias为bias[i],column的bias为bias[i + 1]，非常巧妙！


