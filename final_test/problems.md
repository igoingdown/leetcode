## 题目大意

1. Print a Christmas Tree

打印树

2. Flatten a linked list

将有多个分支的链表扁平化

3. Raindrops

类似interval聚合问题

4. Palindrome: Minimum Insertion

最少删掉串中的多少字母，使串可以由字典中的词拼成。与coin change那道题类似，这个题目使用DFS能做，但是要遍历整个解空间，在解空间较大的时候肯定要超时，时间复杂度为指数时间复杂度。BFS比DFS好些，可以想想BFS怎么实现，BFS在需要删除的字符较多时也要遍历解空间的很大一部分，也会导致超时。
