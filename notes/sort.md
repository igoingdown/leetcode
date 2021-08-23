#### sort专题

56: Merge Intervals

https://leetcode.com/problems/merge-intervals/?tab=Description

sort。sort的第三个参数为重载了`<`的函数，可以自己写myCompare函数实现`<`逻辑，
也可以写函数类用于构建函数对象，也可以利用C++11新特性lambda表达式实现，
编译器会根据lambda表达式生成函数对象。


57: Insert Interval

https://leetcode.com/problems/insert-interval/description/

本题至少有两种方法：

* 方法一：sort，同上题。先将要新Interval插入列表，sort后按上题的思路merge。
$O(N\log{N})$
* 方法二：由于题目给定的Interval列表已经有序，插入新的Interval不需要重新对列表排序。
扫一遍Interval列表，当前的Interval如果能merge到新Interval中，则更新新的Interval，
如果不能更新，没有交集且当前的Interval在新的Interval前，则直接加入结果，
如果没有交集且当前的Interval在新的Interval之后，直接退出扫描。
将新的Interval和剩下的Interval逐个加入结果列表中。
这是fun的方法，实际上模拟了上题合成单个Interval的过程，$O(N)$。


406: Queue Reconstruction by Height

<https://leetcode.com/problems/queue-reconstruction-by-height/description/>

sort。使用lambda表达式进行sort，然后将每个元素插到`res`的`res.begin()+p.second`的位置上。
C++中的lambda表达式的书写规范为:`[](const T &a, const T &b){return a < b}`。


75: Sort Colors

<https://leetcode.com/problems/sort-colors/>

* 排序算法：手写快排、堆排等时间复杂度都是O(NlogN)。
* 暴力法：第一次遍历记录0，1，2的数量，第二次遍历按照数量赋值上去，$O(N)$。
* TP：$O(N)$。令$index_0$和$index_2$分别表示下一个0和2应该填进去的坑，
扫一遍数组，将0放在swap到前面，2swap到后面，1自然就被swap到中间了。
* 变式题是阿里的二面算法题。RGB无序序列排成RGBRGB形式的序列，三指针。


215: Kth Largest Element in an Array

https://leetcode.com/problems/kth-largest-element-in-an-array/description/

快排。快排的partition函数不止可以用挖坑填坑的方式写。


347: Top K Frequent Elements

https://leetcode.com/problems/top-k-frequent-elements/description/

一刷使用map统计频率，按频率倒排，使用lambda表达式简化代码，O(NlogN)。
二刷使用堆排，O(NlogN)。三刷使用快搜，O(N)。四刷使用priority_queue，O(NlogN),其实就是完全堆排。
五刷简化四刷使用的方法，不再使用函数对象。
五刷使用桶排序，bucket_size为1，将每个可能的频率都视为一个bucket，O(N)。
建堆时间复杂度证明：http://blog.csdn.net/anonymalias/article/details/8807895


164: Maximum Gap

https://leetcode.com/problems/maximum-gap/description/

Bucket Sort。 

* 暴力算法：先sort然后遍历，O(NlogN)的时间复杂度。
* Bucket sort: 题目要求O(N)的时间和空间复杂度，桶排序可以满足要求，时间和空间复杂度都是O(N)。
最重要的思想是有多少数就准备多少个桶，最差情况下一个数一个桶，这是桶排序最核心的思想。
先准备`len(nums)`个桶然后计算桶的size，计算出桶的size之后实际需要用到的桶的个数，
因为这些数据中有重复出现的数，扣除这些重复出现的数可以极大地节省内存空间。一个case是`nums`中有99个99和1个100。
这种情况下如果不计算实际用到的桶的个数，会发现要准备100个桶，而实际用到的桶只有2个！


179: Largest Number

https://leetcode.com/problems/largest-number/description/

排序。可以直接对数字排序，然后逐个加进来。要更深入地理解为什么这样能work！


