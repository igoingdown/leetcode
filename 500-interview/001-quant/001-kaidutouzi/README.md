1. 相关假设
    1. 数据块之间的数据不重叠
    2. seq_id >= 0
2. 思路
    * 使用 expected_seq_id 表示当前 buffer 预期接受到的最小 seq_id，低于该 seq_id 的数据直接抛弃。
    * 使用 ring buffer 存储接收到的字节数组，大小为 10KB，覆盖写入。
    * 使用 interval 链表存储字节块的分段信息，每次接收新字节块，执行段的 merge 或新增段。
    * 基于上述 ring buffer 和 interval 链表实现 data buffer，写操作 put 接口分为以下过程：
        * 将过期数据丢弃 (丢弃expected_seq_id 之前的数据)
        * 合法数据写入 ring buffer
        * 执行 interval 的 merge 或新增 interval
        * 更新 expected_seq_id
    * 读操作 get  接口分为以下几步：
        * 检查更新 expected_seq_id 和第一个 interval 的起始是否一致
        * 一致则返回第一个 interval 在 ring buffer 中的数据
        * 不一致则返回空
