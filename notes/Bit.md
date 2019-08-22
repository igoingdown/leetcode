#### 位操作专题

136: Single Number

<https://leetcode.com/problems/single-number/>

位操作。想象一个四四方方的多层公寓，每层有32（也可以更多）个房间，
每个房间住着0或者1，异或像如来神掌一样将每一位从上而下压缩。



137: Single Number II

<https://leetcode.com/problems/single-number-ii/description/>

位操作。每一位都有规律，仍然可以按照上题的思路思考，每一位上都是这样的规律。
![](http://latex.codecogs.com/gif.latex?{sum=x_1*3+x_2*3+...+x_{n-1}*3+y})
要得到y对sum模3即可。

260: Single Number III

<https://leetcode.com/problems/single-number-iii/description/>

位操作，按第一个不同的位将nums分为两派即可。思路同前两道题。

461: Hamming Distance

<https://leetcode.com/problems/hamming-distance/description/>

位操作，与和异或。

477: Total Hamming Distance

<https://leetcode.com/problems/total-hamming-distance/description/>

位操作，分两派，该位为0和该位为1，分别记录每派的count，相乘加到结果上即可。


201: Bitwise AND of Numbers Range

<https://leetcode.com/problems/bitwise-and-of-numbers-range/description/>

位操作


405: Convert a Number to Hexadecimal

<https://leetcode.com/problems/convert-a-number-to-hexadecimal/description/>

位操作，注意0的问题，算术右移和逻辑右移的区别。


421: Maximum XOR of Two Numbers in an Array

<https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/>

位操作，Math。

190: Reverse Bits

<https://leetcode.com/problems/reverse-bits/description/>

位操作。将一个32位无符号数的2进制表示reverse，利用进制，采用10进制的方式来做即可，低位的权重更高。


7: Reverse Integer

<https://leetcode.com/problems/reverse-integer/description/>

位操作，Math。和190相似，注意INT\_MAX、INT\_MIN和正负号，参考**atoi**。


476: Number Complement

<https://leetcode.com/problems/number-complement/description/>

位操作，求补码，从符号位开始0变为1，然后取反。


342: Power of Four

<https://leetcode.com/problems/power-of-four/description/>

位操作。

318: Maximum Product of Word Lengths

<https://leetcode.com/problems/maximum-product-of-word-lengths/description/>

位操作。

50: Pow(x, n)

https://leetcode.com/problems/powx-n/#/description

位操作。直接视为进制题型，指数视为二进制表示，每位的权重是前一位权重的平方。
末位的权重为x，从后向前依次遍历指数的每一位即可。注意先将负数转为整数，负指数转我正指数。


289: Game of Life

<https://leetcode.com/problems/game-of-life/>

Math，位操作。遍历每个cell，每个cell的状态由分为0和1，可以将右侧第一位视为本轮的状态，右侧第二位视为下一轮的状态。
由于0视为2位表示时是00，1视为2位表示时是01，这种表示不影响本轮的状态，而且可以在原地进行操作，更新下一轮的状态。
最后将所有cell的状态右移1位就瞬间变为下一轮的状态了。

----


