#### Leetcode Trie专题

720: Longest Word in Dictionary

<https://leetcode.com/problems/longest-word-in-dictionary/description/>

Trie+DFS或者Trie+BFS。

----

208: Implement Trie (Prefix Tree)

https://leetcode.com/problems/implement-trie-prefix-tree/description/

Trie。系统设计题，实现前缀树。注意要用`c - 'a'`而不是直接用`c`来索引后继节点！

----

14: Longest Common Prefix

<https://leetcode.com/problems/longest-common-prefix/description/>

Trie。

----

648: Replace Words

<https://leetcode.com/problems/replace-words/description/>

Trie。

----

211: Add and Search Word - Data structure design

<https://leetcode.com/problems/add-and-search-word-data-structure-design/description/>

Trie。注意查找的时候如果碰到`'.'`，需要使用DFS，把所有可能的路径均遍历结束后如果都没有找到正确结果，返回`false`。

----

677: Map Sum Pairs

<https://leetcode.com/problems/map-sum-pairs/description/>

Trie+BFS。

----

`microsoft_c#_trie.csharp`: 这是微软的trie的实现，非常经典，跟小爽看了老长时间才看明白！
要自己去试着转为C++版
