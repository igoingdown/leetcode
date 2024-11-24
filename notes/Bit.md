#### 位操作专题

136: Single Number

[https://leetcode.com/problems/single-number/](https://leetcode.com/problems/single-number/)

位操作。想象一个四四方方的多层公寓，每层有32（也可以更多）个房间，
每个房间住着0或者1，异或像如来神掌一样将每一位从上而下压缩。


137: Single Number II

[https://leetcode.com/problems/single-number-ii/description/](https://leetcode.com/problems/single-number-ii/description/)

位操作。每一位都有规律，仍然可以按照上题的思路思考，每一位上都是这样的规律。
![](http://latex.codecogs.com/gif.latex?{sum=x_1*3+x_2*3+...+x_{n-1}*3+y})
要得到y对sum模3即可，本方法适合2n+1（136）, 3n+1（137），4n+1 等情况。

260: Single Number III

[https://leetcode.com/problems/single-number-iii/description/](https://leetcode.com/problems/single-number-iii/description/)

位操作，按第一个不同的位将nums分为两类即可。思路同前两道题。

461: Hamming Distance

[https://leetcode.com/problems/hamming-distance/description/](https://leetcode.com/problems/hamming-distance/description/)

位操作，与和异或。

477: Total Hamming Distance

[https://leetcode.com/problems/total-hamming-distance/description/](https://leetcode.com/problems/total-hamming-distance/description/)

位操作，分两派，该位为0和该位为1，分别记录每派的count，相乘加到结果上即可。

201: Bitwise AND of Numbers Range

[https://leetcode.com/problems/bitwise-and-of-numbers-range/description/](https://leetcode.com/problems/bitwise-and-of-numbers-range/description/)

暴力法：遍历并进行与操作，时间复杂度O(n)。
位操作：取 m 和 n 的公共前缀，公共前缀后面补 0 就是答案。
公共前缀后面的部分 每一位在连续数字序列中一定有 0 ，只要有 0 这一位所有数与的结果一定为 0 ，
这一点可以用反证法证明，假设公共前缀后某一位没有 0，取公共前缀不变其他位均为 0 的数
这个数一定在序列中，与假设的数的连续数字序列中没有 0 矛盾。

405: Convert a Number to Hexadecimal

[https://leetcode.com/problems/convert-a-number-to-hexadecimal/description/](https://leetcode.com/problems/convert-a-number-to-hexadecimal/description/)

位操作，先把负数转为无符号数，0 提前处理掉，一个小技巧是将数字到字母的映射通过字符串表示（简化版 map）。

421: Maximum XOR of Two Numbers in an Array

[https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/)

位操作，构建 trie，树的节点有 2 个子节点；每个根节点到叶子节点表示数组中的数，数字的每一位
为 0 或 1，分别对应 trie 的第 0或 1 个子节点。完成构建后，对于每个数；从最高位找出与该数异或的最大值。

190: Reverse Bits

[https://leetcode.com/problems/reverse-bits/description/](https://leetcode.com/problems/reverse-bits/description/)

位操作。将一个32位无符号数的2进制表示reverse，利用进制，采用10进制的方式来做即可，低位的权重更高。

7: Reverse Integer

[https://leetcode.com/problems/reverse-integer/description/](https://leetcode.com/problems/reverse-integer/description/)

位操作，Math。和190相似，注意INT\_MAX、INT\_MIN和正负号，参考**atoi**。

476: Number Complement

[https://leetcode.com/problems/number-complement/description/](https://leetcode.com/problems/number-complement/description/)

位操作，求补码，高位连续的 0 全换成 1，其他位不变，最后整体取反。

342: Power of Four

[https://leetcode.com/problems/power-of-four/description/](https://leetcode.com/problems/power-of-four/description/)

位操作。4 的幂次二进制表示中只有一个 1（n&(n-1)==0）且在奇数位上，且均 > 0

318: Maximum Product of Word Lengths

[https://leetcode.com/problems/maximum-product-of-word-lengths/description/](https://leetcode.com/problems/maximum-product-of-word-lengths/description/)

位操作。将单词按字母的出现情况映射为一个二进制数，二进制位为 1 表示该字母出现过，二进制位为 0 表示该字母没有出现过。
然后遍历所有的单词对，判断两个单词的二进制数按位与是否为 0，为 0 表示没有相同的字母，计算长度乘积并更新最大值。

50: Pow(x, n)

https://leetcode.com/problems/powx-n/#/description

位操作。可视为进制题型，指数视为二进制表示，每位的权重是前一位权重的平方。
末位的权重为x，从后向前依次遍历指数的每一位即可。注意先将负指数转为正指数。
解法为快速幂法：n 为奇数时，res *= x；n 为偶数时，x *= x。

289: Game of Life

[https://leetcode.com/problems/game-of-life/](https://leetcode.com/problems/game-of-life/)

Math，位操作。遍历每个cell，每个cell的状态由分为0和1，可以将右侧第一位视为本轮的状态，右侧第二位视为下一轮的状态。
由于0视为2位表示时是00，1视为2位表示时是01，这种表示不影响本轮的状态，而且可以在原地进行操作，更新下一轮的状态。
最后将所有cell的状态右移1位就瞬间变为下一轮的状态了。

---
