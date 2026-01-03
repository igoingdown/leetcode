#### 并查集专题

----

547: Friend Circles

<https://leetcode.com/problems/friend-circles/description/>

DFS，并查集。

----

721: Accounts Merge

<https://leetcode.com/problems/accounts-merge/description/>

DFS，并查集。

----

839: Similar String Groups

<https://leetcode.com/contest/weekly-contest-85/problems/similar-string-groups/>

并查集。并查集在逻辑上构造一个森林，先将每个节点都初始化为森林中的一棵树，group为N。
然后遍历所有的边，对于每一条边，如果两个节点所在树的根节点不同，
就将后一个节点所在的树的根节点作为前一个节点所在树的根节点的子节点，同时group减1。
这样就可以解决并查集的第一类题目，就是求group的数量。
另一种题目要求不仅分出group，并且要给出每个group具体有哪些节点，
这时候只需要遍历每个节点，找出其所在树的根节点，按根节点分离每个group即可。
547，839属于第一类，721属于第二类。

并查集的`find(x,parents)`函数用不用递归均可，
一个非常重要的点是在查询过程中进行优化，即在查询过程中增加森林中的树的宽度，
降低树的高度，提升后续的查询效率：
  * 递归方式的优化：参考recursion解法,找到一棵树的根节点后，
  即递归过程结束后，可以将当前节点的父节点直接设为递归结果，
  这样一来，凡是查询路径上的节点的根节点都设成了该树当前时刻的根节点
  * 非递归方式的优化：与递归方式类似，每次循环时，
  都将当前节点的父节点设置为父节点的父节点，即减少一层。

----
