#### BS

154: Find Minimum in Rotated Sorted Array II

<https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/>

BS。

164: Find Minimum in Rotated Sorted Array

<https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/>

和154一模一样。


74: Search a 2D Matrix

<https://leetcode.com/problems/search-a-2d-matrix/?tab=Description>

BS，将矩阵降为视为一维数组用BS。index的映射关系:`matrix[mid / n][mid % n]`。


668: Kth Smallest Number in Multiplication Table

https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/

heap: 用一个小根堆模拟排序过程，小根堆中每个元素是pair，来分别存储乘法表中的基数和乘积，用乘积排序。
每次出队列的时候，如果乘积加上基数之后的值在乘法表范围内，将增大的乘积加回队列。

BS: 每一行中比目标值小的数的个数通过一次除法即可算得，这个发现可以直接将算法的计算复杂度降级。
我发现了这一点，但是一直想在坐标和排序之间建立联系！BS就是通过一个指标，
将一个区间严格分为两半。对于BS的理解又深了一点！


410: Split Array Largest Sum

https://leetcode.com/problems/split-array-largest-sum/

BS：左边界为0，右边界为sum。将数组按连续的方式分组，每组的和不大于mid。
分组个数大于m说明mid不够，更新low；否则更新high。BS有两种写法，这两种写法是等价的！


870: Advantage Shuffle

https://leetcode.com/contest/weekly-contest-93/problems/advantage-shuffle/

贪心算法。给定两个大小相同的数组`a`和`b`，随意调整`a`中元素的顺序，
找出一种排列顺序使同位置上的`a`中元素比`b`中元素大的个数最多。
分析题目的测试用例的数据规模，不能用DFS，结合之前参加校级ACM决赛的经验，这个题是有迹可循的，当时的解决方法也是贪心算法。

* 我的思路：先将`b`排序，然后遍历`a`，为`a`中每个元素$x$在`b`中找出第一个比$x$小且没有被分配过的元素$y$。
这种做法比较低效,较好状况下时间复杂度为$O(N\log N)$， 
这种情况下每次BS找到的$y$都是距离$x$最近的，最坏情况下的时间复杂度为$O(N^2)$。
	* 最好情况下的例子: `a`=$[12,24,8,32]$，`b`=$[13,25,32,11]$
	* 最差情况下的例子: `a`=$[15,16,17,18]$，`b`=$[13,12,14,11]$，
	这种情况下每个`a`中的每个数字找到的都是距离自己最远的，需要往回走继续找。
* 最优思路：将`a`和`b`同时降序排序，记录`b`中元素原始的位置。
然后使用滑动窗口方式，遍历`a`和`b`，分别用`i`和`j`来记录`a`和`b`中下次匹配的起始位置，
`j`一定会比`i`率先到达终点，这表示`a`中能在`b`找到对应元素$y$的$x$都已经找到对应的元素(距离最近的较小的元素)了，
然后`j`从0重新开始，`i`不变，继续滑动窗口遍历，将`b`中没有用掉的$y$随意塞给`a`中的$x$。
这其实是一种TP算法，但是算法的思想有一点贪心在。


774: Minimize Max Distance to Gas Station

https://leetcode.com/contest/weekly-contest-69/problems/minimize-max-distance-to-gas-station/

BS。与其他题目不同的是本题需要在整个限制范围内部进行BS，
MSRA有一道题和本题相似，都是在整个限制范围内找解，这是一种很重要的思路，DP有时候也会用到这种思想。


4: Median of Two Sorted Arrays

https://leetcode.com/problems/median-of-two-sorted-arrays/description/

BS，TP。查找两个有序数组$a_1,a_2$组成的大数组$a$的中位数，时间复杂度要求$O(\log{(m+n)})$。
* TP: 模拟归并排序的merge过程，分别查找使用两个指针$p,q$排序后的$a$中的
元素$a_{(m + n + 1) / 2}$和$a_{(m + n + 2) /2}$，求两者的平均数，时间复杂度$O(m+n)$。
* BS: 递归实现BS，与TP类似，在查找两个元素的过程中，比较的关键步骤，
分别从$a_1,a_2$中取出中位数$a_1[i]$和$a_2[j]$，比较两者，
小的那个所在的数组的前一半可以舍弃掉，这样就将问题的规模缩减了一半，时间复杂度$O(\log{m + n})$。


35: Search Insert Position

https://leetcode.com/problems/search-insert-position/?tab=Description

BS。可以直接用`upper_bound`或者`lower_bound`来做。


34: Search for a Range

https://leetcode.com/problems/search-for-a-range/?tab=Description

BS。BS查找下界和上界两类问题存在区别，区别在于求下界时mid要靠近low，求上界的时候mid要靠近high；
这种区别决定在每次循环更新要找的那个界限（low或者high）。也可以直接使用STL的`upper_bound`和`lower_bound`。

33: Search in Rotated Sorted Array

https://leetcode.com/problems/search-in-rotated-sorted-array/?tab=Description

BS。先拿$a_{mid}$和$a_{low}$比较，是为了确定$a[mid]$在较大的前半部分还是较小的后半部分，
$a_{mid}$在前半部分的条件就是$a_{low} \leq a_{mid}$。
然后再根据$target$所处的位置分类。不能先用$target$进行分类，因为$target$可能不存在于数组中。


81: Search in Rotated Sorted Array II

https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

BS。同33，只是数组中存在重复元素，$a[mid] = a[low]$时分类不明显，直接拎出来，令`low++`(相当于遍历)，其余不变。


875: Koko Eating Bananas

https://leetcode.com/problems/koko-eating-bananas/description/

BS。有$N$堆香蕉，记为$P$，每堆有$P_i$个香蕉，KOKO要在$H$小时内把香蕉吃完，
KOKO可以控制自己每小时吃的最多香蕉数$K$，而且每小时只选择一个香蕉堆吃香蕉，计算KOKO完成吃香蕉任务最小的$K$。

$K \in  [\sum_{i} P_i, \max_i{P_i}]$，已知上界和下界，用BS找目标元素$t$即可，目标元素$t$需要满足$\sum_{i}P_i/t$的上界 $<= H$。


483: Smallest Good Base

<https://leetcode.com/problems/smallest-good-base/>

BS。将一个数分解为多个项，每一项系数都是1，但是基数成等比数列。
项数范围是[2,63]，逆序遍历项数，BS查找底数。注意防溢出，用除法判断溢出是最好的。


786: K-th Smallest Prime Fraction


<https://leetcode.com/problems/k-th-smallest-prime-fraction/>

多种解法，这是一类题，跟微软小冰组的那个找定基数不定指数的第k大问题类似，

* Heap: 用priority_queue解决很简单。
* 二维bs。

leetcode上有个人总结了这类题，看着还挺好的，
[这是传送门](https://leetcode.com/problems/k-th-smallest-prime-fraction/discuss/115819/Summary-of-solutions-for-problems-%22reducible%22-to-LeetCode-378)。


69: Sqrt(x)

https://leetcode.com/problems/sqrtx/#/description

BS。注意0和mid * mid == x的情况。需要求更精确的平方根时可以用Newton法。

Newton法：求$x$的平方根即求$f(t) = t^2 - x$的根，根据牛顿法的思想，
在二次方程中，通过迭代切线根会逐渐收敛到曲线根，初始化$t_n = 1.0$，
不断地通过$t_{n+1}=t_n - \frac{f(t_n)}{f'(t_n)}$迭代，
直到$|t_n - t_{n+1}| <= \epsilon$即可。更细节的推理可以参考[该知乎问题的答案](https://www.zhihu.com/question/20690553)。


392: Is Subsequence

https://leetcode.com/problems/is-subsequence/description/

Follow up需要BS。


162: Find Peak Element

<https://leetcode.com/problems/find-peak-element/>

BS。二分法可以用递归和非递归的方式实现，复杂度为$O(logN)$。本题是一维数组找极值，
MS有道题是二维数组找极值，思路相同，二分，$O(N)$时间找行的最小值，跟相邻行比较，
如果是极值点则结束，不是就找更小的那个子矩阵。fun的水滴证明法相当直观！



367: Valid Perfect Square

https://leetcode.com/problems/valid-perfect-square/#/description

BS。一刷没有AC。注意一个公式1 + 3 + 5 + 7 + 9 + …… = n^2!因为mid设为int，结果溢出得了WA。


