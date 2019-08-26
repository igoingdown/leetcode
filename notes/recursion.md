#### 递归

114: Flatten Binary Tree to Linked List

<https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/>

递归，将左右分别flattern之后，将左侧链接到右侧。

108: Convert Sorted Array to Binary Search Tree

<https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/>

递归，BS。


761: Special Binary String

<https://leetcode.com/problems/special-binary-string/description/>

* BFS:每次选字符串中两个special binary substring交换，如果结果没有访问过就将其放入队列中，
这种解法是我自己的解法，有大量重复计算，超时。
* 递归：根据题意可以将special binary string类比为valid parenthesis，其中`1`类比为`(`，`0`类比为`)`，
字母顺序更大可以类比为我们倾向与将**更深**的valid parenthesis排在前面。
于是很容易想到递归算法，递归函数`f`的函数体：
	* 将valid parenthes分成多个连续的valid sub-parenthesis
	* 对每个valid sub-parenthesis除去最外层的`()`的部分调用递归函数`f`，得到相应的字母顺序最**大**的valid sub-parenthesis
	* 将上一步得到的结果按**更深的valid sub-parenthesis排在更前面**的规则排序并将排序后的子串拼接起来返回即可。
* 不管是`0,1`，还是`()`都是一种逻辑的代号，`0,1`不如`()`直观，
详情可以参考[这篇解释](https://leetcode.com/problems/special-binary-string/discuss/155621/Logical-Thinking-with-Clear-Code)。


94: Binary Tree Inorder Traversal

https://leetcode.com/problems/binary-tree-inorder-traversal/#/description

二叉树的前、中、后遍历的递归和非递归算法都要很熟悉。


372: Super Pow

https://leetcode.com/problems/super-pow/#/description

递归。


385: Mini Parser

https://leetcode.com/problems/mini-parser/#/description

递归。用到istringstream，不好理解！子函数对流修改后，父函数要clear()才能得到正确的指针！
不太理解递归。


671: Second Minimum Node In a Binary Tree

https://leetcode.com/contest/leetcode-weekly-contest-48/problems/second-minimum-node-in-a-binary-tree/

递归。


669: Trim a Binary Search Tree

https://leetcode.com/contest/leetcode-weekly-contest-48/problems/trim-a-binary-search-tree/

递归。自己总是把问题忘难了想。


222: Count Complete Tree Nodes

https://leetcode.com/problems/count-complete-tree-nodes/description/

递归。

很快有思路，但是折腾了2小时，遇到各种错误，而且算法效率非常低！
通过这道题更深的理解了二分查找算法。判断条件是更新high还是low只跟mid的计算方式有关，
无论什么时候，区间一定要包含答案，这是原则！
按照我的书写习惯，low不会比high大，终止情况是low = high = mid！

简单的递归竟然在效率上打败了50%的算法！




230: Kth Smallest Element in a BST

https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

一刷计算比mid值小的节点个数时逻辑出错，得了WA，再刷！用VS在本地debug就是方便，
终于不用自己写很多cout了，而且快了很多！算法效率不高，follow up没看，
后面再刷要注意这两个问题！二刷使用非递归的基于树的中序遍历的方法一次AC，
效率高出很多，再刷一次，深入理解BST的中序遍历过程，尤其是非递归方法。


105: Construct Binary Tree from Preorder and Inorder Traversal

<https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/>

递归。


106: Construct Binary Tree from Inorder and Postorder Traversal

<https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/>

递归。同105，由于树中无重复元素，可以用map记录inorder中元素到index的映射，
这样就不用在生成树时遍历inorder查找元素了，这样可以把时间复杂度降为$O(N^2)$。


856: Score of Parentheses

https://leetcode.com/contest/weekly-contest-90/problems/score-of-parentheses/

递归。按指定规则计算括号对的分数，递归思路比较容易，用栈找第一个左括号与最左侧匹配的右括号，
将原括号组分为左右两部分，并对两个子问题进行递归处理。


394: Decode String

https://leetcode.com/problems/decode-string/description/

一刷使用自己的算法WA。二刷使用大神的算法AC，
使用两个stack分别存放“[x]”出现时之前的num和应该加到num * "[x]"之前的string，
每个元素只表示一层，跟上层无关。思路理解了，但是还不熟，再刷。
三刷使用递归算法，运行时间少于非递归算法。


100: Same Tree

https://leetcode.com/problems/same-tree/description/

递归。


230: Kth Smallest Element in a BST

https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

基于非递归中序遍历二叉树的方法。


144: Binary Tree Preorder Traversal

https://leetcode.com/problems/binary-tree-preorder-traversal/description/

二叉树先序遍历，
* 递归
* 非递归: 注意入栈的时先对右子树入栈，再对左子树入栈，从而保证左子树优先访问。


200: Number of Islands

https://leetcode.com/problems/number-of-islands/description/

递归。效率不高。

297: Serialize and Deserialize Binary Tree

https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

递归。就是先用先序遍历生成字符串，再按先序遍历顺序还原二叉树。


99: Recover Binary Search Tree


https://leetcode.com/problems/recover-binary-search-tree/description/

递归。BST的中序遍历结果必定是单调递增的，错误发生时，
一定两次出现前一个节点的`val`比后一个节点的`val`大的情况。
第一次出现时，出错的是较大的那个；第二次出现时，出错的是较小的那个。
用`first`,`second`,`pre`分别记录出错的两个节点和中序遍历过程中上一次访问的节点，
遍历完之后调换`first`和`second`节点的`val`即可。**注意二重指针的使用**。


87: Scramble String

https://leetcode.com/problems/scramble-string/description/

一刷递归TLE，没有先sort判断字符串是否相同减少递归深度。
二刷使用sort之后AC，
四刷使用DP，思路和递归差别不大。
使用if进行短路优化时间比不用短路优化还要长，猜是因为if破坏了流水线结构。


617: Merge Two Binary Trees

https://leetcode.com/problems/merge-two-binary-trees/description/

递归


239: Sliding Window Maximum

https://leetcode.com/problems/sliding-window-maximum/description/

一刷使用java优先级队列（因为c++中的优先级队列没有remove接口）没有判空CE，时间复杂度为O(NlogK)，
时间复杂度不够好，最好的算法是递归。


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


687:  Longest Univalue Path

https://leetcode.com/problems/longest-univalue-path/description/

双递归。


654: Maximum Binary Tree

https://leetcode.com/problems/maximum-binary-tree/description/

树的递归。


101: Symmetric Tree

<https://leetcode.com/problems/symmetric-tree/description/>

递归。对左右子树判断对称性。


145: Binary Tree Postorder Traversal

https://leetcode.com/problems/binary-tree-postorder-traversal/description/

二叉树后续遍历递归与非递归实现。多做是有用的，非常有用，做这个题的时候深有体会！

872: Leaf-Similar Trees

<https://leetcode.com/contest/weekly-contest-94/problems/leaf-similar-trees/>

递归。定义如果两棵树的叶子节点按从左到右的顺序访问，得到结果列表相同，则两棵树相似。给定两棵树，判断两棵树是否相似。

中序递归遍历两棵树，记录叶子节点的访问列表，判断访问列表是否完全相同即可。


653: Two Sum IV - Input is a BST

https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

递归，BST查找。


337: House Robber III

https://leetcode.com/problems/house-robber-iii/description/

递归，有点0-1背包的意思。



450: Delete Node in a BST

https://leetcode.com/problems/delete-node-in-a-bst/description/

递归好题！删除BST中的节点，上课讲过，自己做还是废了不少时间。递归删除节点，找到节点后分情况讨论，
找左子树的最大值或者右子树的最小值作为新的根的值，并删除原节点，
findAndDelete函数要注意删除节点不能直接将父节点的右子树设为NULL，要设为删除节点的左子树！


297: Serialize and Deserialize Binary Tree

https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

递归。树的序列化与反序列化，非常经典！先序遍历的递归。


449: Serialize and Deserialize BST

https://leetcode.com/problems/serialize-and-deserialize-bst/description/

递归。BST的序列化与反序列化，和上题使用完全相同的思路AC，应该可以结合BST的特征进行简化！


652: Find Duplicate Subtrees

https://leetcode.com/problems/find-duplicate-subtrees/description/

利用树的遍历先进行序列化，在序列化过程中将序列化结果和根节点对应起来，
注意树的序列化结果要有唯一性，必须加入额外信息：如两侧加括号。


530: Minimum Absolute Difference in BST

https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/

递归。


404: Sum of Left Leaves

<https://leetcode.com/problems/sum-of-left-leaves/>

* 递归:只要想明白一个节点的情况，其他节点都一样。如果节点为空，返回0；
如果左子为叶子节点，返回左子的值+右子树的递归结果；其余情况分别对左右子树进行递归并把结果求和即可。
* 非递归。利用栈，处理栈顶元素的时候直接处理栈顶元素，应该处理栈顶元素的左右结点。


