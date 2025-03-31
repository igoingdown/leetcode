#### BFS专题

799: Champagne Tower

<https://leetcode.com/contest/weekly-contest-75/problems/champagne-tower/>

双 vector 实现 BFS。先把第一层放满，自顶向下把每一层过满的香槟杯倒入下一层，分流的规则是下层的左子和右子分别获得一半溢出的香槟。

102: Binary Tree Level Order Traversal

https://leetcode.com/problems/binary-tree-level-order-traversal/description/

双queue实现bfs。


127: Word Ladder

https://leetcode.com/problems/word-ladder/description/

双queue实现BFS。这种需要记录BFS中遍历层数的题不用着急在构建next的时候返回，
在访问当前层的时候返回效果没多大差别，而且逻辑会更清晰。


126: Word Ladder II

https://leetcode.com/problems/word-ladder-ii/

方法一：BFS+DFS。先用BFS生成每个次到其前缀的map(string, set<string>)，
利用这个map使用DFS生成所有路径,vector前向插入不便的情景可以使用list，方法比较复杂，其实完全不需要使用DFS，纯BFS就行。
方法二：单向BFS。双queue实现BFS，同时用两个对应的queue记录从beginWord到达之前两个queue中每个元素的path。
注意visited的修改，层内不用更新visited，要使用`layer_visited_words`记录每层有哪些新的元素被访问到了，
在一层访问完之后用`layer_visited_words`一并更新visited。其实直接用两个queue存path即可，
每个path的终点就是最后一层的元素，也就是说只存元素的queue是完全多余的。
方法三：双向BFS，分别保存从beginWord和endWord两个方向出发的path，如果两条path能接上，则结果找到。有点tricky。


841: Keys and Rooms
https://leetcode.com/contest/weekly-contest-86/problems/keys-and-rooms/

BFS. 从0号房间取钥匙，然后访问0号房间中钥匙对应的房间，以此类推，典型的BFS，一开始没反应过来！


515: Find Largest Value in Each Tree Row

https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/

BFS。


199: Binary Tree Right Side View

https://leetcode.com/problems/binary-tree-right-side-view/description/

BFS。


843: Guess the Word

https://leetcode.com/contest/weekly-contest-86/problems/guess-the-word/

不太常见，找工作刷题一开始过滤掉这种题。
BFS，实际上是个概率题，初始情况下，随机选定一个word作为target，
wordlist中的每个词与target match的character的个数分别为0,1,2,...,6。
概率分布为$\{1 * 25^6/26^6, 6 * 25^5/ 26^6, ..., 1 * 1/ 26^6\}$，
随机选出一个word调用guess，设该word与target match的字母数为r，
从原始wordlist中过滤出所有与word match的字母数为r的单词（target一定包含在其中）组成新的wordlist，
以此类推，知道找到target或者guess次数超过10次。由初始状态知道，match为0的概率最大，
因此每次随机选择的word与target的match的字母数均为0的概率最大，
为$26 * 25 * 24 * ,..., * 17 / 26 ** 10 = 6.48e-6$。因此guess一定会得到target。


865: Shortest Path to Get All Keys

https://leetcode.com/problems/shortest-path-to-get-all-keys/description/

BFS。和Maze那一系列的题目非常相似，尤其是MazeII。给定一个由二维字符数组`grid`表示的区域，
`'@'`表示起点，`'#'`表示墙，`'.'`表示空白，小写字母表示钥匙，与小写字母对应的大写字母表示锁。
计算从起点出发到集齐所有钥匙走的最短步数。我的BFS方法中使用Queue记录需要遍历的状态，
每个状态包括当前位置与当前拥有的钥匙串，这个状态是唯一的，可以用visited集合记录已经遍历过的状态，
BFS直到状态遍历完或者集齐所有的钥匙为止，BFS的层数就是结果。我的算法效率不高，TLE了。

跟AC算法相比，我对题目的数据限制分析不够到位，AC算法有以下两个优化：
1. 题目限制锁的个数最多为6个，这是一个非常重要的限制条件，
这意味着不需要用set记录当前收集到的钥匙，只需要一个整数即可(后6个比特每个比特分别表示一个锁)。
2. 由于`grid`的长和宽均限制在30以内，加上**1**中的分析，state的空间其实不大($30 * 30 * 2^6$)，
直接使用一个三维数组`distance`存储即可，`distance`的元素初始化全部为-1，表示没有遍历过，
这个条件可以用于判断是否要讲新发现的状态加入下一层要遍历的队列中。
另外`distance`还可以记录起点到当前点的距离，用于返回结果。

以上这两点优化非常重要，将BFS过程中非常频繁的查找操作的时间复杂度从$O(logN)$降到了$O(1)$。


301: Remove Invalid Parentheses

https://leetcode.com/problems/remove-invalid-parentheses/description/

* DFS: 注意从左向右走，分三种情况考虑，左括号，右括号和字母。
* BFS


851: Loud and Rich

https://leetcode.com/contest/weekly-contest-88/problems/loud-and-rich/

BFS。 拓扑排序，可以使用visit记录下一步要访问的节点优化执行速度。


662: Maximum Width of Binary Tree

https://leetcode.com/problems/maximum-width-of-binary-tree/description/

BFS。纯BFS当树的高度过大时，内存溢出。优化方法是
利用满二叉树的性质（子节点和父节点index之间的关系，
$left\_child\_node\_index = parent\_node\_index * 2$， $right\_child\_node\_index = parent\_node\_index * 2 + 1$。


116: Populating Next Right Pointers in Each Node

<https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/>

BFS。双queue实现的BFS空间复杂度为O(N)，不满足要求。利用next指针可以实现BFS，空间复杂度仅为O(1)。

使用三个指针即可实现BFS，`cur`记录本层的访问位置，`next_start`指向下一层的起始位置，
`next_end`指向下一层的末端。每次访问`cur`，如果有左子或右子，都要根据`next_start`进行判断：
1. `next_start == NULL`:将该子节点作为`next_start`并且让`next_end`也指向该节点
2. `next_start != NULL`: 将该子节点添加到`next_end`之后。 


117: Populating Next Right Pointers in Each Node II

<https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/>

BFS。和116完全相同。


847: Shortest Path Visiting All Nodes

https://leetcode.com/contest/weekly-contest-87/problems/shortest-path-visiting-all-nodes/

BFS + DP。使用2进制的方法记录每个节点是否被访问，相当于中间状态。
每次访问一条边，如果经过头结点的状态到达尾节点的距离大于经过头结点的状态到头结点 + 1，则更新经过头结点状态到达尾节点的距离。

871: Minimum Number of Refueling Stops

https://leetcode.com/problems/minimum-number-of-refueling-stops/description/

BFS。题目的场景和**leetcode 134**很像，给定一辆油箱无限大的卡车，初始油量为$G$，
需要前往离起点$S$距离为$T$的目的地$D$，起点和终点之间有若干加油站，
加油站$G_i$到起点的距离和储油量分别记为$d_i和g_i$，求从起点到终点需要加油的最少次数。

分析可知这是个BFS的题目，遍历解空间一定可以得到解，我用双queue实现了BFS，
但是很遗憾空间复杂度过高，内存超了。
分析可知这个题目有一个性质在提示我们可以用`priority_queue`代替`queue`实现BFS，
这个性质就是：在BFS的过程中，解空间中一个父节点的所有子节点是有优劣比较的，
因为目标是要加油的次数最少，我们必须要优先选择储油量最大的子节点(加一次油可以撑到更远的距离)，
只有当储油量最大的子节点的储油量不足够到达下一个加油站的时候，才会继续选择储油量更小的节点，
就是说最好的情况是加一次(选择储油量最大的子节点)就可以撑到下一个加油站，
最坏的情况是所有子节点都选中了，即上次加油后，沿途的每个加油站都停下加油，
结果还是撑不到下一个加油站，这种情况下就必然无法到达目的地了！
因此可以用`priority_queue`来实现BFS。每次访问一个父节点，
将所有可能的子节点都加入`priority_queue`中，选择储油量最大的子节点，
更新这次加油后能到达的最远距离$d$和加油次数$c$，直到$d \geq T$为止。
`priority_queue`实际保存了从起点到当前位置为止，
沿途没有加过油的加油站按储油量由大到小排序的优先级队列。


752: Open the Lock

https://leetcode.com/contest/weekly-contest-64/problems/open-the-lock/

BFS，很简单，比赛的时候网站报的出问题case不对，
出问题的原因是没有对"0000"这一状态进行检测就加入了队列，
但是网站上给的提示case不是这个。感觉DP也能做，但是想不到能从小到大填空的思路。


773: Sliding Puzzle

https://leetcode.com/contest/weekly-contest-69/problems/sliding-puzzle/

BFS。


542: 01 Matrix

<https://leetcode.com/problems/01-matrix/description/>

BFS。从`0`出发，初始化将所有位`0`的cell入队，作为第0层，然后BFS将后面访问的cell的值设为层数即可。


675: Cut Off Trees for Golf Event

https://leetcode.com/contest/leetcode-weekly-contest-49/problems/cut-off-trees-for-golf-event/

* BFS。对于树而言BFS就是层序遍历，
* DFS就是后续遍历！代码我到最后都不知道为什么AC了！


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


637: Average of Levels in Binary Tree

https://leetcode.com/problems/average-of-levels-in-binary-tree/description/

双queue实现BFS。


310: Minimum Height Trees

https://leetcode.com/problems/minimum-height-trees/description/

BFS。graph的拓扑排序。


623: Add One Row to Tree

https://leetcode.com/problems/add-one-row-to-tree/description/

双queue实现BFS。注意要保存更上一层的节点，添加子树时不必考虑子树是否为空！



207: Course Schedule

https://leetcode.com/problems/course-schedule/description/

BFS。graph拓扑排序，算法复杂度有点高，可继续优化！一次AC。


210: Course Schedule II

https://leetcode.com/problems/course-schedule-ii/description/

BFS。graph拓扑排序，和上一道比仅仅是输出结果有变化。


269: Alien Dictionary

http://blog.csdn.net/qq508618087/article/details/50981000

BFS。graph的拓扑排序。


