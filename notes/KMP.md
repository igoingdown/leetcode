#### KMP专题

-------

28: Implement strStr()

https://leetcode.com/problems/implement-strstr/description/

暴力匹配和KMP算法。KMP算法分两步：
1. 求解`next`数组。`next`数组全部初始化为-1;`i,j`初始化为0和-1，
然后对`next`数组对应的`needle`字符串自身进行模式匹配。
1. 模式匹配。`i,j`均初始化为0，然后对`haystack`和`needle`进行模式匹配。

模式匹配代码模板：
```c++
if (j == -1 || s1[i] == s2[j]) { //上述模式匹配步骤中，s1即haystack, s2即needle；
							    	//求解next数组步骤中，s1和s2均为needle
	i++;
	j++;
	// next[i] = j; // 求解next数组需要修改next数组
} else j = next[j];
```

-------

30: Substring with Concatenation of All Words

<https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/>

两种方法KMP和TP，只有TP能AC。

* KMP：使用KMP得到每个关键字在母串中出现的所有位置，然后使用DFS得到解，这种方式超时。
* TP：使用`map`记录每个模式串及对应的频率，两层循环，外循环遍历母串中可以作为拼接串起始位置的
index ![](http://latex.codecogs.com/gif.latex?{i\in[0,ss-ws*l}) 内循环进行匹配，
每次匹配都从母串中取出长为`l`的子串，
看是否在`map`中，在`map`中则修改`map`，直到`map`为空，这时产生了一个答案。此时继续外循环即可。

-------
