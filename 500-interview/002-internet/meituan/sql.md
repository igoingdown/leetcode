这是一个**非常典型、含金量很高的 MySQL 面试题**。
面试官并不是在考 SQL 语法，而是在考你对 **索引、排序、分页、执行计划** 的理解。

我会按「**题意 → 问题 → 原因 → 优化方案 → 最优 SQL**」的结构来讲，基本可以 **一锤定音**。

---

## 一、题意拆解（面试官真正想问什么）

```sql
select * 
from xxx 
where yyy = 1 
  and id > 1000 
order by id asc 
limit 100
```

### 表面看

> 查询 yyy=1 且 id > 1000 的记录，按 id 升序取前 100 条

### 实际考察点

1. **是否存在索引失效 / 排序代价**
2. **是否存在“深分页 / 回表问题”**
3. **是否能意识到 `select *` 的风险**
4. **是否理解 B+Tree 顺序扫描**

---

## 二、这条 SQL 的核心问题（直接给结论）

> ❌ **这条 SQL 在大数据量下是「性能不稳定 / 不可控」的**

### 主要问题有 4 个

---

## 三、问题 1：`select *` 导致大量回表

### 为什么是问题？

即使有联合索引：

```sql
(yyy, id)
```

执行过程仍然是：

1. 走索引过滤 `yyy=1 and id>1000`
2. 找到 100 条 id
3. **回表取所有列（`select *`）**

📌 如果：

* 表很宽（几十个字段）
* 数据在磁盘上

👉 **回表 IO 非常昂贵**

---

### 面试官期望你说出的话

> `select *` 会破坏覆盖索引，增加随机 IO，
> 在高并发场景下非常危险。

---

## 四、问题 2：ORDER BY + LIMIT 依赖索引顺序

### 如果没有合适索引，会发生什么？

假设只有索引：

```sql
idx_yyy(yyy)
```

那么执行路径是：

1. 根据 yyy=1 扫描大量行
2. **filesort 排序 id**
3. 再取 limit 100

❌ **这在大表上是灾难**

---

### 正确索引应该是

```sql
create index idx_yyy_id on xxx(yyy, id);
```

这样：

* where 使用索引
* order by 使用索引
* limit 可以“走到即停”

---

## 五、问题 3：`id > 1000` 本质是“游标分页”，但写法不完整

这一点是 **高级面试点**。

### 当前 SQL 看起来像“游标分页”：

```sql
id > 1000
```

但实际上：

* 没有保证 **上一页的最后一个 id**
* 容易出现：

  * 数据插入导致跳页
  * 分页不稳定

---

### 正确的“游标分页”写法

```sql
where yyy = 1
  and id > :last_id
order by id asc
limit 100
```

并且：

* `last_id` 必须来自上一页最后一条记录

---

## 六、问题 4：`select * + limit` 在大表下的不可预测性

### 面试官担心的是：

* 数据增长后
* 查询从 **毫秒 → 秒级**
* 无法通过简单加机器解决

---

## 七、完整优化思路（面试高分答案）

### ① 建立正确索引

```sql
create index idx_yyy_id on xxx(yyy, id);
```

---

### ② 改写 SQL（覆盖索引 + 延迟回表）

#### 第一步：只查主键

```sql
select id
from xxx
where yyy = 1
  and id > 1000
order by id asc
limit 100;
```

> ⚡ 完全走索引，无回表

---

#### 第二步：回表取数据

```sql
select *
from xxx
where id in (
  select id
  from xxx
  where yyy = 1
    and id > 1000
  order by id asc
  limit 100
)
order by id asc;
```

📌 这叫 **延迟回表（Delayed Join）**

---

## 八、最优版本（生产推荐）

### 如果你明确知道需要哪些字段

```sql
select id, col1, col2
from xxx
where yyy = 1
  and id > 1000
order by id asc
limit 100;
```

✔ 覆盖索引
✔ 顺序扫描
✔ 无 filesort
✔ IO 可控

---

## 九、EXPLAIN 预期结果（加分点）

```sql
type: range
key: idx_yyy_id
rows: ~100
Extra: Using index
```

---

## 十、面试一句话总结（可以直接背）

> 这条 SQL 的问题在于 `select *` 破坏覆盖索引、
> 在大数据量下存在回表和排序风险。
> 正确方式是通过 `(yyy, id)` 联合索引配合游标分页，
> 或使用延迟回表来保证查询性能稳定。


