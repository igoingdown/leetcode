#### math专题

31: Next Permutation

https://leetcode.com/problems/next-permutation/?tab=Description

math。先从后将降序序列反转，然后找被反转序列的前一个数字在反转序列中的上界与该数字替换。


41: First Missing Positive

<https://leetcode.com/problems/first-missing-positive/description/>

math，鸽巢原理，第一个missing的正整数的范围一定是$[1, array.size() + 1]$。类似小米实习面试题。

遍历数组中的每个坑，向坑中填入应该填入的数，规则是:第$i$个坑中填入的数为$i+1$，即$nums[i-1]=i$，对于每个坑$i$，只要不满足以下3个条件：
* $nums[i] \leq n$ `&&` $nums[i] > 0$
* $nums[i] - 1 \neq i$
* $nums[i] \neq nums[nums[i] - 1]$（防止因为有重复的数而导致死循环）

就执行`swap(nums[i], nums[nums[i] - 1])`将$nums[i]$装入到应该出现的位置(第$nums[i]-1$个坑)，
此时第$i$个坑出现了一个新的数，重复以上步骤直到以上条件不满足或者第$i$个坑中填入了正确的数。


60: Permutation Sequence

<https://leetcode.com/problems/permutation-sequence/#/description>

Math。$N$个数字的所有排列方式为$N!$种，在由前到后确定每一位上的数字的过程中，单位不同，根据单位和当前剩余的`k`决定填充哪个数字，并用`set`记录已经使用过的数字。


43: Multiply Strings

https://leetcode.com/problems/multiply-strings/#/description

math。大数乘法，给定两个大数$a,b$(字符串表示)，求$c=a*b$。

设$a,b$的长度为别为$n_1,n_2$，则$c$的长度最大为$n_1+n_2$。由低位到高位计算$c$的任意一位$c_k$，对于每一个满足`i+j == k`的有序对`{i,j}`计算$p_{ij}=a_i * b_j$并求和，加上计算$c_{k-1}$产生的进位$carrier_k$对10取模即可，即$c_k=(\sum_{i=0}^{k}{a_i * b_{k-i}} + carrier_k) \% 10$, 且$carrier_{k+1}=(\sum_{i=0}^{k}{a_i * b_{k-i}} + carrier_k) / 10$。初始化$c$长度为$n_1+n_2$的全零字符串，计算结束之后将高位的0抹去，当结果为0要补个0。


448: Find All Numbers Disappeared in an Array

<https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/>

Math。在原数组上进行改动，对于数组`A`中的任意元素`A[i]`。将`A[A[i]]`标记为负数之后遍历按下标遍历`A`
如果`A[i]`为正，则`i`没出现过。 


442: Find All Duplicates in an Array

<https://leetcode.com/problems/find-all-duplicates-in-an-array/>

同448。区别在于遇到重复值时直接就加入结果列表即可。


268: Missing Number

<https://leetcode.com/problems/missing-number/>

Math。求和再做减法最方便，为了防止溢出需要用范围更大的数据结构。


229: Majority Element II

<https://leetcode.com/problems/majority-element-ii/>

Math。数组中最多有两个数`n1,n2`的频数`>n/3`。

BM多数投票算法（Boyer-Moore Majority Vote algorithm）。将n1，n2初始化为任意两个不同的数就行，
对应counter1和counter2初始化为0。还要注意一点第一次遍历结束只是明确了n1，n2是出现频率最高的数，
但是对应的counter是不准的，需要重新计数后再查看counter是否满足条件。


240: Search a 2D Matrix II

<https://leetcode.com/problems/search-a-2d-matrix-ii/description/>

math，BS的变形，所选的哨兵为角上的元素，每次将范围缩减一行或一列，$O(\max(M,N))$。暴力方法是对每一行进行BS，$O(MlogN)$。


54: Spiral Matrix

<https://leetcode.com/problems/spiral-matrix/?tab=Description>

math。内循环每次从$(i,i)$开始，向右走到$(i, n - i - 1)$, 
再向下走到$(m - i - 1, n - i - 1)$，再向左走到$(m - i - 1, i)$, 
最后向上走到$(i + 1, i)$。注意去重，即后遍历一圈的过程中，
前后两次沿相反的方向遍历的不能是同一行或者同一列！

59: Spiral Matrix II

<https://leetcode.com/problems/spiral-matrix-ii/?tab=Description>

同54。

835: Image Overlap

<https://leetcode.com/contest/weekly-contest-84/problems/image-overlap/>

math。空间考察，两个大小一样的方阵A，B重叠，有四种可能的情况，
固定A，B可以与A重叠左上角，左下角，右上角，右下角。
遍历A的格，作为重叠的部分在A内的一角，遍历B的每个格，
根据重叠部分在A的方位（四个，所以有四种情况），
计算重叠的格在A中对应的行和列，判断两者的值并分别计数。

858: Mirror Reflection

https://leetcode.com/contest/weekly-contest-90/problems/mirror-reflection/

math。全镜面正方形二维房间，一束光从一角照进来，控制入射角度（q控制）和房间的长度（p），
观察这束光第一次照到角上会最先照到另外三个角的哪一个。
这是一个非常好的初中物理题。其实只要沿一个方向（上方）按光的反射定律无限延伸即可，
如果想到最简单的照到其它三个角的方式，后面就容易了。
于是问题变为一个数学问题，一个点每次向上跑q，看什么时候能达到$n * q % p == 0$的条件，根据n来判断是哪个角。

867: Prime Palindrome

https://leetcode.com/contest/weekly-contest-92/problems/prime-palindrome/

math。给定整数N，找出一个回文质数`p`，要求`p`是满足`p >= N`的第一个回文质数。 
由于题目条件`N < `$10^8$而且`N`为`int`型，因此可以遍历$i \in [0, 10000]$，
作为回文数的左侧部分，然后通过`mirror`函数，将右侧补全。
补全的过程中可以在左右两部分的中间添加一位数字$j \in [-1, 9]$($j=-1$表示不添加)。
如果`mirror`函数的结果`p`满足$p >= N$且`p`是回文数，则答案正确。

上面的解法有个小trick，仔细分析`mirror`函数的遍历过程会发现，
每次遍历的时候都是先产生一个$2k$位的整数，然后再产生10个$2k+1$位的整数，
这就产生了一个问题:为什么先遍历大的整数，再遍历小的整数结果却不会出错？
其实这是因为符合模式为`xx`(`x`表示一个整数)的质数只有11一个，这个结论需要证明！

48: Rotate Image

<https://leetcode.com/problems/rotate-image/?tab=Description>

math。矩阵顺时针旋转，先将矩阵进行上下翻转(上换到下)，然后对角互换(左下换到右上)，
于是左上就换到了右上，左下换到了左上，右上换到了右下，右下换到了左下，实现了顺时针旋转90度。
也可以先进行左右翻转，然后将左上和右下互换，由于左上与右下互换不如左下与右上来的简单，
因此第一种方案更好一点。对于逆时针旋转先上下翻转，然后左上与右下互换。

66: Plus One

<https://leetcode.com/problems/plus-one/description/>

math。初始化令最低位进位c=1,可以按照统一的模式解决。

29: Divide Two Integers

https://leetcode.com/problems/divide-two-integers/#/description

Bit，math。给定32位整数$a,b$的除法，求$a/b$，要求不能用乘法运算。

视为求商的二进制表示。每次循环寻找除$a$商大于0的最大的$b*2^i$，减掉这部分。重复上述步骤直到$a<b$。时间复杂度$O(\log{N})$。

89: Gray Code

https://leetcode.com/problems/gray-code/description/

Math。从0开始，不断从起始位或者终止位补0和1(从起始位补的话不必补0，更简洁)，当时从终止位补0或1出错，不知道为啥。

134: Gas Station

https://leetcode.com/problems/gas-station/description/

math。在一个单向成环的道路(类比单链表成一个完整环)上有$N$个加油站，
对于每个加油站$G_i$，有两个重要参数:分别是加油站储油量$g_i$和从第$i$个加油站到第$i+1$个加油站需要消耗的油量$c_i$，
给定一辆油箱无限大的卡车，问从哪个加油站出发可以绕环路一圈回到起点。

定义$l_i = g_i - c_i$，遍历每个加油站$G_i$(尝试以$G_i$为起点)，如果$G_i$可以成为起点则返回$i$，
如果$G_i$不能成为起点，即从$G_i$出发最远只能到达$G_j$，
则$[G_i, G_{i+1}, \cdots ,G_j]$中任意一个加油站都不能成为起点，这是因为：

1. 对于$[G_i, G_{i+1}, \cdots ,G_j]$的任意一个加油站$G_k$，有$\sum_{k=i}^j l_k < 0$和$\sum_{x=i}^k l_x \geq 0$
2. 根据**1**，有$l_j < 0$，$\sum_{k=i}^{j-1} l_k \geq 0$和$|l[j]|> \sum_{k=i}^{j-1} l_k$
3. 故$\sum_{x=k}^{j-1} l_x < \sum_{x=i}^{j-1} l_x$
4. 于是$\sum_{x=k}^j l_x<0$，即从$G_k$不可能到达$G_j$。

重复以上过程直到遍历结束，如果$\sum_{i=1}^N l_i >= 0$，则一定有解，且最后一次选中的作为起点的$G_i$就是一个解。

382: Linked List Random Node

https://leetcode.com/problems/linked-list-random-node/description/

概率，math。for循环每次以1/k概率将原值覆盖，$(1-1/k)$的概率保留原值。当链表中的数字为：{1， 2， 3， 4}时,概率分布如下：
$$P(res = 1) = 1 * 1/2 * 2/3 * 3/4$$
$$P(res = 2) =     1/2 * 2/3 * 3/4$$
$$P(res = 3) =           1/3 * 3/4$$
$$P(res = 4) =                 1/4$$


398: Random Pick Index

https://leetcode.com/problems/random-pick-index/description/

同上一题，O(N)。

453: Minimum Moves to Equal Array Elements

<https://leetcode.com/problems/minimum-moves-to-equal-array-elements/>

Math。给定长度为`n`的数组`A`，定义`A`上的一个元操作：**将数组中的`n-1`个元素加1**，最少经过多少次元操作可以使数组中元素都相等?
**将数组中的`n-1`个元素加1**等价于**数组中不加1的那个元素减去1，然后数组中的所有元素都加1**。
将所有的元素都加1并不能改变原数组中的数之间的差值，于是本题就转化为求**最少的减1操作**。
而要使数组中的元素全部相等，又要使用减法，那么最少的次数就是让这些元素全部都等于数组中最小的数。
于是有 ![](http://latex.codecogs.com/gif.latex?{answer=\\sum_{i=1}^{n}A_i-min(S)\*n})。

[【这里有详细解释】](https://leetcode.com/problems/minimum-moves-to-equal-array-elements/discuss/311290/Easy-Java-solution-with-explanation)。

621: Task Scheduler

https://leetcode.com/problems/task-scheduler/description/

Math。找出最频繁的字母，按公式给出结果。公式是：循环体size * 循环次数(频繁字母频率-1) + 剩余的频繁字母个数。
公式有特例如3个A，3个B，3个C，1个D，n=2时就不对，此时res=tasks.size()。


738: Monotone Increasing Digits

https://leetcode.com/contest/weekly-contest-61/problems/monotone-increasing-digits/

Math，没认真想，思路不好，不要怕开空间！


441: Arranging Coins

https://leetcode.com/problems/arranging-coins/#/description

Math。就是个一元二次方程求解的问题，我忘记用公式了。
用了个O(logN)的方法，用公式一次一次开方就OK了。一次AC。


343: Integer Break

https://leetcode.com/problems/integer-break/#/description

Math。需要用导数来推导，果然是数学题！


319: Bulb Switcher

https://leetcode.com/problems/bulb-switcher/#/description

Math。发现了一部分规律，但是没有继续深入，发现的规律还比较浅层。一刷一次AC。


672: Bulb Switcher II

https://leetcode.com/contest/leetcode-weekly-contest-48/problems/bulb-switcher-ii/

Math。没有发现规律，需要再理解一下！


