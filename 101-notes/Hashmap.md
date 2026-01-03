#### Hashmap专题

389: Find the Difference

<https://leetcode.com/problems/find-the-difference/>

HashMap。对于字符串的常用方法，将字符转为数组下表，从而将空间复杂度降到O(N)。

169: Majority Element

<https://leetcode.com/problems/majority-element/>

Math，鸽巢原理，投票法。同权投票众数的票数最多，一定胜出。

128: Longest Consecutive Sequence

<https://leetcode.com/problems/longest-consecutive-sequence/>

HashMap，空间换时间。每次遇到没访问过的元素，访问之，
并查看该元素所在最长连续序列的长度，更新结果，$O(N^2)$。使用unordered_map记录访问元素的最大长度。
当n-1和n+1都访问过后，将序列两端的元素对应的最大长度更新。
因为之后序列内部的元素就不考虑了，只会考虑序列外的元素，
而序列外的元素跟该序列可能链接的地方只有左右两端，这个题很像DP，
注意要将该元素设为访问过的状态，要向map中添加pair，$O(N)$。

719: Find K-th Smallest Pair Distance

<https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/>

Hashmap，已知距离的范围，用vector对所有的距离进行计数，最后找出第k小的距离。


381: Insert Delete GetRandom O(1) - Duplicates allowed

<https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/description/>

* Hashmap
  * 使用`map`和 `set`记录下标，加速访问与删除操作，`map`的 key 为数组元素，`val` 为 `set`，`set`记录`val`在 `nums`的下标

  * 插入和删除都只能从数组 `nums` 的尾部进行，因此删除的不是数组尾部元素时，需要先调换再删除，确保时间复杂度为 $O(1)$

  * `random`函数只要随机从nums中任选一个即可，因为这种情况下数组中每个元素被选中的概率相同，



873: Length of Longest Fibonacci Subsequence

<https://leetcode.com/contest/weekly-contest-94/problems/length-of-longest-fibonacci-subsequence/>

Hashmap。给定一个数组$A$，找出其中最长的满足斐波那契规律的子序列的长度。

由于题目只需要知道最长的斐波那契子序列的长度，可以暴力解决。
为了方便查找，将数组拷贝一份到Hashmap中，遍历所有可能的子序列，
开头分别是$A_i$和$A_j$，$i<j$，如果Hashmap包含$sum = A_i + A_j$，则令$A_i = A_j, A_j = sum$，
重复以上过程，记录可能得到的最大长度，时间复杂度为$O(N_3)$。


874: Walking Robot Simulation

<https://leetcode.com/problems/walking-robot-simulation/description/>

Hashmap。给定一个边界无限的二维平面和一个初始处于这个平面上原点面向$Y$轴正向的机器人，
二维平面上有些障碍物$O$无法通过，给定一组命令$C$，每条命令为一个整数，正整数表示前进的距离，
$-1$表示右转，$-2$表示左转。机器人执行命令，前进过程中如果遇到障碍物会停下，
直到转向绕过障碍物。问机器人**执行命令过程中到原点的最远欧式距离**。

从原点出发，模拟机器人执行命令的路线，更新能够导到的最远距离。
只要比较每条命令执行完机器人所处的位置到原点的距离和已知最大距离即可，
因为沿着单一方向移动过程中的，机器人所处的位置到原点的欧式距离不可能有极（最）大值，
只有中间停顿处才可能出现极（最）大值。


500: Keyboard Row

https://leetcode.com/problems/keyboard-row/#/description

HashMap。使用vector表示map，`tolower()`、`toupper()`、`isupper()`、 `islower()`和`isalpha()`
这一系列处理char的函数都处于相同的命名空间。


138: Copy List with Random Pointer

https://leetcode.com/problems/copy-list-with-random-pointer/#/description

HashMap。使用hashmap记录就链表节点到新链表节点的对照，然后按单链表的顺序复制即可。


822: Card Flipping Game

https://leetcode.com/contest/weekly-contest-81/problems/card-flipping-game/

Hashmap。要求正面字符不能出现在反面，考察规律，出去正反面数字相同的牌，
一定有一种方式，将所有相同数字全都排在正面。
因此只要记录正反面相同的牌的数字，除去这些数字，找牌上出现的最小的数字即可。

49: Group Anagrams

https://leetcode.com/problems/anagrams/#/description

HashMap。`map`使用红黑树实现，而`unordered_map`基于hash table，
使用hash型数据结构必须保证key的类型有`hash()`方法，容器类型除了string外默认是没有`hash()`方法的，
而非hash型数据结构没有限制！
c++中对于`map`和`unordered_map`，使用[]方法访问当key不存在时调用value的默认构造函数。


12: Integer to Roman

https://leetcode.com/problems/integer-to-roman/#/description

HashMap,Math。自己建立map，将阿拉伯数字与罗马数字字符串对应起来。

13: Roman to Integer

https://leetcode.com/problems/roman-to-integer/description/

HashMap,Math。上题的逆过程，扫一遍字符串，如果当前字符比后一个字符的权值大，做减法，否则做加法。


146: LRU Cache

<https://leetcode.com/problems/lru-cache/description/>

Hashmap和list。

* `STL`的`list`基于双向循环链表实现，不用自己写链表，简化了代码
* `list`提供`splice`接口，`splice` 意为“通过交织两股绳子的末端实现连接”，这一操作被水手广泛用于绳结的加固。其核心含义是 ​​“无痕连接”​​ 或 ​​“重组”​，实际上就是双向链表的节点插入操作的细化，先拆链，再插链，有 3 种重载实现形式，可以插入单点、部分链表和完整链表。
* 将`list`中刚刚使用过的元素调度到`list`的首部，这是LRU的核心思想
* `put`操作的实现中，不仅要修改`list`和相应的迭代器，还有`list`中的值和`map`。
* 这种实现中元素优先级越高，使用越频繁，在`list`中的位置越靠前，删除只会在`list`的尾部进行，而`hashmap`的删除操作随时随时都可以进行。
* 注意：`stl`的`front`和`back`的实现都是返回元素的可变引用，`begin`和 `end`的实现均返回迭代器，且`end`遵循迭代器左闭右开约定，返回的是最后一个元素的下一个位置

290: Word Pattern

<https://leetcode.com/problems/word-pattern/description/>

双map。
* 很好的一道题，注意双向 map 匹配和size 匹配，用 stringstream 挨个读很容易漏掉最后一步 size 匹配。


771: Jewels and Stones

<https://leetcode.com/contest/weekly-contest-69/problems/jewels-and-stones/>

HashMap。


383: Ransom Note

<https://leetcode.com/problems/ransom-note/>

HashMap。用串`a`合成串`b`，只要串`b`中的每个字符的频数都不大于串`a`中对应的字符频数即可。


409: Longest Palindrome

<https://leetcode.com/problems/longest-palindrome/>

HashMap。记录每个字母的个数，是偶数的话可以直接分两部分拼到结果的两侧，如果字母个数为奇数个，剩下一个其余分两部分拼到结果的两侧。
如果有字母个数为奇数，可以将剩余的那个作为结果palindrome的轴（轴只有1个）。


451: Sort Characters By Frequency

<https://leetcode.com/problems/sort-characters-by-frequency/#/description>

HashMap。`Solution`类内部定义的`MyCompare`要用static关键字，
因为在调用排序函数的时候编译器没有`Solution`类对象信息!map使用[]操作查询时，
不存在的键会自动生成！而值会调用相应的默认构造函数！。


451: Sort Characters By Frequency

https://leetcode.com/problems/sort-characters-by-frequency/#/description

HashMap。`Solution`类内部定义的`MyCompare`要用static关键字，
因为在调用排序函数的时候编译器没有`Solution`类对象信息!map使用[]操作查询时，
不存在的键会自动生成！而值会调用相应的默认构造函数！


760: Find Anagram Mappings

https://leetcode.com/contest/weekly-contest-66/problems/find-anagram-mappings/


291: Word Pattern II

https://www.programcreek.com/2014/07/leetcode-word-pattern-ii-java/

双map和dfs结合。strStart应该更新为i + 1而不是i。


734: Sentence Similarity

https://leetcode.com/contest/weekly-contest-60/problems/sentence-similarity/

Hashmap，没理解题意，sentence相似要求每个位置的word都相似！第一次用python刷题，比c++快多了，在数据结构涉及set，string等结构时，python非常方便。

846: Hand of Straights

https://leetcode.com/contest/weekly-contest-87/problems/hand-of-straights/

Hashmap。跟上面的那道题有异曲同工之妙，因为map基于红黑树实现，默认根据key的大小排序！
用map记录数组中数字的频率，每组的起点一定是当前map的key的起点，
每组要消耗一个数，消耗完就将其移除这个key。只要出现一次key的缺失，则失败！


811: Subdomain Visit Count

Hashmap。使用istringstream和getline对字符串进行处理，用map进行存储。


