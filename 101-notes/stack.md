#### 栈专题

20: Valid Parentheses

https://leetcode.com/problems/valid-parentheses/description/

stack。判断各种括号的组合是否合法，用栈。遍历字符串，遇左括号入栈，
遇右括号如果栈顶为对应的左括号则出栈，否则该括号串非法。遍历结束如果栈空则合法，否则非法。


71: Simplify Path

<https://leetcode.com/problems/simplify-path/#/description>

stack。用`vector`代替`stack`更简单，`stringstream`要用熟，
`getline(in_stream, buffer, char)`的第三个参数表示分隔符。最后结果中多出来的一个`"/"`要去掉。


844: Backspace String Compare

<https://leetcode.com/contest/weekly-contest-87/problems/backspace-string-compare/>

stack。使用将string转为stack，遇到'#'且栈非空则删除栈顶元素，否则将字符压入栈中。


496: Next Greater Element I

https://leetcode.com/problems/next-greater-element-i/description/

栈。还需深入理解。



503: Next Greater Element II

https://leetcode.com/problems/next-greater-element-ii/description/

栈。stack和map都要保存index，和上题的区别在于要进行两次遍历，算法效率还可以继续提升。时间和空间复杂度为O(N)。


158: Min Stack

hulu面试题。使用s,min两个栈实现，min记录串数加入s之后之后的最小值，

栈。只有最小值变化或者连续添加最小值才入min栈，出栈时只有s和min的top相同才出栈。


150: Evaluate Reverse Polish Notation

https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

栈。注意先出栈的第二个操作数，后出栈的是第一个操作数。


42: Trapping Rain Water

<https://leetcode.com/problems/trapping-rain-water/description/>

单调递减栈。

栈中存放的是可以作为当前水槽的左边界或底板的数的index，如果后面出现了较大数，
则新的数可以作为水槽的右边界。对于要出栈的情况，即出现右边界时，
如果栈中有两个及以上的元素，则当前栈顶可以作为水槽底板，
底板出栈后的那个栈顶就是左边界，当前水槽可以容纳的水就是`(min(left_bound, right_bound) - bottom) * width`。


739: Daily Temperatures

<https://leetcode.com/contest/weekly-contest-61/problems/daily-temperatures/>

单调递减栈。

类似42，栈中存放的是可能有更高温度出现的日期的index。


246: Sliding Window Maximum

https://leetcode.com/problems/sliding-window-maximum/description/

queue，单调递减双端队列或堆。

* 使用deque: 类似42，维护一个单调递减栈（存索引）可以知道一定范围的数组的最大值，而且最大值就是栈的最底端的元素。
由于需要取出窗口中的最大值（即需要访问栈的最底端元素），另外当窗口滑过当前最大值所在的位置时，
需要将最大值删除（删除栈的最底端元素），综合以上需求，双端队列是最理想的数据结构！
* 使用优先级队列: 直接存索引，按照数字大小构建大根堆即可。注意c++实现优先级队列不好写，需要构造一个带参数的函数类。


225: Implement Stack using Queues

https://leetcode.com/problems/implement-stack-using-queues/submissions/1

queue。`pop`函数和普通的`stack`的`pop`不同，要返回栈顶元素。

84: Largest Rectangle in Histogram

<https://leetcode.com/problems/largest-rectangle-in-histogram/description/>

单调递增栈。

栈中存储的是可能作为矩形的高使矩形可以向右延伸的数的index。在需要出栈的情况下，
* 如果栈中元素个数大于1: 矩形的高为`arr[s.top()]`，矩形的长是`(i - 出栈后的栈顶 + 1)`。
* 如果栈中元素个数为1：当前栈顶为全局洼地！矩形高为`arr[s.top()]`，长为`arr.size()`。

735: Asteroid Collision

<https://leetcode.com/contest/weekly-contest-60/problems/asteroid-collision/>

栈。注意分类！


