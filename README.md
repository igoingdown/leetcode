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

https://leetcode.com/problems/island-perimeter/

就是逐一遍历所有的cell，用分离的cell总的的边数减去重叠的边的数目即可。在查找重叠的边的数目的时候有一点小技巧，就是沿着其中两个方向就好，这种题目都有类似的规律，就是可以沿着上三角或者下三角形的方向来做。一刷一次ac，但是还没开始注意codestyle的问题，需要再刷一遍。


455: Assign Cookies

https://leetcode.com/problems/assign-cookies/

给出两个序列，一个序列中的元素代表cookie的size，另外一个序列代表能满足孩子要求的最小cookie的size，问如何分配使得到的满意的孩子最多。先将两个序列都按从小到大顺序排序，然后按双路指针的方式解决。一刷一次ac，但是对于C++默认的sort函数的排序方式（从小到大还是从大大小）并不是很清楚。
算法库中的sort(beg, end, comp)函数实际使用快排，其中的comp是函数或者函数指针，签名是 bool comp(elem_type first_arg, elem_type second_arg)，返回的bool值的含义是第一个参数是否应该排在第二个参数的前面。而且默认参数会将较小的参数排在前面，即sort函数默认是从小到大排序！

453: Minimum Moves to Equal Array Elements

https://leetcode.com/problems/minimum-moves-to-equal-array-elements/

一开始自己对题目的理解出错了，浪费了不少时间。每次移动要求同时将n-1个元素加1，我看成了每次移动将其中2个元素加1。搞清楚题目真正含义之后，不太会做，参考了一下其他人的解题思路：给数组中的n-1个元素加1的操作等价于数组中“不加1的那个元素“减去1，然后数组中的所有元素都加1。我们知道，给所有的元素都加1并不能改变原数组中的数之间的差值。所以这题就转化为求最少的减1操作。而要使数组中的元素全部相等，又要使用减法。那么最少的次数就是让这些元素全部都等于数组中最小的数。所以得到的结果就是sum（所有元素和）-n*数组中最小元素。
注意看题目！一刷由于c++的api用的不熟。

383: Ransom Note

https://leetcode.com/problems/ransom-note/

就是用后一个串合成前一个串，条件是后一个串的每个字符只能用一次，这种题都可以利用c++的字符和int型转换来构建一个长为26的数组，每个数组表示一个key（前提是全大写或者全小写）。
一刷for循环中的计数器i没有声明类型（int），编译错误。二刷一次ac。


404: Sum of Left Leaves

https://leetcode.com/problems/sum-of-left-leaves/

* 递归:
  1. 只要想明白一个节点的情况，其他节点都一样。对于每个节点如果指针为空，返回0；如果该节点非空且左子树为叶子节点，则返回左叶子节点和右子树递归结果的和，否则返回左右子树的递归结果的和。
  2. 还有一种写了两个函数的算法，其实差不多。一刷第一次调用dfs函数参数给错了，只有一个root节点不算左叶子结点。
* 非递归。利用栈，处理栈顶元素的时候直接处理栈顶元素，应该处理栈顶元素的左右结点。


834: Sum of Distances in Tree
https://leetcode.com/contest/weekly-contest-84/problems/sum-of-distances-in-tree/

用图的思路解决树的问题。先用DFS算出跟节点到其他节点的距离之和tot，并且在计算过程中连带算出以每个节点为根节点的子树的节点个数c[0, i, .., n - 1]，这两个问题都是比较简单的问题。然后DFS遍历所有节点，已知根节点到所有其他节点的距离之和的情况下，算任意一个子节点到其他所有节点的距离之和的公式是: s[v] = (s[u] - c[v]) + (n - c[v])。这是因为已知根节点u到所有其他节点的距离之和s[u]，求所有其他节点到一个u的一个子节点v的距离之和s[v]，可以将所有节点分为两部分，其中一部分是以v为根节点的子树，另一部分是整个树的其余部分。以v为根节点的子树上的每个节点到u的距离减1就是这些节点到v的距离，树的另一部分上的每个节点到u的距离+1就是他们到v的距离。反映在最终结果(距离加和)上，前一部分需要在s[u]的基础上减掉c[v]，后一部分需要在s[u]的基础上加上(n - c[v])，于是就有了上面的公式。


409: Longest Palindrome

https://leetcode.com/problems/longest-palindrome/

比较简单，如果字母个数为偶数，直接加，字母个数为奇数，加上减一后的值，由于回文串中间可以放一个长度为一的子串，因此如果有个数为奇数的字母，最后结果要加一。
一刷统计小写字母的出现次数时，条件写反了。计算最后结果时注意处理出现次数为奇数的字符。二刷一次ac。


448: Find All Numbers Disappeared in an Array

https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

要求不能使用额外空间，只能在原数组上进行改动，将提到的元素对应的索引上的值加上负号，对后续的遍历操作影响不大（取绝对值就行）。由于在遍历到i之前已经将i后到元素置为负值，因此要在遍历到时候就加上绝对值。一刷中括号写成了小括号（取数组元素写成了函数调用，这两者的区别大了），在加入结果的时候少写了if语句。二刷一次ac。


442: Find All Duplicates in an Array

https://leetcode.com/problems/find-all-duplicates-in-an-array/

题目和上面那道题差不多，而且更简单！可是我没想到。和上一题的区别在于在处理重复赋值时直接就加入结果队列了。一刷一次ac。


414: Third Maximum Number

https://leetcode.com/problems/third-maximum-number/

找出n个数中的第m（m < n）大的数，这是个经典问题，我去望京面试的时候就被问到，我当时真菜，不然暑假可以拿好多钱，哼！当m不太大（m<4）时，都可以按同一种思路解决 ，就是同时设置多个max，遍历数组元素，分条件更新max。注意两点，一是max的初始化一定要比当前数组元素类型的最小值要小；二是max更新条件要写全，“=”的情况要排除。
一刷各max的更新顺序写反了，max更新条件没写全，没有用更大范围的数据类型。二刷一次ac。


289: Game of Life

https://leetcode.com/problems/game-of-life/

一刷判断自身的条件写错，死而复生的判断条件写错，代码效率不高。二刷代码结构有优化，但是效率还是不高，判断语句中==写成赋值号=，cell周环遍历数列写错（1写成-1）。三刷没有ac是因为不理解c++_11新特性。(auto n : vec)中的n是临时变量，修改n不能改变原来vector中的元素，因此在不需要修改vector中元素时遍历可以用auto，但是要修改vector中的元素，还是需要迭代器或者下标。


287: Find the Duplicate Number

https://leetcode.com/problems/find-the-duplicate-number/

BS，TP。TP将问题转化为链表内部环检测的问题。


2: Add Two Numbers

https://leetcode.com/problems/add-two-numbers/description/

链表。


24: Swap Nodes in Pairs

https://leetcode.com/problems/swap-nodes-in-pairs/description/

一次走两步。注意原链表只有一个元素时新链表为空，要对这种情况进行判别。


268: Missing Number

https://leetcode.com/problems/missing-number/

一开始掉进了前面的解法的坑里，老想着把元素当作索引，将正值变负值，然后找改变后的数组中的正值对应的元素，由于同时有n和0，这两种情况不能有效区分，而且也没说可以改动数组，故抛弃了这种解法。求和再做减法更方便，由于担心溢出，用了范围更大的数据结构，好像没什么用。


229: Majority Element II

https://leetcode.com/problems/majority-element-ii/

看了一篇博客，恍然大悟，很开心，就喜欢这种感觉。原博地址：http://blog.neoshell.moe/leetcode229.html
BM多数投票算法（Boyer-Moore Majority Vote algorithm）。要注意变量的初始化，将n1，n2初始化为任意两个不同的数就行，对应counter设置为0是关键。还要注意一点第一次遍历结束只是明确了n1，n2是出现频率最高的数，但是对应的counter是不准的，需要重新计数！最后需要查看counter是否满足条件。


228: Summary Ranges

https://leetcode.com/problems/summary-ranges/

用b记录本次范围的起始位置，用i作为索引。注意更新i和b时先更新i再更新b，而且是拿第i个元素和第i+1个元素比较，这样就不必在循环体外单独处理最后一个元素了。


216: Combination Sum III

https://leetcode.com/problems/combination-sum-iii/

一刷使用dfs解决。我总是不太会构造递归，要注意这种题型！用递归解决问题，只要关注解决本层次的问题就好，通过条件筛选和循环将本层解决完，调用本身进入下一层。这种说法很简单，其实不容易做到！
注意剪枝条件，比如left可能等于i，每步循环中，需先将元素插入列表尾部，在下一层递归结束后，要将插入的元素从尾部取出！


547: Friend Circles

https://leetcode.com/problems/friend-circles/description/

一刷使用DFS，也可以使用并查集解决。


721: Accounts Merge

https://leetcode.com/problems/accounts-merge/description/

一刷使用DFS，C++版debug很久，用python写debug方便很多，但是超时了。二刷使用并查集。上面那道题是并查集的简单题，这道属于并查集比较难的题。


839: Similar String Groups
https://leetcode.com/contest/weekly-contest-85/problems/similar-string-groups/

并查集。并查集在逻辑上构造一个森林，先将每个节点都初始化为森林中的一棵树，group为N。然后遍历所有的边，对于每一条边，如果两个节点所在树的根节点不同，就将后一个节点所在的树的根节点作为前一个节点所在树的根节点的子节点，同时group减一。这样就可以解决并查集的第一类题目，就是求group的数量。另一种题目要求不仅分出group，并且要给出每个group具体有哪些节点，这时候需要遍历每个节点，找出其所在树的根节点，按根节点分离每个group即可。547，839属于第一类，721属于第二类。


720: Longest Word in Dictionary

https://leetcode.com/problems/longest-word-in-dictionary/description/

Trie和DFS结合，一次AC。


677: Map Sum Pairs

https://leetcode.com/problems/map-sum-pairs/description/

Trie和BFS结合，一次AC。


842: Split Array into Fibonacci Sequence

https://leetcode.com/contest/weekly-contest-86/problems/split-array-into-fibonacci-sequence/

DFS. 记录起始位置，分离结果，设置终止条件，将问题转为子问题。


743: Network Delay Time

https://leetcode.com/problems/network-delay-time/description/

一刷使用DFS没AC，debug很久,没理解错哪了，二刷使用BFS就AC了。三刷使用Dijkstra算法，效率不如BFS，实现效率不高，可以继续改进。BFS是Dijkstra的降级。
原来leetcode后端是用python写的！以后用pycharm写python或者intelij idea写java来debug也不错！


542: 01 Matrix

https://leetcode.com/problems/01-matrix/description/

一刷使用朴素的BFS一次AC，二刷加了一点trick，in-place的方式，题目要找到所有格到0格的最短距离，从0格出发不断修改到达非0格的距离，这种转换在DFS和BFS类的题目中非常常见！时间复杂度？？


30: Substring with Concatenation of All Words

https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/

一刷先用KMP得到每个关键字在母串中出现的所有位置，然后使用DFS得到解，这种方式会超时。二刷使用TP，使用两个map，一个map记录每个模式串的个数，另一个用于匹配，两层循环，外循环遍历母串（注意遍历的范围是0~ss - ws * l），内循环进行匹配，每次匹配都从母串中取出长为l的子串，看是否在map中，在map中则修改map，知道map为空，这时产生了一个答案，继续外循环即可。


417: Pacific Atlantic Water Flow

https://leetcode.com/problems/pacific-atlantic-water-flow/description/

一刷使用相反的方式，从内到外查看一个节点是否能到达P或者A，终止条件不对，debug很久。二刷使用由外到内的方式，没理解终止条件中的mark参数的意义。

209: Minimum Size Subarray Sum

https://leetcode.com/problems/minimum-size-subarray-sum/

一开始把题目意思理解错了，浪费了很多时间。subarray是原array的连续子序列，就像substring是原string的连续子序列一样。基于错误的理解，我使用dfs来解决，后来超时才反应过来。一定要好好看题，正确理解题意，往往事半功倍！正确地理解了题意之后，一刷很快ac。二刷更新min_size时没有判别，代码有小幅更新（能用while就不要用for）。
用sum和left记录当前subarray的和与起始位置，注意同时更新sum和left，每次更新min_size之前需要对当前subarray的size进行判别。


162: Find Peak Element

https://leetcode.com/problems/find-peak-element/

BF，$O(N)$。写了一半发现可疑从两头一起开始遍历，但是时间复杂度并没有明显改善。
BS，$O(logN)$。可以把自己的二分法固定下来，while里面填`low < high`, 更新方式为`high = mid`， `low = mid + 1`， 返回low。这样以来，写代码的时候实际要判断的只有更新条件了！二分法还可以用递归的方式表现。

154: Find Minimum in Rotated Sorted Array II

https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

原来algorithm库中是有min（max）函数的，也有min(max)_element函数的！但是min（max）函数只接受两个参数，没什么实用价值，min(max)_element函数也没什么大的使用价值，返回迭代器。
其实比较简单，一刷一次ac。说实在的，自己被这个hard标志吓得不轻。

164: Find Minimum in Rotated Sorted Array

https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

和154一模一样。


152: Maximum Product Subarray

https://leetcode.com/problems/maximum-product-subarray/

原理是dp，但是我对dp并不熟！关键在于当前的max和min并不是全局的max和min，每遍历一个元素就要更新全局的max（res）。一刷变量名写错，效率也不高。二刷由于不理解DP，更新过程写错！三刷一次AC。



344: Reverse String

https://leetcode.com/problems/reverse-string/

字符串翻转，很简单。使用内置函数swap简化了代码，一次AC。


136: Single Number

https://leetcode.com/problems/single-number/

位运算（异或）经典题目。想象一个多层公寓，每个公寓住着0或者1，异或像如来神掌一样将每一位从上而下压缩。


137: Single Number II

https://leetcode.com/problems/single-number-ii/description/

每一位都有规律，仍然可以按照上题的思路思考，每一位上都是这样的规律$sum = x_1 * 3 + x_2 * 3 + ... + x_{n-1} * 3 + y$，要得到y对sum模3即可。


260: Single Number III

https://leetcode.com/problems/single-number-iii/description/

位操作，按第一个不同的位将nums分为两派即可。思路同前两道题。


461: Hamming Distance

https://leetcode.com/problems/hamming-distance/description/

位运算，与和异或。


477: Total Hamming Distance

https://leetcode.com/problems/total-hamming-distance/description/

位运算，分两派，该位为0和该位为1，分别记录每派的count，相乘加到结果上即可。


190: Reverse Bits

https://leetcode.com/problems/reverse-bits/description/

位运算。一刷边界设置错误没AC。


201: Bitwise AND of Numbers Range

https://leetcode.com/problems/bitwise-and-of-numbers-range/description/

位运算


405: Convert a Number to Hexadecimal

https://leetcode.com/problems/convert-a-number-to-hexadecimal/description/

位运算，注意0的问题，算术右移和逻辑右移的区别。


421: Maximum XOR of Two Numbers in an Array

https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/

位运算比较难的题，没太明白关键一步异或的操作的含义。再刷。


7: Reverse Integer

https://leetcode.com/problems/reverse-integer/description/

和190相似，一刷没AC。注意考虑极限情况，包括INT_MAX和INT_MIN。


476: Number Complement

https://leetcode.com/problems/number-complement/description/

位运算，求补码，从符号位开始0变为1，然后取反。


342: Power of Four

https://leetcode.com/problems/power-of-four/description/

位运算，搞了很久，没抓住主要性质。


318: Maximum Product of Word Lengths

https://leetcode.com/problems/maximum-product-of-word-lengths/description/

位运算，一刷做的不是最优解！


104: Maximum Depth of Binary Tree

https://leetcode.com/problems/maximum-depth-of-binary-tree/

一刷使用层序遍历（BFS），一次AC，效率不高。二刷使用DFS，一行解决问题，效率也非常高，一次AC。


389: Find the Difference

https://leetcode.com/problems/find-the-difference/

对于字符串的常用方法，将字符转为数组下表，从而将空间复杂度降到O(N)。二刷一次AC。


226: Invert Binary Tree

https://leetcode.com/problems/invert-binary-tree/

使用递归，较简单，二刷一次AC。


169: Majority Element

https://leetcode.com/problems/majority-element/

math,鸽巢原理，投票法。同权投票众数的票数最多，一定胜出。


100: Same Tree

https://leetcode.com/problems/same-tree/

使用递归，教简单，二刷改善了codestyle，逻辑也更清晰，一次AC。


128: Longest Consecutive Sequence

https://leetcode.com/problems/longest-consecutive-sequence/

HashMap，空间换时间。可以使用师姐的思路，每次遇到没访问过的元素，访问之，并查看该元素所在最长连续序列的长度，更新结果，$O(N^2)$。使用unordered_map记录访问元素的最大长度。当n-1和n+1都访问过后，将序列两端的元素对应的最大长度更新。因为之后序列内部的元素就不考虑了，只会考虑序列外的元素，而序列外的元素跟该序列可能链接的地方只有左右两端，这个题很像DP，注意要将该元素设为访问过的状态，要向map中添加pair，$O(N)$。


719: Find K-th Smallest Pair Distance

https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/

Hashmap，已知距离的范围，用vector对所有的距离进行计数，最后找出第k小的距离。


381: Insert Delete GetRandom O(1) - Duplicates allowed

https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/description/

Hashmap，使用Hashmap记录val到index set的映射，使用pos记录array最后一个元素的下一个位置。调用Random找随机元素


120: Triangle

https://leetcode.com/problems/triangle/

DP。自底向上，`dp[c] = min(dp[c], dp[c+1]) + triangle[r][c]`，$O(N^2)$。


799: Champagne Tower
DP。与120类似。
`dp[r][c] = (dp[r-1][c-1] >= 1 : dp[r-1][c-1] - 1 : 0) / 2 + (dp[r-1][c] >= 1 ? dp[r-1][c] - 1 : 0) / 2`。



105: Construct Binary Tree from Preorder and Inorder Traversal

https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

递归。


106: Construct Binary Tree from Inorder and Postorder Traversal

https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

递归。同105，由于树中无重复元素，可以用map记录inorder中元素到index的映射，这样就不用在生成树时遍历inorder查找元素了，这样可以把时间复杂度降为$O(N^2)$。


108: Convert Sorted Array to Binary Search Tree

https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

递归，二分查找。


109: Convert Sorted List to Binary Search Tree

https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/#/description
同108，只是这里mid要通过快慢指针来找。


114: Flatten Binary Tree to Linked List

https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

递归，将左右分别flattern之后，将左侧链接到右侧。


761: Special Binary String

https://leetcode.com/problems/special-binary-string/description/

* BFS:每次选字符串中两个special binary substring交换，如果结果没有访问过就将其放入队列中，这种解法是我自己的解法，有大量重复计算，超时。
* 递归：题目中暗藏两个规律:
	1. 所有special binary string均以1开头，以0结尾
	2. 允许交换两个相邻的special binary substring，可以得到所有special binary substring的全排列，因此最大的special binary string就是所有special binary substring按递减排序得到的结果。
	分析得知以上两点就容易想到递归算法，将special binary string分成尽可能多的special binary substrings,对每个special binary substring进行递归得到special binary substring的最大值，然后将按降序排序后的special binary substrings连接起来就是要求的结果。

75: Sort Colors

https://leetcode.com/problems/sort-colors/

排序，手写快排、堆排等时间复杂度都是O(NlogN)。
暴力法第一次遍历记录0，1，2的数量，第二次遍历按照数量赋值上去，$O(N)$。
TP，$O(N)$。令index_0和index_2分别表示下一个0和2应该填进去的坑，扫一遍数组，将0放在swap到前面，2swap到后面，1自然就被swap到中间了。
变式题是阿里的二面算法题。RGB无序序列排成RGBRGB形式的序列，三指针。


74: Search a 2D Matrix

https://leetcode.com/problems/search-a-2d-matrix/?tab=Description
BS，将矩阵降为视为一维数组用BS。index的映射关系:`matrix[mid / n][mid % n]`。


240: Search a 2D Matrix II

https://leetcode.com/problems/search-a-2d-matrix-ii/description/

math，BS的变形，所选的哨兵为角上的元素，每次将范围缩减一行或一列，$O(\max(M,N))$。暴力方法是对每一行进行BS，$O(MlogN)$。


73: Set Matrix Zeroes

https://leetcode.com/problems/set-matrix-zeroes/?tab=Description
将第一行第一列作为标志，第一行第一列用其他标志。顺序遍历将标志置0，逆序遍历按标志将元素置0。算法复杂度高些，但是好理解。


62: Unique Paths

https://leetcode.com/problems/unique-paths/?tab=Description
DP。


63: Unique Paths II

https://leetcode.com/problems/unique-paths-ii/?tab=Description
DP。同62。


64: Minimum Path Sum

https://leetcode.com/problems/minimum-path-sum/?tab=Description
DP。同62。


53: Maximum Subarray

https://leetcode.com/problems/maximum-subarray/?tab=Description
DP，可以降为0维DP。累加，当加到a[i]时候如果当前sum小于0。就把[0-i]都扔掉 重新加起。画了个函数图像，感觉稍微好些。序列中的每个数都是sum的导数，这么看的话就可以理解。DP算法好些可以解释连续的问题。和LCS很相似，DP解法构造子问题形式的思路相同，$DP[i]$表示以[i]结尾的sub序列。


72: Edit Distance

https://leetcode.com/problems/edit-distance/description/

DP，知道思路，没能将问题降级为子问题。需要继续理解！


486: Predict the Winner

https://leetcode.com/problems/predict-the-winner/description/

二维DP，一维亦可，二维DP易于理解。两个维度坐标含义相同，填表方式是沿对角线填表，这取决于子问题的结构。子问题比较容易看出来，对于$dp[i][j]$,取头剩$dp[i+1][j]$,取尾剩$dp[i][j-1]$，但是剩下的是对手的盘，因此要将dp中存储的元素设置为一手比二手玩家多得的分，这样对手的盘就是负值！


45: Jump Game II


https://leetcode.com/problems/jump-game-ii/description/


DP,BFS。DP复杂度为O(N^2)，自己写的DP，遍历nums，填充并修改dp，如果dp[i]都有效，遍历[1, nums[i]]，更新dp[i+j]，这种方式会超时。师姐的dp跟我不太一样，为了得到dp[i]，遍历dp[0, i-1]，如果一步可以到i则直接跳出，师姐的dp思路才是真正的dp思路。BFS的复杂度为O(N)，从0开始，对于每层更新能到达的最远的元素，然后从那个元素开始，直到能够到最后一个元素位置。


85: Maximal Rectangle


https://leetcode.com/problems/maximal-rectangle/description/


DP。把原来的1010矩阵变成直方图矩阵。外层遍历每一行，内层遍历每一列，下一行只要需要使用上一行的信息，所以可以简化为一维DP。height,left和right更新的先后顺序无所谓。关键是理解left[j]和right[j]为什么可以表示最高的（高度为height[j]）的全1向量的左右边界,原因是当matrix[i][j]为1时，left和right的更新会取当前行的边界cur和上一行的对应列的最小值(对right)或者最大值(left)。


837: New 21 Game
https://leetcode.com/contest/weekly-contest-85/problems/new-21-game/

DP。给定K,N,W，当牌的点数小于K时，从$[1, W]$的牌中等概论随机抽取一张，计算手牌的面值之和$<=N$的概率。使用pre记录当前牌面值总和之前的概率总，相当于前缀和，使用dp记录当前牌面值的概率。dp[i]最多只跟$[i - 1, i-1-W]$的牌面值概率的总和sum有关，$dp = sum / W$, 使用b记录相关牌面值的起点，使用e记录牌面值的终点。每次计算dp之后，$pre[i + 1] = pre[i] + dp[i]$。


730: Count Different Palindromic Subsequences

https://leetcode.com/problems/count-different-palindromic-subsequences/description/

DP。二维DP记录每个子串中不重复的回文子序列的个数，先固定长度，然后遍历起点。对于$DP[i][j]$，分两种情况:
1. $s[i] == s[j]$:假设$s[i+1:j-1]$的不重复的回文子序列为$\{y_1, y_2, ..., y_k\}$，$s[i]=s[j]=a$，不考虑具体的细节粗略估计应该有$DP[i][j]=DP[i+1][j-1] * 2 + 2$，这是因为$s[i:j]$的不重复回文子串粗略想想应该有$\{y_1, y_2, ..., y_n, ay_1a, ay_2a, ..., ay_na, a, aa\}$，下面考虑可能出现的重复，当$s[i:j]$的模式为`axxxaxxxaxxxa`时，就会出现重复，因此可以用TP的方法，分别从$s[i+1]$和$s[j-1]$向内查找$a$，设出现的位置分别为$l$和$r$。
  * $l < r$：即$s[i:j]$的模式是`axxxaxxaxxxa`，因此重复的就是最里面的`xx`的非重复回文子序列个数，此时$DP[i][j] = DP[i+1][j-1]*2 - DP[l+1][r-1]$。
  * $l = r$：即$s[i:j]$的模式是`axxxaxxxa`，此时$DP[i][j] = DP[i + 1][j-1] * 2 + 1$
  * $l > r$: 即不存在重复，$s[i:j]$的模式是`axxxa`，此时$DP[i][j] = DP[i+1][j-1] * 2 + 2$。
2. $s[i] != s[j]$:$DP[i][j] = DP[i+1][j] + DP[i][j-1] - DP[i+1][j-1]$。

731: Rectangle Area II
https://leetcode.com/contest/weekly-contest-88/problems/rectangle-area-ii/

DP。计算二维坐标系内所有非旋转矩形（所有矩形的边均和X或Y轴平行）重叠的面积。基本思想是将所有矩形分成小块，所有部分都只计算一次。
  * 我自己的思路：使用priority_queue，将所有矩形按照$\{X_1, X_2, Y_1, Y_2\}$的优先级进行排序，每次取出前两个矩形，每次将重复的部分保留，计算多出的部分。我的思路有个bug，当多出的部分与后续的矩形有重复时，这个方法就有了重复计算。
  * **正确方法**：将所有出现过的X，Y分别提取出来。遍历每个矩形，找到其左下角和右上角两个坐标的位置$\{X_1, Y_1, X_2, Y_2\}$在X和Y中对应的index：$\{i_1, j_1, i_2, j_2\}$，遍历所有小矩形$\{x_1, y_1, x_2, y_2\}$，其中$i_1 <= x_1 < x_2 <= i_2, j_1 <= y_1 < y_2 <= j_2$。由于$x_1$和$x_2$必然在X中相邻，$y_1$和$y2$必然在Y中相邻，因此只需标记$\{x_1, y_1\}$即可，可以用二维DP记录应该访问的小矩形，$DP[x_1][y_1] =true$就表示小矩形$\{x_1, y_1, x_2, y_2\}$的面积应该被计入最后的结果中。


55: Jump Game

https://leetcode.com/problems/jump-game/?tab=Description
同45。三种方法，性能由差到好。


56: Merge Intervals

https://leetcode.com/problems/merge-intervals/?tab=Description
sort。sort的第三个参数为重载了"<"的函数，可以自己写myCompare函数实现"<"逻辑，也可以写函数类用于构建函数对象。也可以利用C++11新特性lambda表达式实现，编译器会根据lambda表达式生成函数对象。


57: Insert Interval

https://leetcode.com/problems/insert-interval/description/

sort。同56，先将要新Interval插入列表，然后merge。
更高效的算法是扫一遍所有的interval。看看当前的interval能不能merge到新的interval中。如果能merge则更新新的interval，如果不能更新，没有交集且当前的interval在新的interval前，则直接加入结果，如果没有交集且当前的interval在新的interval之后，直接退出扫描。将新的interval和剩下的interval逐个加入结果列表中。这是fun的方法，O(N)。


406: Queue Reconstruction by Height

https://leetcode.com/problems/queue-reconstruction-by-height/description/

sort。使用lambda表达式进行sort，然后将每个元素插到`res.begin()+p.second`的位置上。


54: Spiral Matrix

https://leetcode.com/problems/spiral-matrix/?tab=Description

math。内循环每次从$(i,i)$开始，向右走到$(i, n - i - 1)$, 再向下走到$(m - i - 1, n - i - 1)$，再向左走到$(m - i - 1, i)$, 最后向上走到$(i + 1, i)$。注意去重，即后遍历一圈的过程中，前后两次沿相反的方向遍历的不能是同一行或者同一列！


59: Spiral Matrix II

https://leetcode.com/problems/spiral-matrix-ii/?tab=Description

同54。

835: Image Overlap
https://leetcode.com/contest/weekly-contest-84/problems/image-overlap/

math。空间考察，两个大小一样的方阵A，B重叠，有四种可能的情况，固定A，B可以与A重叠左上角，左下角，右上角，右下角。遍历A的格，作为重叠的部分在A内的一角，遍历B的每个格，根据重叠部分在A的方位（四个，所以有四种情况），计算重叠的格在A中对应的行和列，判断两者的值并分别计数。


858: Mirror Reflection

https://leetcode.com/contest/weekly-contest-90/problems/mirror-reflection/

math。全镜面正方形二维房间，一束光从一角照进来，控制入射角度（q控制）和房间的长度（p），观察这束光第一次照到角上会最先照到另外三个角的哪一个。这是一个非常好的初中物理题。其实只要沿一个方向（上方）按光的反射定律无限延伸即可，如果想到最简单的照到其它三个角的方式，后面就容易了。于是问题变为一个数学问题，一个点每次向上跑q，看什么时候能达到$n * q % p == 0$的条件，根据n来判断是哪个角。


867: Prime Palindrome

https://leetcode.com/contest/weekly-contest-92/problems/prime-palindrome/

math。给定整数N，找出一个回文质数p，要求p是满足$p >= N$的第一个回文质数。 由于题目条件$N < 10^8$而且N为`int`型，因此可以遍历$i \in [0, 10000]$，作为回文数的左侧部分，然后通过`mirror`函数，将右侧补全。补全的过程中可以在左右两部分的中间添加一位数字$j \in [-1, 9]$($j=-1$表示不添加)。如果`mirror`函数的结果p满足$p >= N$且p是回文数，则答案正确。

上面的解法有个小trick，仔细分析`mirror`函数的遍历过程会发现，每次遍历的时候都是先产生一个$2k$位的整数，然后再产生10个$2k+1$位的整数，这就产生了一个问题:为什么先遍历大的整数，再遍历小的整数结果却不会出错？其实这是因为符合模式为`xx`(`x`表示一个整数)的质数只有11一个，这个结论需要证明！


48: Rotate Image

https://leetcode.com/problems/rotate-image/?tab=Description

math。矩阵顺时针旋转，先将矩阵进行上下翻转(上换到下)，然后对角互换(左下换到左上)，于是左上就换到了右上，左下换到了左上，右上换到了右下，右下换到了左下，实现了顺时针旋转90度。对于逆时针旋转先上下翻转，然后左上与右下互换。


66: Plus One

https://leetcode.com/problems/plus-one/description/

math。初始化令最低位进位c=1,可以按照统一的模式解决。


35: Search Insert Position

https://leetcode.com/problems/search-insert-position/?tab=Description
BS。可以直接用`upper_bound`或者`lower_bound`来做。


34: Search for a Range

https://leetcode.com/problems/search-for-a-range/?tab=Description
BS。BS查找下界和上界两类问题存在区别，区别在于求下界时mid要靠近low，求上界的时候mid要靠近high；这种区别决定在每次循环更新要找的那个界限（low或者high）。也可以直接使用STL的`upper_bound`和`lower_bound`。


33: Search in Rotated Sorted Array

https://leetcode.com/problems/search-in-rotated-sorted-array/?tab=Description
BS。$a[mid]$和$a[low]$比较，是为了确定$a[mid]$在较大的前半部分还是较小的后半部分，$a[mid]$在前半部分的条件就是$a[low] <= a[mid]$。


81: Search in Rotated Sorted Array II

https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

BS。同33，只是数组中存在重复元素，$a[mid] = a[low]$时分类不明显，直接拎出来，令`low++`(相当于遍历)，其余不变。


31: Next Permutation

https://leetcode.com/problems/next-permutation/?tab=Description
math。先从后将降序序列反转，然后找反转序列的前一个数字在反转序列中的上界与该数字替换。


41: First Missing Positive


https://leetcode.com/problems/first-missing-positive/description/


math。鸽巢原理，第一个missing的正整数的范围一定是$[1, array.size() + 1]$。扫描原数组，用额外的数组记录已经出现的正整数，再扫描新数组，第一个没访问过的数就是第一个missing的正整数。有更好的方法，不需要额外的空间，详见 http://www.cnblogs.com/AnnieKim/archive/2013/04/21/3034631.html  。


15: 3Sum

https://leetcode.com/problems/3sum/?tab=Description
TP。

16: 3Sum Closest

https://leetcode.com/problems/3sum-closest/?tab=Description
TP。同15，先sort，然后逐个确定i,l,r三个指针，注意去重。和15不同的是，内循环内部不需要再去重了。


18: 4Sum

https://leetcode.com/problems/4sum/?tab=Description
TP。先进行sort，然后逐个确定i,j,l,r四个指针，注意去重和剪枝(非必须)。


38: Count and Say

https://leetcode.com/problems/count-and-say/description/

TP。将序列模仿出来即可。


11: Container With Most Water

https://leetcode.com/problems/container-with-most-water/?tab=Description
TP。左右指针分别从数组两端开始，两指针夹逼过程中，矩形的长变小，只有宽增大，面积才会增大。


821: Shortest Distance to a Character
https://leetcode.com/contest/weekly-contest-81/problems/shortest-distance-to-a-character/

TP，string中里指定字符最近的距离，分别从左侧和右侧使用TP进行遍历。


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

multimap存储去掉一个数之后的target，遍历数组查找是否有数字,注意找到的数字不能为a[i]。因为题目的限制，也可以用map存。基于map的时间复杂度为O(N)。使用TP，要先sort，时间复杂度为O(NLOGN)。


500: Keyboard Row

https://leetcode.com/problems/keyboard-row/#/description
现在连easy级的题都没法一刷AC了，真是菜啊！再刷！！！二刷一次AC。


454: 4Sum II

https://leetcode.com/problems/4sum-ii/#/description
没有思路，要再刷两遍！一刷没AC，res更新不是加1，而是加上map中的count！二刷一次AC，但是思路理解并不流畅！还要再刷!


451: Sort Characters By Frequency

https://leetcode.com/problems/sort-characters-by-frequency/#/description
比较简单，但是比较考基本功，但是还是不明白为啥要用static关键字！！！一刷没AC，注意map使用[]操作查询时，不存在的键会自动生成！而值会调用相应的默认构造函数！这是c++的一大优点。


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


822: Card Flipping Game
https://leetcode.com/contest/weekly-contest-81/problems/card-flipping-game/

Hashmap。要求正面字符不能出现在反面，考察规律，出去正反面数字相同的牌，一定有一种方式，将所有相同数字全都排在正面。因此只要记录正反面相同的牌的数字，除去这些数字，找牌上出现的最小的数字即可。


133: Clone Graph

https://leetcode.com/problems/clone-graph/description/

graph的dfs, 注意图中可能有环，和138非常相似。


94: Binary Tree Inorder Traversal

https://leetcode.com/problems/binary-tree-inorder-traversal/#/description
二叉树的前、中、后遍历的递归和非递归算法都要很熟悉。


49: Group Anagrams

https://leetcode.com/problems/anagrams/#/description
map使用红黑树实现，而unordered_map基于hash table，使用hash型数据结构必须保证key的类型有hash()方法，容器类型除了string外默认是没有hash()方法的，而非hash型数据结构没有限制！c++中对于map和unordered_map，使用[]方法访问当key不存在时调用value的默认构造函数。


445: Add Two Numbers II

https://leetcode.com/problems/add-two-numbers-ii/#/description
很简单，但是没有一次AC！而且我的方法时间和空间复杂度都比较高。


328: Odd Even Linked List

https://leetcode.com/problems/odd-even-linked-list/#/description
很简单的一道题，题意理解错误，正确理解题意后一次AC。


148: Sort List

https://leetcode.com/problems/sort-list/#/description
TP。双指针找到中点，递归排序再merge。


147: Insertion Sort List Add to List

https://leetcode.com/problems/insertion-sort-list/#/description
指针。使用dummy node作为新的头结点，将原链表的节点依次插入到新链表中。


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

链表分组反转，头插法。使用pre和cur分别记录当前组和下一组的头结点，设置dummy node作为结果链表的起始，记录新链表的尾部，因为没插入一个新的组之后就要更新这个尾部，再进行头插法。


61: Rotate List

https://leetcode.com/problems/rotate-list/#/description
TP。注意要首先得出链表长度len，再将旋转次数对len取模，避免多余计算和可能的错误。


83: Remove Duplicates from Sorted List

https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

TP。用pre和cur两个指针，cur走到cur和cur->next不等，pre = cur，pre=cur->next, cur=cur->next。


82: Remove Duplicates from Sorted List II

https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/#/description
TP。同83，记录cur重复次数次，重复一次pre = cur，重复多次pre ->next = cur->next。最后cur=cur->next。


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
二分法注意0和mid * mid == x的情况。经典方法是Newton法。


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
使用进制计算，计算n的2进制表示下的每一位的权值并相乘。注意将n由负转为正时，需要使用long long类型。


60: Permutation Sequence

https://leetcode.com/problems/permutation-sequence/#/description
题目不简单，看别人的代码很难，对思路还不是很清晰，再刷！


43: Multiply Strings

https://leetcode.com/problems/multiply-strings/#/description
大数乘法。从低位到高位，对于结果的每一位都跑一次循环，得到该位的数字并设置全局变量记录进位。初始化结果全零，之后再将高位的0抹去，当结果为0要补个0。


29: Divide Two Integers

https://leetcode.com/problems/divide-two-integers/#/description
二进制，位运算。时间复杂度是O(logN)。


12: Integer to Roman

https://leetcode.com/problems/integer-to-roman/#/description
自己建立map，将阿拉伯数字与罗马数字字符串对应起来。

13: Roman to Integer

https://leetcode.com/problems/roman-to-integer/description/

是12题的逆过程。

567: Permutation in String

https://leetcode.com/problems/permutation-in-string/#/description
一个简单的滑动窗口的题目，没思路，真是菜！一刷AC，还要再刷！


532: K-diff Pairs in an Array

https://leetcode.com/problems/k-diff-pairs-in-an-array/#/description
很简单，没有一次AC，再刷！


524: Longest Word in Dictionary through Deleting

https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/#/description
思路不是自己的。一刷因为多个变量在同一行中定义写法出错拿个CE！对于pj的增长方式还是没办法提出比较容易理解的模型。再刷！！


3: Longest Substring Without Repeating Characters

https://leetcode.com/problems/longest-substring-without-repeating-characters/#/description
滑动窗口，TP。使用一个长为256的vector记录每个char上次出现的位置，用start记录当前无重复元素子串的起始位置，窗口右侧遇到一个已经访问过的char，窗口左侧（start）移到改char上次出现位置的后一位。


557: Reverse Words in a String III

https://leetcode.com/problems/reverse-words-in-a-string-iii/#/description
面试被难倒的一个问题，一刷没有AC，真是辣鸡！再刷！


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
DP解法,先判断是否为回文串，然后更新起始点，O(N^2)。另一种解法遍历每个字符，沿两侧展开，更新起始点和最大长度，O(N^2)。


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


227: Basic Calculator II

https://leetcode.com/problems/basic-calculator-ii/#/description
istringstream非常好用，可以从中直接读取任意数据类型，读取字符串直接用getline操作。注意用op来对term进行正负修饰，只有第一次读入加号或者减号的时候需要。一刷没思路，二刷term的正负没写对位置。


224: Basic Calculator

https://leetcode.com/problems/basic-calculator/description/

和227相似，稍难主要是括号的处理。使用signs的栈存储当前括号计算结果应该乘上的符号，sign只存储一个数字的符号。上题适合使用stringstream，本题不适合使用stringstream。


17: Letter Combinations of a Phone Number Add to List

https://leetcode.com/problems/letter-combinations-of-a-phone-number/#/description
BFS和DFS都可以做，我更喜欢用bfs.


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


91: Decode Ways

https://leetcode.com/problems/decode-ways/#/description
DP,注意处理非法输入。


71: Simplify Path

https://leetcode.com/problems/simplify-path/#/description
stack。用vector代替stack更简单，stringstream要用熟，getline(stream, buffer, char)的第三个参数表示分隔符。最后多出来一个"/"要去掉。


844: Backspace String Compare
https://leetcode.com/contest/weekly-contest-87/problems/backspace-string-compare/

stack。使用将string转为stack，遇到'#'且栈非空则删除栈顶元素，否则将字符压入栈中。


93: Restore IP Addresses

https://leetcode.com/problems/restore-ip-addresses/#/description
DFS。count记录ip段数，start记录起始位。


22: Generate Parentheses

https://leetcode.com/problems/generate-parentheses/#/description
dfs，左括号只要有剩余就可以选，右括号只有在已生成的串中左括号多于右括号才可以选。


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

https://leetcode.com/problems/path-sum-ii/description/

dfs。遍历解空间，收集合法解。不用去重，比较简单。


124: Binary Tree Maximum Path Sum

https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

dfs。一种方法是两个递归，小的递归找出以root为起点以任意节点为终点的所有path sum的最大值，大的递归找出以任意节点为root的子树的最大path sum作为结果；就是说遍历解空间，大递归遍历以任意节点为根的子树，对子树调用小递归，更新大递归的解。以这种方法存在大量的重复计算，效率低。另一种方法将大递归和小递归融合成一个递归，在小递归中更新全局最优解，但是返回小递归的解。


46: Permutations

https://leetcode.com/problems/permutations/description/

dfs。面试趋势是这种题目变为解决问题其中的一步。


47: Permutations II

https://leetcode.com/problems/permutations-ii/description/

比46要难，去重可以使用frequency，将只考虑重复元素的第一个元素，重复次数用频率计数。排列、组合、组合和都属于01背包问题，理解要加强。



90: Subsets II

https://leetcode.com/problems/subsets-ii/description/

dfs，先排序，对着解空间写递归，注意去重。


131: Palindrome Partitioning

https://leetcode.com/problems/palindrome-partitioning/description/

先用dp计算任意子串是否为回文，再使用dfs收集合法的partition。


77: Combinations

https://leetcode.com/problems/combinations/description/

dfs。


78: Subsets

https://leetcode.com/problems/subsets/

dfs。


39: Combination Sum

https://leetcode.com/problems/combination-sum/?tab=Description
dfs。可以画出解空间来理解解题过程。


40: Combination Sum II

https://leetcode.com/problems/combination-sum-ii/?tab=Description
DFS。首先要排序，之后要对照解空间写递归过程。


51: N-Queens

https://leetcode.com/problems/n-queens/description/

dfs时让col递增，逐个选择合法的row，存储path，path的含义是(path[i], i)位置可以放一个Queen，之后将合法path转为棋局排列。注意判断冲突有三个条件（1）row1 ！= row2（2）row1 + col1 != row2 + col2 （3）row1 - col1 != row2 - col2。 


52: N-Queens II

https://leetcode.com/problems/n-queens-ii/description/

dfs，思路同上。


132: Palindrome Partitioning II

https://leetcode.com/problems/palindrome-partitioning-ii/description/

dfs超时,DP一次AC。partition的DP递推公式和判断回文的递推公式不同，[i,j]不满足回文的时候，不能只考虑[i+1,j]和[i,j-1]令其较小值+1，因为[i+1,j]和[i,j-1]虽然可能组成最长的回文子串，也可能partition次数很多！因此要再用一个minCut数组存储最小的cut.


79: Word Search

https://leetcode.com/problems/word-search/description/

dfs。和maze那道题对比，思考想为什么要恢复原状态(回溯)，回溯会不会造成死循环？


89: Gray Code

https://leetcode.com/problems/gray-code/description/

递归。从0开始，不断从起始位或者终止位补0和1(从起始位补的话不必补0，更简洁)，当时从终止位补0或1出错，不知道为啥。


211: Add and Search Word - Data structure design

https://leetcode.com/problems/add-and-search-word-data-structure-design/description/

挺难！一刷调试了4个小时才AC！理解严重不够！多刷！还不能完整地写出来，再刷！二刷没有AC，对外层for循环和run的更新有了更深的理解。但是对于返回值的判定还是理解不够，再刷！


674: Longest Continuous Increasing Subsequence My SubmissionsBack to Contest
https://leetcode.com/contest/leetcode-weekly-contest-49/problems/longest-continuous-increasing-subsequence/

比较简单，但是这种题我是比较害怕的！还要继续总结！多总结！这才是进步的捷径！

673: Number of Longest Increasing Subsequence

https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/

跟上一题很像！怪不得邓邓把上一道题看成这道题！DP难在算法的理解。看了半天没理解，看了大神的注释之后豁然开朗！一刷AC，但是理解不够，再刷！二刷DEBUG了很久，还是理解不够，心不在焉漏洞百出！再刷！


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

https://leetcode.com/problems/unique-binary-search-trees/description/

DP思路是：将1到n分别作为根，左右两侧都是一个规模更小的子问题，左右两侧结果相乘就是一种情况，枚举所有情况求和即可。一刷AC，二刷没AC，思路不够熟。三刷没思路，看了注释之后AC。四刷使用数组没有初始化WA，应该使用vector。这道题和矩阵相乘的那道题很类似，都是从序列中间取一个元素，分割序列将问题转化为规模更小的子问题，同时分割元素可以是序列中的任意一个元素，这类的递推函数很常见。DP问题的解不仅可以由一个小规模子问题的解得到，还可以由多个甚至所有小规模子问题的解的组合得到。


95: Unique Binary Search Trees II

https://leetcode.com/problems/unique-binary-search-trees-ii/description/

BFS或递归。BFS从1到n，逐渐扩充res，然后遍历上一个节点加入后的res列表，在每棵树上添加新的节点（每个可能的右子树），时间复杂度O(N^2logN)~O(N^3logN)。递归将问题转化为区间的BST生成，遍历范围，选取元素为根，2个子问题分别生成所有左子树left与所有右子树right，然后按照96的思路将所有左右子树的组合得到就是结果。


300: Longest Increasing Subsequence

https://leetcode.com/problems/longest-increasing-subsequence/#/description
一刷AC，使用patient sort算法，时间复杂度为O(NLOGN)，但是不太理解。二刷一次AC，仍然不太理解。三刷使用java刷，算法使用一维DP，时间复杂度为O(N^2)，效率略低，思路很简单，没AC，要注意重复数字不能计入length。patient sort是专门应对这个题的算法！和95相似，这两个问题的DP算法都有一点弯。四刷一次AC。


32: Longest Valid Parentheses

https://leetcode.com/problems/longest-valid-parentheses/description/

一维DP，每一个元素记录以当前字符结尾的最长合法串的长度。
1. s[i] == '('， dp[i] = 0；
2. s[i] == ')'， 如果s[i - 1] == '(' 则dp[i] = dp[i- 2] + 2， 如果s[i - dp[i-1]-1] == '(', 则dp[i] = dp[i-dp[i-1]-2] + dp[i-1]+2；


647: Palindromic Substrings

https://leetcode.com/problems/palindromic-substrings/description/

一刷使用DP算法AC，时间复杂度和空间复杂度都是O(N^2)。讨论区应该有更好的解法，再刷尝试！讨论区有一个经典的解决字符串中回文子串的算法叫“曼彻斯特算法”，后面要对这种类型进行总结！


416: Partition Equal Subset Sum

https://leetcode.com/problems/partition-equal-subset-sum/description/

一刷没AC，使用时间复杂度为O(N!)的backtracing算法，出现很多CE！最后TLE。也有人说时间复杂度为O(pow(2, N))的！这是个典型的0/1背包问题，0/1背包问题的特点是从一组数中选取某些数达到一定的值。对0/1背包问题的一个很好的解释在下面的链接中：

https://discuss.leetcode.com/topic/67539/0-1-knapsack-detailed-explanation

这一题使用的DP解法对标准0/1背包算法进行了优化，因为题目不需要知道更多的信息，数组开一维就可以。数组开二维也可以，但是比较麻烦，需要更多的初始化，操作！

最优化方法是使用bitset的方法，时间复杂度为O(N)，空间复杂度为O(1)!


139: Word Break

https://leetcode.com/problems/word-break/description/

一维DP，不用管前面，每次从后面看，将s[0, j]分成两部分s[0, i]和s[i+1, j]，如果s[i+1, j]在字典中，s[0,i]可以由词典中的词拼成，则s[0, j]也可以由字典中的词拼成。注意dp[0]=true的初始化。dp[0]对结果没有意义，但是在dp更新时有用。O(N^2*M)。


140: Word Break II

https://leetcode.com/problems/word-break-ii/description/

和上题的思路相同，但是使用的是递归+MEMO，因为要把所有可能的结果都保存下来。
f(s[0, j]) = f(s[0, i]) + word(s[i + 1, j]) 


135: Candy
BFS或DP。BFS算法将问题转化为拓扑排序，O(N^2)的复杂度，超时。一维DP先从左向右扫描数组，与左侧元素比较更新DP，之后反向扫描数组，根据元素与右侧元素的关系修改DP。可以将空间复杂度降到O(1)，同时保留O(N)的时间复杂度。


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

dp。二维填表，逐行填充，母问题可以转化为两个子问题。dp[i][j]表示s1的前i个字符和s2的前j个字符是否可以按照题目规定的方式组合成s3的前i+j个字符。


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


377: Combination Sum IV

https://leetcode.com/problems/combination-sum-iv/description/

一刷没思路，DFS都忘了。大神的top-down的DFS超时，加入memo实现DP后，AC。这个题很经典，和之前整理的回溯法有强关联！注意理解DP的含义，我现在仍然不知道这样做是不是就叫做DP。再刷！注意整理！
除了上一种top-down的DP方法，还有一种bottom-up的DP方法，这种方法在我看来更像DP。一刷dp空间分配不够，RE。错误在本地没复现，猜测是因为本地使用伙伴内存管理，dp配额有冗余，而网页后端对内存的检测更严格。
两种方法的空间复杂度都是O(N)，时间复杂度均为O(MN)，top-down方法虽然使用递归，但是这个时间复杂度容易分析。


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

https://leetcode.com/problems/coin-change/description/

DP。dfs+贪心剪枝，WA，错在使用贪心算法剪枝并不一定得到最优解！如([10, 25, 30], 50)这个反例，因为问题要找最短的，这相当于提示用BFS，但是BFS会导致MLE。一维DP最简单，[0, amount]全序列DP，子问题规模就是coin的面值种类。

一般面试能碰到的DP可以分为3类，第一类是一维DP（LCS， final_term 第4题），第二类和第三类都是二维DP，其中第二类的下标i和j表示的含义相同，是对称的 (Longest Palindromic Substring, Unique Binary Search Tree, Triangle) ，第三类是下表i和j的含义是不同的，不是对称的 (0-1背包问题，Best Time to Buy and Sell Stock IV)，其实还有三维DP（87: Scramble String）。刷题要精刷，每道题做完都要看discuss区找最优解！

DP问题首先看问题能否降为子问题，如果能将问题分解为规模更小的问题，那就很可能用Buttom-up的DP方法。子问题可能是两个（Climb Stairs, Unique Paths, Minimum Path Sum, Delete and Earn），三个及多个（Coin Change）或者全部更小规模子问题（final term第4道题）。


518: Coin Change 2

https://leetcode.com/problems/coin-change-2/description/

DP.与上题不同的是要去重，这里计算的是目标组合的个数。相比于这题，Climbing Stairs相比，这里因为计算的是合法组合数，去重更困难。思路是先控制使用的coin的面值，逐个加入新面值，改变组合数。


740: Delete and Earn
https://leetcode.com/contest/weekly-contest-61/problems/delete-and-earn/

DP，可以降为子问题，典型的0-1背包问题。要继续思考，细嚼慢咽还是很有收获的。


115: Distinct Subsequences

https://leetcode.com/problems/distinct-subsequences/description/

DP。二维填表题，i-1和j-1分别是s和t的index，使用s[i-1]的匹配数为s[i-1]==t[j-1]时的dp[i-1][j-1]，不使用s[i-1]时的匹配数为dp[i-1]][j]。



494: Target Sum

https://leetcode.com/problems/target-sum/description/

一刷没有好思路，看了大神的解析，将问题转化为一个之前解决过的相似问题，自己使用DFS解决了，但是过程不够顺畅，对于set的计数不能再t=0时直接返回，而应该结果+1。时间复杂度为O(N^2)再刷！二刷使用DP没AC，对`vector::resize()`理解不对，resize并不会对vector原有的数据进行重置，只会将其截断或者在后端补充，应该先用clear。再刷！
DFS思路：将num分为正集合P和负集合N，于是有下面的推导
$$sum(P) - sum(N) = target$$
$$sum(P) + sum(N) + sum(P) - sum(N) = target + sum(P) + sum(N)$$
$$2 * sum(P) = target + sum(nums)$$
现在问题也就变成了寻求满足条件的P的个数，可以用DFS。官方给每道题都给了答案，而且每道题的答案不止一种，再刷可以重点看看官方答案。


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

使用双deque实现BFS时，根据奇偶层的处理区别可以分为两种方案：当前层为cur，下一层为next，
* 方案一: 
	1. 奇数层: 读cur时从头读，写next时从尾写，先写左子树再写右子树
	2. 偶数层: 读cur时从尾读，写next时从头写，先写右子树再写左子树 
* 方案二:
	1. 奇数层: 读cur时从尾读，写next时从头写，先写左子树再写右子树
	2. 偶数层: 读cur时从头读，写next时尾头写，先写右子树再写左子树 

也可以使用双Stack实现BFS。奇数层先入左子再入右子，偶数层先入右子再入左子。基于Stack的方法更简单。

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


355: Design Twitter

https://leetcode.com/problems/design-twitter/description/

一刷使用基于堆排序的方法AC，效率并不是很高。明白了为什么有时候会和结果反序，这是因为我写的堆排序的结果是升序，而这种题目一般要求要降序输出结果。


490: Maze
锁定了，写不了。
但是比较简单，至少有两种写法。
一是使用visited，而是将访问过的区域设置为阻隔，有个非常相似的题目，但是我给忘了。


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

递归使用min和max限定子树范围。非递归利用BST的中序遍历一定是递增序列的性质。


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
更巧妙的方法：记录每行、每列、每个小方块中每个数字是否使用过，如果使用过了，就是invalid，这种方法只需遍历1次board。注意数组的初始化！


37: Sudoku Solver

https://leetcode.com/problems/sudoku-solver/description/

dfs。注意使用上题的方式判断valid。注意row_used, col_used和box_used要先初始化！


102: Binary Tree Level Order Traversal

https://leetcode.com/problems/binary-tree-level-order-traversal/description/

双queue实现bfs。


127: Word Ladder

https://leetcode.com/problems/word-ladder/description/

双queue实现BFS。


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

dfs。不能从所有单元格出发进行dfs或者bfs，而是从四条边界出发使用dfs或者bfs即可。、


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

递归中序遍历。BST的中序遍历结果必定是单调递增的，如果进行替换，一定两次出现前一个比后一个大的情况，第一次出现时，被调换的那个一定是较大的那个，而第二次出现的时候被调换的那个一定是较小的那个。用全局变量first,second,pre分别记录被调换的第一个、第二个、上一次访问的元素，遍历完之后调换first和second节点的val即可。


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

与452非常相似，但是并没有想到怎么做，看Wikipedia（https://en.wikipedia.org/wiki/Interval_scheduling#Interval_Scheduling_Maximization）也没看懂，真菜！对于贪心还是不太理解，再刷。


621: Task Scheduler

https://leetcode.com/problems/task-scheduler/description/

一刷没思路，讨论区使用的算法没有看出什么门道，就是找出最频繁的字母，按公式给出结果。公式是：循环体size * 循环次数(频繁字母频率-1) + 剩余的频繁字母个数。公式有特例如3个A，3个B，3个C，1个D，n=2时就不对，此时res=tasks.size()。再刷！


121: Best Time to Buy and Sell Stock

https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

DP。遍历每天的股价，记录当前（包括今天的）最低价，当前价格减当前最低价就是今天卖出的最大收益，取每天最大收益的最大值就是结果。


122: Best Time to Buy and Sell Stock II

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

贪心算法或DP。贪心算法不涨就买，涨就卖。DP使用sell和buy两个数组分别记录当天买入或卖出可能的最大收益，递推公式为：
sell[i] = max(sell[i-1], buy[i-1] + prices[i])
buy[i] = max(buy[i-1], sell[i-1] - prices[i])


123: Best Time to Buy and Sell Stock III
DP。同122，只是要用四个变量分别记录买1次，买2次，卖1次和卖2次的最大收益。
$$sell2[i] = max(sell[i-1], buy2[i-1] + prices[i])$$
$$buy2[i] = max(buy2[i], sell1[i-1] - prices[i])$$
$$sell1[i] = max(sell[i-1], buy1[i] + prices[i])$$
$$buy1[i] = max(buy1[i-1], -prices[i])$$


714: Best Time to Buy and Sell Stock with Transaction Fee

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

一刷使用自己设计的贪心算法：先买，涨了就卖，这样是不对的！[1,3,7,5,10,3]这个case就不对。二刷使用s0和s1分别记录两种状态，这是有限状态自动机的概念，s0是手里没有股票的收益，s1是手里有一支股票的收益，在两个状态之间切换，和309很像。


309: Best Time to Buy and Sell Stock with Cooldown

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

一刷没思路，使用基于有限状态机的DP，一刷AC，时间复杂度和空间复杂度均为O(N)。s0,s1,s2三个状态分别表示最后一个操作为rest, buy, sell的当天maxprofit。再刷！


649: Dota2 Senate

https://leetcode.com/problems/dota2-senate/description/

一刷使用自己设计的贪心算法，分别使用2个参数(count, skip)为双方计数，WA。总计81个case，卡在第78个。分析发现自己对于题目理解有问题，被ban掉的人没有投票权，拥有投票权的人均属于同一方才算赢，这是一个多轮次的游戏。二刷基于queue对游戏进行模拟，思路是一方将另一方ban掉，靠前的那一方ban，靠后的那一方被ban，而且ban的那一方经过这一轮之后下一轮仍然可以投票，所以要将这个数加上N之后放到队列末尾。二刷AC。


134: Gas Station

https://leetcode.com/problems/gas-station/description/

math。做法是遍历i（尝试以i为起点），如果i可以成为起点则返回，如果不能成为起点，则[i, j]中任意一个station都不能成为起点（sum(i,j)<0，对i和j之间的任意一个位置k，sum(i,k)>=0，故l[j]<0, sum[i,j-1]>=0且|l[j]|>sum(i,j-1)，故sum(k,j-1)<sum(i,j-1)，于是sum(k,j)<0）。直到遍历结束，如果total+tank>0，则一定有解，且start记录的i就是一个解（可以用假设法证明，如果start之后的一个station是解，由于从start可以到达该station，所以start一定也是解。而start之前不可能存在解，如果有解，则start一定是一个解）。


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
用deque很简单。一刷没AC，pop函数和普通的stack的pop不同，要返回栈顶元素。


42: Trapping Rain Water

https://leetcode.com/problems/trapping-rain-water/description/

stack，单调栈。出栈情况下不必更新遍历指针，下次循环会自然地继续出栈或者入栈。出栈时用循环向前将造成递增的元素全部出栈，这样容易理解，但是代码显得过于冗长。


739: Daily Temperatures
https://leetcode.com/contest/weekly-contest-61/problems/daily-temperatures/

stack，单调栈。注意存的是index，循环用while比较好，更简洁。


84: Largest Rectangle in Histogram
stack，单调栈。注意要计算的矩形宽度不是(i - 出栈元素的index)，而是(i - 出栈后的栈顶 + 1)，这么做的原因是因为，当前元素可能是洼地，这么计算就不会少算了。


246: Sliding Window Maximum

https://leetcode.com/problems/sliding-window-maximum/description/

单调递减双端队列或堆。使用deque时维护一个单调递减栈（存索引），对于每个可以生成结果的元素，将队头元素插入结果中。使用优先级队列时直接存索引，按照数字大小构建大根堆即可。注意c++实现优先级队列不好写，可以使用java实现。


735: Asteroid Collision
https://leetcode.com/contest/weekly-contest-60/problems/asteroid-collision/

利用stack的特性，注意分类，debug很久！


296: Best Meeting Point
这是一道锁定题。横轴纵轴互不影响，可以将两个维度直接拆开，每个维度排序之后去掉单个的中间节点，加上剩余配对的节点直接的距离即可。一刷没AC，计算sum的时候横轴和纵轴分到两个循环了，在一个循环就可以了，因为长度都一样，注意end初始应该设为posList.size() - 1。


164: Maximum Gap

https://leetcode.com/problems/maximum-gap/description/

一刷使用暴力算法，先sort然后遍历，O(NlogN)的时间复杂度。题目要求O(N)的时间和空间复杂度，桶排序可以满足要求。二刷使用桶排序算法，时间和空间复杂度都是O(N)。由于bucket size设置不当（应该再加1），导致运行时出现除零操作RE。bucket size并不是非常重要的参数，bucket的个数也不需要非常严格，但是一定要保证大于需要的桶的个数。


23: Merge k Sorted Lists

https://leetcode.com/problems/merge-k-sorted-lists/description/

优先级队列，时间复杂度为O(NKlogK)，一刷没AC。头条喜欢考！priority_queue的构造函数中第三个参数不可以使用lambda表达式。


632: Smallest Range

https://leetcode.com/problems/smallest-range/description/

优先级队列。和merge sort的merge算法类似，区别在于本题需要访问priority_queue的队尾元素，因此使用了map，map基于红黑树实现，自动对key进行排序，而且可以通过迭代器随时访问头和尾。保证队列中存有每个list中的最小的数，队列的队头和队尾之间的距离的最小值就是题目的解，每次更新结果后，扔掉队头，并将队头所在的list中下一个元素添加到队列中。将map作为可以两端同时访问的priority_queue的想法真是要逆天了！


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

https://leetcode.com/problems/lru-cache/description/

hashmap和list。主要利用了stl的list基于双向循环链表实现的性质及其提供的splice接口，使得插入、删除都控制在O(1)，而基于hashmap的查找、插入和删除同样是O(1)。注意put操作的实现中，不仅要修改list和相应的迭代器，还有list中的值和map。元素优先级越高在list中的位置越靠前，删除只会在list的尾部进行，而hashmap的删除操作随时随时都可以进行。
list<pair<int, int>> items; unordered_map<int, list<pair<int, int>>::iterator> cache。cache存储key到list中key-value对的迭代器，可以脑补图形。


290: Word Pattern

https://leetcode.com/problems/word-pattern/description/

双map，一次AC。


291: Word Pattern II
https://www.programcreek.com/2014/07/leetcode-word-pattern-ii-java/

双map和dfs结合，一刷没AC，strStart应该更新为i + 1而不是i。


734: Sentence Similarity
https://leetcode.com/contest/weekly-contest-60/problems/sentence-similarity/

map，没理解题意，sentence相似要求每个位置的word都相似！第一次用python刷题，比c++快多了，在数据结构涉及set，string等结构时，python非常方便。


525: Contiguous Array

https://leetcode.com/problems/contiguous-array/description/

核心公式diff[i, j] = diff[0,j] - diff[0,i]，diff表示1比0多的个数，数组的一小段的diff等于整个数组的起始位置到段结尾的diff减去全数组起始位置到段起始的diff。当两个diff相等，表示中间的小段0和1的个数相同，更新结果。一刷没AC，注意处理空数组（diff要多加一个空位，map也要！）。


76: Minimum Window Substring

https://leetcode.com/problems/minimum-window-substring/description/

TP，将直通硅谷老师的思路改进如下：
1. 分别用aMap与tMap（vector实现）存储符合条件的子串($[i,...,j]$)与T中的字符及频率。 
2. for循环遍历j（每轮循环先更新j，然后固定j更新i）:
  1. 先将s[j]添加到aMap中
  2. 尝试更新count和include
  3. 如果[i, ……, j]满足条件,使用while循环尝试右移i,移动过程中优先更新min_len和min_start，如果不能再右移直接退出while循环。


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


687: Longest Univalue Path

https://leetcode.com/problems/longest-univalue-path/description/

双递归。


654: Maximum Binary Tree

https://leetcode.com/problems/maximum-binary-tree/description/

树的递归。


101: Symmetric Tree

https://leetcode.com/problems/symmetric-tree/description/

递归。对左右子树判断对称性。


145: Binary Tree Postorder Traversal

https://leetcode.com/problems/binary-tree-postorder-traversal/description/

二叉树后续遍历递归与非递归实现。多做是有用的，非常有用，做这个题的时候深有体会！


655: Print Binary Tree

https://leetcode.com/problems/print-binary-tree/description/

合并左右子树的时候思路要清晰，分情况，不是两边一直用空串填充，而是每个元素两侧都使用空串填充！一步步简化代码，对容器的insert函数用熟了！


623: Add One Row to Tree

https://leetcode.com/problems/add-one-row-to-tree/description/

树的层序遍历（双queue），注意要保存更上一层的节点，添加子树时不必考虑子树是否为空！


337: House Robber III

https://leetcode.com/problems/house-robber-iii/description/

递归，有点0-1背包的意思。


662: Maximum Width of Binary Tree

https://leetcode.com/problems/maximum-width-of-binary-tree/description/

一刷使用BFS，当树的高度过大时，内存溢出。二刷基于BFS，利用满二叉树的性质（子节点和父节点index之间的关系，$left child node index = parent node index * 2$， $right child node index = parent node index * 2 + 1$。


129: Sum Root to Leaf Numbers

https://leetcode.com/problems/sum-root-to-leaf-numbers/description/

dfs，遇到叶子节点就把num(表示path)加到res上。如果follow up将节点的数只有1位的限制去掉，可以使用vector表示path。


450: Delete Node in a BST

https://leetcode.com/problems/delete-node-in-a-bst/description/

好题！删除BST中的节点，上课讲过，自己做还是废了不少时间。递归删除节点，找到节点后分情况讨论，找左子树的最大值或者右子树的最小值作为新的根的值，并删除原节点，findAndDelete函数要注意删除节点不能直接将父节点的右子树设为NULL，要设为删除节点的左子树！


116: Populating Next Right Pointers in Each Node

https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/

BFS。双queue实现的BFS空间复杂度为O(N)，不满足要求。利用next指针可以实现BFS，空间复杂度仅为O(1)。BFS的思想：遍历本层，链接下一层并记录下一层的起始节点。


117: Populating Next Right Pointers in Each Node II

https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/

BFS。同116。


847: Shortest Path Visiting All Nodes
https://leetcode.com/contest/weekly-contest-87/problems/shortest-path-visiting-all-nodes/

BFS + DP。使用2进制的方法记录每个节点是否被访问，相当于中间状态。每次访问一条边，如果经过头结点的状态到达尾节点的距离大于经过头结点的状态到头结点 + 1，则更新经过头结点状态到达尾节点的距离。


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

系统设计题，实现前缀树。注意要用c - 'a'而不是直接用c来索引后继节点！


14: Longest Common Prefix

https://leetcode.com/problems/longest-common-prefix/description/

Trie。


648: Replace Words

https://leetcode.com/problems/replace-words/description/

Trie


307: Range Sum Query - Mutable

https://leetcode.com/problems/range-sum-query-mutable/description/

一刷使用暴力解法AC，时间复杂度为O(N)。用线段树和二分索引树做时间复杂度可以降到O(log N)。


530: Minimum Absolute Difference in BST

https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/

一刷递归一次AC。


729: My Calendar I

https://leetcode.com/problems/my-calendar-i/description/

线段交集，感觉跟线段树或者二分索引书有关，不清楚！要继续思考，一刷AC。


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

DP和递归，递归超时，可以使用迭代替换递归，实质是斐波那契数列，计算的是合法的排列数。


88: Merge Sorted Array

https://leetcode.com/problems/merge-sorted-array/description/

合并两个排好序的数组。我用了堆，用了temp，空间复杂度过高。最优解是将较长的数组扩充，然后倒着插入，思路类似快排，挖坑填坑。


125: Valid Palindrome

https://leetcode.com/problems/valid-palindrome/description/

字符相关API如：isdigit,isalpha,isalnum,isupper,islower要用熟。


4: Median of Two Sorted Arrays

https://leetcode.com/problems/median-of-two-sorted-arrays/description/

二分查找。查找两个有序数组总的中位数，要求O(log(m+n))的时间复杂度。基于归并排序的方式O(m+n)的复杂度，基于递归的二分查找可以达到复杂度要求。


10: Regular Expression Matching

https://leetcode.com/problems/regular-expression-matching/description/

正则表达式匹配，频率超高！同频的还有四则运算表达式的计算，前、中、后缀表达式切换和运算！
递归方法分char和`.`，之后在内部讨论后面是否有`*`。DP考虑是否为`*`，是`*`分不重复和重复重复，重复时`x*x`只需判断s把`x`去掉之后的情况，不是`*`可以归于一类。


44: Wildcard Matching

https://leetcode.com/problems/wildcard-matching/description/

递归超时，DP可以AC。和10非常相似。还有更简单的方法及TP法。
https://yucoding.blogspot.com/2013/02/leetcode-question-123-wildcard-matching.html



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




































