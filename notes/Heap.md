#### Heap

23: Merge k Sorted Lists

https://leetcode.com/problems/merge-k-sorted-lists/description/

Heap。
* 经典题，`priority_queue`构造函数的第三个模版参数使用lambda表达式时，需要加 decltype 且需要传入实参对象，不如函数模版(重载`()`操作符)方便
* 时间复杂度$O(NK\log{K})$


632: Smallest Range

https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/

Heap。和merge sort的merge算法类似，区别在于本题需要访问priority_queue的队尾元素，因此使用了map，
map基于红黑树实现，自动对key进行排序，而且可以通过迭代器随时访问头和尾。
保证队列中存有每个list中的最小的数，队列的队头和队尾之间的距离的最小值就是题目的解，每次更新结果后，
扔掉队头，并将队头所在的list中下一个元素添加到队列中。将map作为可以两端同时访问的priority_queue的想法真是要逆天了！

295: Find Median from Data Stream

https://leetcode.com/problems/find-median-from-data-stream/description/

Heap。
* 使用小根堆存大的那部分，用大根堆存储较小的部分
* 保持大根堆的 size >= 小根堆的 size

857: Minimum Cost to Hire K Workers

https://leetcode.com/contest/weekly-contest-90/problems/minimum-cost-to-hire-k-workers/

Heap。这是个非常好的题目！场景是给公司制定招人策略，给定一组候选人，
每个员工有两个参数：quality和期望最低wage。要求招K个人，招的人的wage按quality的比例给，
要求招人花费的钱最少。直观感受是对每个员工按`wage/quality`升序排序，
因为还钱最少，肯定要招性价比最高的员工。但是由于所有员工的实际按招的人的quality的比例给，
如果招了一个quality非常高，同时期望最低wage也很高的人，那这组解就不一定是最优解。于是我们可以得到总体的招人原则：
1. 招的人的`wage/quality`尽可能低（要求候选人对自己的认识足够清晰）
2. 招的人quality不能太高（招尽可能平庸的人！）

于是解法就比较清晰了，构建quality的大根堆q，
遍历按wage/quality升序排序后的候选人（包括wage和quality属性）列表，
每次将当前候选人插入q中，用sum记录当前q中候选人quality的总数，
当q中候选人的个数为K时，招这K个人要花的钱是sum * 当前候选人的`wage/quality`，
这是因为当前候选人的`wage/quality`一定是最大的。
当q的候选人数大于K(为K+1)时，先把quality最大的候选人出队列(不要他了，因为他太优秀了)，然后按前一种情况处理即可。

373: Find K Pairs with Smallest Sums

https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/

Heap。将 `nums1` 中的每个元素与 `nums2` 的组合视为一个有序链表，视为 `nums1` 长度个链表进行归并，选择小根堆，找出 top k 个。

692: Top K Frequent Words

https://leetcode.com/problems/top-k-frequent-words/description/

Heap。基于heap sort的方法解决。

264: Ugly Number II

https://leetcode.com/problems/ugly-number-ii/#/description

两种解法
Heap: 最小堆
DP: dp[i] = min(dp[p2] * 2, dp[p3] * 3, dp[p5] * 5)
