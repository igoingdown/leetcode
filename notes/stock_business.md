#### stock专题

121: Best Time to Buy and Sell Stock

<https://leetcode.com/problems/best-time-to-buy-and-sell-stock/>

DP。给定一段时间内一支股票每天的价格数组$P$，计算本金充足只允许一次买入和一次卖出的条件下能获得的最大收益。

可以这么思考：卖出操作可以在任意一天进行，而只能在卖出日之前买入。
遍历每天的股价$P_i$，尝试在这天卖出，记录历史(包括今天的)最低价$min\_price$作为买入价格，
计算出收益就是今天卖出的最大收益，全局最大收益就是每天的最大收益的最大值。

122: Best Time to Buy and Sell Stock II

<https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/>

贪心算法，DP。给定一段时间内一支股票每天的价格数组$P$，计算本金充足允许多次买入和一次卖出的条件下能获得的最大收益。

* 贪心算法：由于我们知道了股票最终的走势，在不限制交易次数，仅限制买入在卖出之前的话，
穷举所有可能的操作，我们可以获得这支股票的理论收益最大值，这个问题其实跟买入卖出操作关系不大。
在已知未来的情况下，我们可以根据未来发生的事情选择现在的行为，如果已知明天要涨，今天买然后明天卖掉就行，
每天都这么操作，见涨就执行买入和卖出交易各一次就可以获得理论上的收益最大值。

* DP：使用`buy`和`sell`数组分别记录**上一次执行的操作是买入或卖出得到的最大收益**，
初始化`sell[0] = 0`，`buy[0]=INT_MIN`，递推公式为：
`sell[i] = max(sell[i-1], buy[i-1] + prices[i])`
`buy[i] = max(buy[i-1], sell[i-1] - prices[i])`


123: Best Time to Buy and Sell Stock III

<https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/>

DP，AC自动机。同122，用`buy1,sell1,buy2,sell2`分别记录买1次，买2次，卖1次和卖2次的最大收益。
上述4个变量表示4种状态，这些状态呈链式连接关系，
如下图所示:![image](https://github.com/igoingdown/public-notes/blob/master/images/ac_auto_machine.png?raw=true)

`sell2 = max(sell2, buy2 + prices[i])`
`buy2 = max(buy2, sell1 - prices[i])`
`sell1 = max(sell1, buy1 + prices[i])`
`buy1 = max(buy1, - prices[i])`


188: Best Time to Buy and Sell Stock IV

<https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/>

greedy，DP，AC自动机。本题实际上是122和123的合体。

* 当限制交易的次数`k`$\in$`[0, prices.size() / 2)`时：用123中的AC自动机解法可解决，
区别是这里的状态转移链更长，共计`2*k`个状态，其中`buy`和`sell`分别占`k`个。
* 当`k >= prices.size()/2`时：这个题退化到122，用贪心算法直接计算最大收益即可。


714: Best Time to Buy and Sell Stock with Transaction Fee

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

一刷使用自己设计的贪心算法：先买，涨了就卖，这样是不对的！[1,3,7,5,10,3]这个case就不对。
二刷使用s0和s1分别记录两种状态，这是有限状态自动机的概念，
s0是手里没有股票的收益，s1是手里有一支股票的收益，在两个状态之间切换，和309很像。

309: Best Time to Buy and Sell Stock with Cooldown

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

DP。使用基于有限状态机的DP，时间复杂度和空间复杂度均为$O(N)$。
`s0,s1,s2`三个状态分别表示最后一个操作为`rest`, `buy`, `sell`的当天`max_profit`。
