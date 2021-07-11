#### 链表

2: Add Two Numbers

<https://leetcode.com/problems/add-two-numbers/description/>

链表尾插法。模拟实现硬件中的串行加法器，注意进位。

----

445: Add Two Numbers II

<https://leetcode.com/problems/add-two-numbers-ii/#/description>

链表。先反转链表，然后按第2题做。不允许反转链表可以先求二者长度，然后从后向前遍历。

----

24: Swap Nodes in Pairs

<https://leetcode.com/problems/swap-nodes-in-pairs/description/>

链表尾插法。一次走两步，注意使用`dummy_node`时，
如果原链表只有一个元素直接返回`dummy_node->next`是错误的，要对这种情况进行判别。

328: Odd Even Linked List

https://leetcode.com/problems/odd-even-linked-list/#/description

很简单的一道题，题意理解错误，正确理解题意后一次AC。



143: Reverse Linked List

链表头插法。



25: Reverse Nodes in k-Group

https://leetcode.com/problems/reverse-nodes-in-k-group/description/

链表分组反转，头插法。使用`pre`和`cur`分别记录当前组和下一组的头结点，设置dummy node作为结果链表的起始，
记录新链表的尾部，因为没插入一个新的组之后就要更新这个尾部，再进行头插法。


