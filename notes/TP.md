#### TP专题


228: Summary Ranges

<https://leetcode.com/problems/summary-ranges/>

TP。用`b,e`分别记录range的起、止index，
初始化`b,e`均为range的起始index，然后尝试将`e`后移，移出该range后将该range加入结果列表，
然后`b`初始化为`e`，开始下一轮尝试。


38: Count and Say

https://leetcode.com/problems/count-and-say/description/

TP。将序列模仿出来即可。


11: Container With Most Water

https://leetcode.com/problems/container-with-most-water/?tab=Description

TP。左右指针分别从数组两端开始，两指针夹逼过程中，矩形的长变小，只有宽增大，面积才可能增大。


67: Add Binary

https://leetcode.com/problems/add-binary/description/

TP。双指针后向遍历，最后将得到的结果逆转。

821: Shortest Distance to a Character

https://leetcode.com/contest/weekly-contest-81/problems/shortest-distance-to-a-character/

TP。string中里指定字符最近的距离，分别从左侧和右侧使用TP进行遍历。

820: Short Encoding of Words

https://leetcode.com/contest/weekly-contest-81/problems/short-encoding-of-words/

TP。将后缀通过反转转为前缀，sort，出去子串长度即可，加法不好做，可以换到减法。


833: Find And Replace in String

https://leetcode.com/contest/weekly-contest-84/problems/find-and-replace-in-string/

TP。在字符串中进行多次互不影响的替换，先替换前面的，再替换后面的，用一个bias记录全局的偏移量。
由于sources和targets中的字符串都要按照indexes中的index的顺序排序，
使用map记录string到index的映射会有问题，因为key有可能存在重复。


214: Shortest Palindrome

https://leetcode.com/problems/shortest-palindrome/description/

TP。把原始串补成回文字符串的两个极限情况是：
1. 以第一个字符为中心，将后面的字符串补齐
2. 原始串就是回文串（中心是原始串的中点），不需要补齐
这样就可以分析出来原始串补齐之后形成的回文串的中点的位置范围，
从原始串的中点开始，向左遍历找到第一个可以通过补全就能得到回文串的位置即可。


855: Exam Rooms

https://leetcode.com/contest/weekly-contest-89/problems/exam-room/

TP。 用set记录已经被占领的座位，由于set基于红黑树实现，可以对元素默认进行升序排序。
每次有新的人要加入考场，遍历set，找相邻且距离最远的两个元素，
第一个元素和最后一个元素单独考虑，因为他们只有一个边界，其余元素都有两个边界。

868: Binary Gap

https://leetcode.com/contest/weekly-contest-93/problems/binary-gap/

TP。找一个正整数`N`的二进制表示中，距离最远的两个`1`之间的距离。之间利用`bitset`将问题转化为TP问题。

567: Permutation in String

https://leetcode.com/problems/permutation-in-string/#/description

滑动窗口，TP。


455: Assign Cookies

<https://leetcode.com/problems/assign-cookies/>

TP。给出两个序列`g`和`s`，![](http://latex.codecogs.com/gif.latex?{g_i})代表能满足第`i`个孩子要求的最小cookie的size，
![](http://latex.codecogs.com/gif.latex?{s_j})表示第`j`个cookie的size。问如何分配使得到满意的孩子最多。

先将`s`和`g`升序排序，然后用双指针解决，
这个方法的核心思路是优先给需求低的孩子分配cookie，这么做可以最大化收益：将得到满足的孩子个数最大化。

STL的`algorithm`库中的`sort(beg, end, comp)`函数实际使用快排，其中的`comp`是函数对象或者函数指针，
签名是 `bool comp(elem_type first_arg, elem_type second_arg)`，
返回的`bool`值的含义是第一个参数是否应该排在第二个参数的前面，默认参数会将较小的参数排在前面，即`sort`函数默认升序排序。

如果需要降序排列，可以用STL中的`greater`，比如讲一个`vector<int> a`降序排序，可以调用`sort(a.begin(), a.end(), greater<int>())`


109: Convert Sorted List to Binary Search Tree

<https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/#/description>

TP。同108，区别在于本题中`mid`要通过快慢指针来找。


3: Longest Substring Without Repeating Characters

<https://leetcode.com/problems/longest-substring-without-repeating-characters/#/description>

滑动窗口，TP。使用一个长为256的`vector`记录每个`char`上次出现的位置，
用`start`记录当前无重复字符子串的起始位置，窗口右侧遇到一个已经访问过的`char`，
窗口左侧`start`移到该`char`上次出现位置的后一位。


209: Minimum Size Subarray Sum

<https://leetcode.com/problems/minimum-size-subarray-sum/>

TP，滑动窗口。同第3题思路相同，用`i,j`分别记录当前subarray的和与起、止位置，用`sum`记录subarray的和，当`sum >= s`时尽量左移`i`，左移结束更新`ans`。


557: Reverse Words in a String III

https://leetcode.com/problems/reverse-words-in-a-string-iii/#/description

TP。字符串内部单词反转。

用`b`和`e`分别记录每个单词的起始字符的index和末尾字符的下一个index，然后用`reverse(s.begin()+b, s.begin()+e)`反转单词即可。

1: Two Sum

https://leetcode.com/problems/two-sum/description/

* 方法一： Map。对于数组中的每一个元素$A_i$，
使用multimap存储键值对$(target - A_i, i)$。
再次遍历数组的每个元素$A_j$, 如果$A_j$是multimap的key且对应的value不等于$j$。
因为题目的限制，multimap也可以用map代替。基于map的时间复杂度为$O(N)$。

* 方法二：TP。先拷贝数组$A$到$copy$中，sort $copy$，
首尾指针$l$和$r$分别向中间移动使首尾指针指向的元素的和$sum$逐渐向$taret$靠拢。
最后再$A$中分别查找$copy$数组的首尾指针$l$和$r$指向的元素在$A$中对应的元素。
时间复杂度为$O(N\log{N})$。


15: 3Sum

https://leetcode.com/problems/3sum/description/

TP/MP。类似上题的**方法二**，先对数组排序，前向遍历数组先固定一个指针`i`，
这样$sum$中的一个元素就有了，剩下的问题就是一个 **Two Sum**问题了。

注意去重，`i`,`l`,`r`三个指针都要去重。

16: 3Sum Closest

https://leetcode.com/problems/3sum-closest/?tab=Description

TP/MP。同15，先sort，然后逐个确定`i`,`l`,`r`三个指针，
注意三个指针都要去重。**和15相同，去重的原则是计算过的组合不必继续计算，
这种情况下解空间树仍然有很好的作用，非常清晰！**

18: 4Sum

https://leetcode.com/problems/4sum/?tab=Description

TP/MP。先进行sort，然后逐个确定i,j,l,r四个指针，注意去重和剪枝(非必须)。


454: 4Sum II

https://leetcode.com/problems/4sum-ii/#/description

TP/MP，HashMap。同上题，由于题目不需要找出符合条件的各个数的index，
可以先遍历两个指针的结果并用HashMap存储，之后遍历另外两个指针并在HashMap中查找。
这样一个$O(N_4)$的问题就降到了$O(N_2)$。


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

TP，先将快指针定位到n + 1处，维持快慢指针的间隔，直到快指针到了fast处，
将慢指针后面的节点删除。注意要使用dummy节点作为新的头结点。


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

<https://leetcode.com/problems/linked-list-cycle-ii/#/description>

TP，链表成环检测。设置快慢指针，快指针每次走两步，慢指针每次走一步，如果两者相遇则有环。
此时令快指针从头开始走，快慢指针一次走一步，直到两者相遇，相遇点就是环的起点。

数学解释：记链表起点`head1`到环的起点`head2`的距离为`l`，从环起点`head2`出发到快慢指针
相遇点`P`至少要经过的距离为`x`，环长为`c`，则有以下推论:

1. ![](http://latex.codecogs.com/gif.latex?{l+x+m\*c=2(l+x+n\*c)})
1. ![](http://latex.codecogs.com/gif.latex?{l+x=k\*c})

* 链表环相关问题：
  1. 是否有环（slow和fast是否相遇）
  2. 环长（相遇后以原方式继续走，到两者再次相遇（还是到碰撞点，可画函数图像），记录走过的距离即可）
  3. 环起点位置（相遇后slow从head开始，fast从碰撞点出发，一次走一步，相遇处就是连接点位置）
  4. 链表长度（基于2和3可得）
* 引申的链表相交问题：可以根据两个链表是否成环分为三类
    1. 两个都没环：判断两者最后一个节点是否相同
    2. 一个有环，一个没环，不可能相交
    3. 两个都有环，看一个链表的碰撞点是否在另一个链表的环内，因为若相交，环一定共享！


287: Find the Duplicate Number

<https://leetcode.com/problems/find-the-duplicate-number/>

BS，TP。TP是将问题转化为链表成环检测问题，
将数组下标视为指针，数组元素视为链表节点值，则题目条件中的数组构成了一种**P**字形的逻辑结构，
因为必有一个节点存在两个指针入口，一个指针出口，切入口和出口之间呈环形结构，区别只是环的大小而已。
找重复元素就是找指针入口，即找环的起点。

92: Reverse Linked List II

https://leetcode.com/problems/reverse-linked-list-ii/#/description

TP，头插法。分别用pre和end记录要翻转的部分的前一个节点和后一个节点，然后使用头插法即可。

61: Rotate List

https://leetcode.com/problems/rotate-list/#/description

TP。注意要首先得出链表长度`len`，再将旋转次数对`len`取模，避免多余计算和可能的错误。
指针先走`k%len`步，慢指针跟上，一直走到快指针走到尾节点，将尾节点链到头结点上，慢指针指向的节点就是新的头结点！


83: Remove Duplicates from Sorted List

https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

TP。用`pre`和`cur`两个指针，每次循环让`cur`走到`cur`和`cur->next`不等，`pre = cur，pre=cur->next, cur=cur->next`。


82: Remove Duplicates from Sorted List II

https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/#/description

TP。同83，记录`cur`的重复次数，只重复一次将`cur`添加到结果链表中，重复多次直接将`cur`跳过。


86: Partition List

https://leetcode.com/problems/partition-list/#/description

TP。设置两个dummy node对于两部分分别进行尾插法，形成两个链表然后接上。

9: Palindrome Number

https://leetcode.com/problems/palindrome-number/description/

TP或者看逆数与原数是否相等，注意本题中负数不合法。


88: Merge Sorted Array

https://leetcode.com/problems/merge-sorted-array/description/

TP。我用了堆，用了temp，空间复杂度高。最优解是将较长的数组扩充，
然后倒着插入，思路类似快排，挖坑填坑。


44: Wildcard Matching

https://leetcode.com/problems/wildcard-matching/description/

DP,DFS,TP。与**10**不同的地方在于匹配规则是`'*'`可以匹配任意长度的字符串，`'?'`可以匹配单一字符。

* DFS超时。
* DP思路甚至公式和上题都非常相似:
	1. $p[j]$`=='*'`:`dp[i][j] = dp[i-1][j] || dp[i][j-1]`
	2. $p[j]$`!='*'`: `dp[i][j] = dp[i-1][j-1] && (s[i] == p[j] || p[j] == '?')`
* TP才是这道题的最优解，但是DP也不错，可以参考[这篇博客](https://yucoding.blogspot.com/2013/02/leetcode-question-123-wildcard-matching.html)。


76: Minimum Window Substring

<https://leetcode.com/problems/minimum-window-substring/description/>

TP，将直通硅谷老师的思路改进如下：
1. 分别用`aMap`与`tMap`存储符合条件的子串($S[i,j]$)与$T$中的字符及对应的频率。 
2. for循环优先开拓右边界`j`，如果左、右边界限定范围内的子串包含$T$，然后逐渐压缩左边界`i`至无法压缩为止，此时的子串$S[i,j]$为一个候选解:
	1. 先将$S[j]$添加到`aMap`中
	2. 尝试更新`count`（记录当前时刻$T$中没有被子串$S[i,j]$包含的字符个数）
	3. 如果子串$S[i,j]$满足条件`count == 0`,使用`while`循环右移`i`至无法右移为止，右移结束后，更新`min_len`和`min_start`。


