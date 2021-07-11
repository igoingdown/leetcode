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

[interviews](interviews/jiukun/README.md)


463: Island Perimeter

<https://leetcode.com/problems/island-perimeter/>

枚举。有两种做法
* 方法一:遍历所有的cell，判断每个cell的每个边是否为Island的边界，是边界则`perimeter+1`。
* 方法一:遍历所有的cell，每个 cell 带来 4 个长度的周长，减掉被重复计算的部分即可。

----

414: Third Maximum Number

<https://leetcode.com/problems/third-maximum-number/>

找出`n`个数中的第`m`（`m <= n`）大的数，这是个经典问题=?

* `m`不太大（`m<4`）时：同时设置多个max，遍历数组元素，分条件更新max。注意以下两点
  1. max的初始化一定要比当前数组元素类型的最小值要小；
  1. max更新条件要写全，“=”的情况要排除。
* 当`m >= 4`时：可以借用快排的partition操作来做。

----


73: Set Matrix Zeroes

<https://leetcode.com/problems/set-matrix-zeroes/?tab=Description>

将第一行和第一列作为标志，第一行(或第一列) 单独配置一个标志。
从$(0, 0)$到$(m-1, n-1)$前向遍历将标志置零， 置零表示改行和该列都应该被置零。
从$(m-1, n-1)$到$(0, 0)$逆序遍历按标志将元素置0。
逆序的好处是不用最后再把标志行和标识列再处理一遍。


535: Encode and Decode TinyURL

https://leetcode.com/problems/encode-and-decode-tinyurl/#/description

存储 origin_url 和 code 两个方向的映射。随机生成 code，遇到碰撞就再来一次，直到不碰撞为止。
参考https://dev.to/seanpgallivan/solution-encode-and-decode-tinyurl-4mji


508: Most Frequent Subtree Sum

https://leetcode.com/problems/most-frequent-subtree-sum/#/description

递归遍历树，构建`map[sum]count` 并在构建过程中算出 max_count；
构建 map 结束，遍历 map 返回 `val==max_count` 的 key 的列表。



438: Find All Anagrams in a String

https://leetcode.com/problems/find-all-anagrams-in-a-string/#/description

参考 https://www.cnblogs.com/grandyang/p/6014408.html

使用滑动窗口。窗口内部只要每个字符的个数一致即可。


380: Insert Delete GetRandom O(1)

https://leetcode.com/problems/insert-delete-getrandom-o1/#/description

get\_random的时候index不能为0！


274: H-Index

https://leetcode.com/problems/h-index/#/description


**TODO**: 使用的是什么方法？
注意vector和Hashmap的查找复杂度都是O(1)！开数组，多加一个元素用于存储引用数大于size的个数。


166: Fraction to Recurring Decimal

https://leetcode.com/problems/fraction-to-recurring-decimal/#/description

**TODO**: 使用的是什么方法？
 注意极端情况如0，如负数，还有超出界限的问题。效率不高。
discuss区c++第一名的算法非常简洁，和我思路一样。


523: Continuous Subarray Sum

https://leetcode.com/problems/continuous-subarray-sum/#/description

思路不是自己的，一刷没AC，因为变量写错CE，因为没考虑K会是负数而WA，还要再刷！


462: Minimum Moves to Equal Array Elements II

https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/#/description

这个问题中数列的平衡杆不一定就是均值，因为经过排序后两端每对数字移动的总距离和均值无关。
当数字有偶数个时，以均值直接算作平衡杆正确；当数字有奇数个且中间那个数恰好为均值时，用均值作为平衡杆也正确；
但是当中间那个数不是均值时，就应该用中间那个数作为平衡杆，亦即中间那个数不需要移动！
一次AC，但是思路不是自己的，还要再刷！



423: Reconstruct Original Digits from English

https://leetcode.com/problems/reconstruct-original-digits-from-english/#/description

比较简单的多元方程组的问题，一刷没AC，因为string和int的互换方法不清CE了，算法效率也不是很高。


415: Add Strings

https://leetcode.com/problems/add-strings/#/description


400: Nth Digit

https://leetcode.com/problems/nth-digit/#/description

注意base设为int类型越界


413: Arithmetic Slices

https://leetcode.com/problems/arithmetic-slices/#/description


368: Largest Divisible Subset

https://leetcode.com/problems/largest-divisible-subset/#/description

思路不好，有漏洞，看了讨论区的C++算法，一刷没AC。
因为开始没对数组没排序得了WA。对大神的思路理解的不够深入，再刷！！


365: Water and Jug Problem

https://leetcode.com/problems/water-and-jug-problem/#/description

巨硬笔试题，数论问题，挺难的！
最大公约数GCD和最小公倍数LCM还不太会弄！一刷一次AC。但是思路理解起来还是挺费劲的！再刷！


313: Super Ugly Number

https://leetcode.com/problems/super-ugly-number/#/description

比较复杂，我有个思路，但是没有想到怎么实现。看了讨论区算法才搞明白，思路不是自己的，一次AC，还要再刷！


264: Ugly Number II

https://leetcode.com/problems/ugly-number-ii/#/description

和313题很像，我也是用的313题的方法，效率还不错，一刷AC。


532: K-diff Pairs in an Array

<https://leetcode.com/problems/k-diff-pairs-in-an-array/#/description>


524: Longest Word in Dictionary through Deleting

https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/#/description


520: Detect Capital

https://leetcode.com/problems/detect-capital/#/description

注意判断逻辑顺序。


541: Reverse String II

https://leetcode.com/problems/reverse-string-ii/#/description



434: Number of Segments in a String Add to List

https://leetcode.com/problems/number-of-segments-in-a-string/#/description


551: Student Attendance Record I

https://leetcode.com/problems/student-attendance-record-i/#/description


521: Longest Uncommon Subsequence I

https://leetcode.com/problems/longest-uncommon-subsequence-i/#/description

一行完事，但是很绕！


6: ZigZag Conversion

https://leetcode.com/problems/zigzag-conversion/#/description


556: Next Greater Element III

https://leetcode.com/problems/next-greater-element-iii/#/description

不难，但是忘记怎么求下一个排列的算法了。


7: Basic Calculator II

https://leetcode.com/problems/basic-calculator-ii/#/description

istringstream非常好用，可以从中直接读取任意数据类型，读取字符串直接用getline操作。
注意用op来对term进行正负修饰，只有第一次读入加号或者减号的时候需要。


224: Basic Calculator

https://leetcode.com/problems/basic-calculator/description/

和227相似，稍难主要是括号的处理。使用signs的栈存储当前括号计算结果应该乘上的符号，
sign只存储一个数字的符号。上题适合使用stringstream，本题不适合使用stringstream。


336: Palindrome Pairs

https://leetcode.com/problems/palindrome-pairs/#/description


539: Minimum Time Difference

https://leetcode.com/problems/minimum-time-difference/#/description


468: Validate IP Address

https://leetcode.com/problems/validate-ip-address/#/description

getline在这个题目中有妙用！题目不难，但是边界条件非常多！


522: Longest Uncommon Subsequence II

https://leetcode.com/problems/longest-uncommon-subsequence-ii/#/description

两种方法，直接构造带有cmp函数的map失效，还没弄明白原因！


475: Heaters

https://leetcode.com/problems/heaters/#/description

要弄懂懂`upper_bound`和`lower_bound`的区别。


436: Find Right Interval

https://leetcode.com/problems/find-right-interval/#/description


275: H-Index II

https://leetcode.com/problems/h-index-ii/#/description

274的附加题。题意很难懂。


378: Kth Smallest Element in a Sorted Matrix

https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/

BS。要找到二分查找中间的判定条件比较困难！
如何将一个不在matrix中的值逼近到在matrix中的值的根本技巧需要再深入思考。


658: Find K Closest Elements

https://leetcode.com/problems/find-k-closest-elements/description/

`lower_bound`得到第一个不小于val的元素的迭代器，而`upper_bound`得到第一个大于val的元素的迭代器。
明白了一个问题就是为什么要去掉low，保留high，
因为low是有问题的，相当于数轴上的空心点！一定是high离得近，所以最后舍弃了low！


670: Maximum Swap

https://leetcode.com/contest/leetcode-weekly-contest-48/problems/maximum-swap/


401: Binary Watch

https://leetcode.com/problems/binary-watch/description/

直接遍历解空间！不理解表的的实际运行换算进制搞错！


674: Longest Continuous Increasing Subsequence My SubmissionsBack to Contest

https://leetcode.com/contest/leetcode-weekly-contest-49/problems/longest-continuous-increasing-subsequence/

比较简单，但是这种题我是比较害怕的！


673: Number of Longest Increasing Subsequence

https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/

LIS，跟上一题很像！DP难在算法的理解。


354: Russian Doll Envelopes

https://leetcode.com/problems/russian-doll-envelopes/

LIS的变种，将二维数据其中一个维度升序另一个维度降序排序之后只关注降序排序的维度就是LIS。这个题很有意思，很有思考价值！


676: Implement Magic Dictionary

https://leetcode.com/contest/leetcode-weekly-contest-49/problems/implement-magic-dictionary/

set或者vector实现效率太低，字典树实现太难调试。使用set实现舒服多了！


416: Partition Equal Subset Sum

<https://leetcode.com/problems/partition-equal-subset-sum/description/>

一刷没AC，使用时间复杂度为O(N!)的backtracing算法，出现很多CE！最后TLE。
也有人说时间复杂度为O(pow(2, N))的！这是个典型的0/1背包问题，0/1背包问题的特点是从一组数中选取某些数达到一定的值。
[这是对0/1背包问题的一个很好的解释](https://discuss.leetcode.com/topic/67539/0-1-knapsack-detailed-explanation)

这一题使用的DP解法对标准0/1背包算法进行了优化，因为题目不需要知道更多的信息，
数组开一维就可以。数组开二维也可以，但是比较麻烦，需要更多的初始化，操作！

最优化方法是使用bitset的方法，时间复杂度为O(N)，空间复杂度为O(1)!


464: Can I Win

https://leetcode.com/problems/can-i-win/description/

时间复杂度为（dfs导致递归，时间复杂度不会分析），空间复杂度为O(2^N)。


467: Unique Substrings in Wraparound String

https://leetcode.com/problems/unique-substrings-in-wraparound-string/description/

时间复杂度O(N)，空间复杂度O(1)。
在理解大神思路的基础上自己实现一次AC。再刷一次！但是这个解法真的是DP吗？


221: Maximal Square

https://leetcode.com/problems/maximal-square/description/

自己的思路和大神的思路相似，我的思路不够简洁，大神使用square的边长表示square。
状态方程的理解：(i, j)是square,则(i-1, j-1), (i-1, j),(i, j-1)必定是size的square！
如果三者的size不同，则(i, j)取三者最小的加1。时间复杂度和空间复杂度都是O(M\*N)。


576: Out of Boundary Paths

https://leetcode.com/problems/out-of-boundary-paths/description/

思路正确，效率不高，时间复杂度和空间复杂度均为O(N\*n\*m)。大神的高效解法太好了。


693: Binary Number with Alternating Bits

https://leetcode.com/problems/binary-number-with-alternating-bits/description/

时间复杂度为O(log N)，空间复杂度为O(1)。


341: Flatten Nested List Iterator

https://leetcode.com/problems/flatten-nested-list-iterator/description/


173: Binary Search Tree Iterator

https://leetcode.com/problems/binary-search-tree-iterator/description/

和上题相似的思路，初始化时，遍历查找最左节点没有更新root会导致内存溢出。
时间复杂度为O(N)，空间复杂度为O(H)。


838: Push Dominoes

https://leetcode.com/contest/weekly-contest-85/problems/push-dominoes/

字符串题型。多米诺骨牌模拟题，一列骨牌，随机选择其中一部分使其左倾或者右倾，
每秒传递一张牌的距离。根据一张牌的左右两侧的牌决定其状态，直到状态不变为止。有点BFS的意思。


331: Verify Preorder Serialization of a Binary Tree

https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/description/

一刷使用自己的算法，没AC，看了讨论区，有大佬和我的算法相同，稍微修改了自己的代码AC。
注意考虑两点，数的长度不止为1，中间过程如果stack为空，直接返回false即可。再刷一次。



456: 132 Pattern

https://leetcode.com/problems/132-pattern/description/

不太理解为什么要用while循环，是为了使用更大的中间值？


402: Remove K Digits

https://leetcode.com/problems/remove-k-digits/description/


636: Exclusive Time of Functions

https://leetcode.com/problems/exclusive-time-of-functions/description/

并且自己设计了新的struct，效率可能会受影响，但是非常清晰。中间没对stack判空RE。再刷。


355: Design Twitter

https://leetcode.com/problems/design-twitter/description/

Heap。Heap效率并不是很高。明白了为什么有时候会和结果反序，
这是因为我写的堆排序的结果是升序，而这种题目一般要求要降序输出结果。


490: Maze

锁定了，写不了。
但是比较简单，至少有两种写法。
一是使用visited，二是将访问过的区域设置为阻隔，有个非常相似的题目，但是我给忘了。



659: Split Array into Consecutive Subsequences

https://leetcode.com/problems/split-array-into-consecutive-subsequences/description/


36: Valid Sudoku

https://leetcode.com/problems/valid-sudoku/description/

暴力法：检查行 检查列 检查每个小矩阵就行，这种方法要遍历board3次。
更巧妙的方法：记录每行、每列、每个小方块中每个数字是否使用过，如果使用过了，
就是invalid，这种方法只需遍历1次board，用空间换时间。注意数组的初始化！


452: Minimum Number of Arrows to Burst Balloons

https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/

贪心算法，自己陷入了一个有多种解需要遍历的怪圈，其实不需要。
按终点大小排序后直接从直径终点射出就可以了！
我的思路是每次找到重合最多的坐标点，刺破覆盖该位置的所有气球。
重复以上步骤直到气球全部被刺破，这个方法一定奏效，但是复杂度极高。
为什么贪心算法能work呢？


435: Non-overlapping Intervals

https://leetcode.com/problems/non-overlapping-intervals/description/

与452非常相似，但是并没有想到怎么做，
看[Wikipedia](https://en.wikipedia.org/wiki/Interval_scheduling#Interval_Scheduling_Maximization)没看太明白，
对于贪心还是不太理解。



649: Dota2 Senate

https://leetcode.com/problems/dota2-senate/description/

queue。用queue对游戏进行模拟，一方将另一方ban掉，靠前的那一方ban，
靠后的那一方被ban，而且ban的那一方经过这一轮之后下一轮仍然可以投票，
所以要将这个数加上N之后放到队列末尾。



324: Wiggle Sort II

https://leetcode.com/problems/wiggle-sort-ii/description/

Follow up很有料!。


296: Best Meeting Point

这是一道锁定题。横轴纵轴互不影响，可以将两个维度直接拆开，每个维度排序之后去掉单个的中间节点，加上剩余配对的节点之间的距离即可。


525: Contiguous Array

https://leetcode.com/problems/contiguous-array/description/

核心公式diff[i, j] = diff[0,j] - diff[0,i]，diff表示1比0多的个数，
数组的一小段的diff等于整个数组的起始位置到段结尾的diff减去全数组起始位置到段起始的diff。
当两个diff相等，表示中间的小段0和1的个数相同，更新结果。一刷没AC，注意处理空数组（diff要多加一个空位，map也要！）。


538: Convert BST to Greater Tree

https://leetcode.com/problems/convert-bst-to-greater-tree/description/

一开始思路不好，只想着记录父节点，导致重复计算，要再想一下为什么！
使用sum记录当前访问的最大值，是最吼的，逆先序遍历即可。



655: Print Binary Tree

<https://leetcode.com/problems/print-binary-tree/description/>

合并左右子树的时候思路要清晰，分情况，不是两边一直用空串填充，
而是每个元素两侧都使用空串填充！一步步简化代码，对容器的insert函数用熟了！



236: Lowest Common Ancestor of a Binary Tree

https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

两个节点的LCA，非常经典！O(N)时间复杂度，递归找path，选出最后一个相同节点，这是最蠢的方法！


747: Largest Number Greater Than Twice of Others

https://leetcode.com/contest/weekly-contest-64/problems/largest-number-greater-than-twice-of-others/

数组最大值，简单题


284: Peeking Iterator

https://leetcode.com/problems/peeking-iterator/description/

系统设计题，考的是拷贝构造函数的应用。


307: Range Sum Query - Mutable

https://leetcode.com/problems/range-sum-query-mutable/description/

一刷使用暴力解法AC，时间复杂度为O(N)。用线段树和二分索引树做时间复杂度可以降到O(log N)。


729: My Calendar I

https://leetcode.com/problems/my-calendar-i/description/

TreeMap。判断多条线段是否存在交集，可以用java的TreeMap轻松实现。
对于任意一个新加入的线段，分别判断起点start的floorKey和ceilingKey记录的线段与新加入的线段是否有重叠即可。

731: My Calendar II

https://leetcode.com/problems/my-calendar-ii/description/

这是一道什么类型的题？还有什么其他方法？这类interval的题目还是比较多的。一刷使用逐一重叠并记录的方法。


220: Contains Duplicate III

https://leetcode.com/problems/contains-duplicate-iii/description/

一刷暴力法，O(NK)的时间复杂度，TLE。二刷使用基于bucket的方法AC。



758: Bold Words in String

https://leetcode.com/contest/weekly-contest-66/problems/bold-words-in-string/

转化为合并interval


759: Employee Free Time

https://leetcode.com/contest/weekly-contest-66/problems/employee-free-time/

同上题，转化为合并interval。


2018.1.11.1 Round Robin

轮询调度，带权重的轮询调度

最大公约数、多个数的最大公约数、轮询调度


762: Prime Number of Set Bits in Binary Representation
给定一个范围，判断范围内的每个数的二进制表示中1的个数是否为质数
bitset


763: Partition Labels

将仅含有小写字母的字符串，要求划分后子串尽可能多而且每个字母最多出现在一个划分中。

DFS超时，贪心AC。



65: Valid Number

https://leetcode.com/problems/valid-number/description/

正则表达式，注意trim之后再进行正则表达式匹配。


125: Valid Palindrome

https://leetcode.com/problems/valid-palindrome/description/

字符相关API如：isdigit,isalpha,isalnum,isupper,islower要用熟。



766: Toeplitz Matrix

查看矩阵的每条斜向下对角线上的元素是否相同


767: Reorganize String

将字符串重排，要求相邻的两个字母不同，dfs超时，应该用优先级队列。


769: Max Chunks To Make Sorted (ver. 1)

给定数组为下标的一种排列，将数组进行partition，要求每个子数组排序后整个数组也有序，
给出合法的partition后最多的子数组个数。


768: Max Chunks to Make Sorted (ver. 2)

与上题不同的地方在于数组中元素可以有重复。


775: Global and Local Inversions

https://leetcode.com/contest/weekly-contest-69/problems/global-and-local-inversions/

array。


796: Rotate String

字符串旋转。先判断字母表是否相同，然后逐位旋转一个字符串，看是否与另一个相同，
O(N^2)。要旋转字符串s的一部分s[i,j]，需要调用reverse(s.begin() + i, s.begin() + j + 1)，
c++的尾迭代器都是一个字符的下一个，可以参考s.end()迭代器的使用。



715: Range Module

https://leetcode.com/problems/range-module/description/

TreeMap。使用key记录区间[start, end)的起点，value记录终点。
添加、删除、查询区间都可以很快完成。
TreeMap适合这个场景，floorKey和ceilingKey两个API非常好用，可以用这两个API遍历不相邻的区间。
