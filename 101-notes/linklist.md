#### 链表

2: Add Two Numbers

<https://leetcode.com/problems/add-two-numbers/description/>

链表：尾插法。

----

445: Add Two Numbers II

<https://leetcode.com/problems/add-two-numbers-ii/#/description>

链表。先反转链表，然后按第2题做。不允许反转链表可以先求二者长度，然后从后向前遍历。

----

24: Swap Nodes in Pairs

<https://leetcode.com/problems/swap-nodes-in-pairs/description/>

链表：尾插法，dummy node 全局不动使用 tmp 遍历链表，每次走 2步。需要调整节点顺序搞4个变量 abcd 分别表示链表的 4 个节点，依次调整其next 指针即可，逻辑更清晰。

328: Odd Even Linked List

https://leetcode.com/problems/odd-even-linked-list/#/description

很简单的一道题，题意理解错误，正确理解题意后一次AC。



143: Reverse Linked List

链表头插法。



25: Reverse Nodes in k-Group

https://leetcode.com/problems/reverse-nodes-in-k-group/description/

链表分组反转，头插法。使用`pre`和`cur`分别记录当前组和下一组的头结点，设置dummy node作为结果链表的起始，
记录新链表的尾部，因为没插入一个新的组之后就要更新这个尾部，再进行头插法。


