### 解析题干

从你上传的图片来看，这是一道算法设计题，主题是“排序榜更新”（Leaderboard Update）。它要求设计一个“Leaderboard”系统，用于管理用户的分数排行榜。系统需要支持以下几个操作：

1. **updateScore(userId, score)**: 更新某个用户（用userId标识）的分数。如果用户不存在，就添加新用户；如果存在，就更新分数。分数更新后，整个排行榜需要保持有序（通常按分数从高到低排序，同分时可能按userId或其他规则）。

2. **getTopK(K)**: 返回前K名用户的userId列表，按分数降序排列。如果用户少于K，就返回所有用户。

3. **getRank(userId)**: 返回指定用户的排名（从1开始）。排名基于分数，高的分数排名靠前。

图片中的代码是用C++写的，但它不完整，还有一些语法错误（比如Node类的定义看起来像二叉树，但没用上；comparator<xxx>()是占位符）。它用了一个vector<User*>来存储用户，按分数排序，每次更新都sort整个vector。这是一个基础实现，但效率不高（因为每次更新都排序，时间慢）。

这个题目类似于LeetCode上的“设计排行榜”问题（比如1244题），核心是处理频繁更新和查询排名。输入是用户ID（整数）和分数（整数），输出是排名或列表。假设用户数n在1000~10^5级别，操作次数多，所以需要高效算法。

简单说，这就像游戏里的积分排行榜：玩家分数变了，榜单要实时更新，你能快速查谁是前10名，或某人排第几。

### 分析题目思路

#### 核心问题
- **数据结构选择**：需要存储用户ID和分数，支持快速更新、排序和查询。
- **效率考虑**：如果用户很多（比如10万个），每次更新都全排序会很慢（时间复杂度O(n log n) per update，太糟）。所以要找能自动保持有序的结构。
- **排名规则**：分数高的排前，同分时通常按userId小到大（或题目指定）。排名从1开始。
- **边界情况**：新用户添加、分数不变、用户少于K、负分数（假设允许）、用户ID重复等。
- **思路步骤**：
  1. 存储：用map或unordered_map快速找用户是否存在和当前分数。
  2. 排序：用能自动排序的容器，如set（有序集合）、priority_queue（堆）或平衡树。
  3. 更新：如果用户存在，删除旧数据，插入新分数；不存在，直接插。
  4. 查询：getTopK遍历前K；getRank找用户位置。

#### 时间空间分析
- 简单方法：O(n log n)更新，O(1)查询（预排序）。
- 优化方法：O(log n)更新和查询。
- 空间：O(n)存用户。

中学生比喻：想象一个班级成绩榜。简单方法：每次有人改分，就把全班名单重排（费时）。好方法：用一个“自动排序的盒子”，改分时拿出来改了再塞回去，盒子自己排好。

### 多种解法

我给出3种解法，从简单到优化。每个都解释为什么好用，时间复杂度，和C++实现。代码会用简单注释，让中学生看懂（假设你们学过基本C++如vector、map）。

#### 解法1: 简单Vector + Sort（图片里的思路）
- **思路**：用vector存所有用户，每次更新后sort整个vector。getTopK取前K，getRank循环找位置。
- **为什么好**：简单易懂，适合用户少的情况。像手动排序成绩单。
- **缺点**：更新慢，如果n=10^5，更新10^4次就超时。
- **复杂度**：更新O(n log n)，查询O(n)最坏。
- **适用**：小数据测试。

#### 解法2: 用Multiset（有序集合）
- **思路**：用multiset<pair<int, int>>存{ -score, userId }（负分让高分在前）。map<int, int>存userId到score。更新时删旧pair，插新pair。getTopK遍历multiset前K。getRank用lower_bound找位置。
- **为什么好**：multiset自动排序，更新快。像一个聪明盒子，东西塞进去就排好序。
- **缺点**：getRank需计算距离（O(log n + k)如果同分多）。
- **复杂度**：更新O(log n)，查询O(k)或O(log n)。
- **适用**：中等数据，最平衡。

#### 解法3: 用Priority_queue（堆） + Map
- **思路**：用priority_queue<pair<int, int>>存{score, userId}（大顶堆，高分在上）。但堆不支持删任意元素，所以用lazy delete：更新时标记旧分数无效，查询时跳过无效的。
- **为什么好**：堆顶总是最高分，getTopK快。但需处理“僵尸”数据（旧分数）。
- **缺点**：查询时可能多pop无效数据，坏情况下慢。
- **复杂度**：更新O(log n)，getTopK O(k log n)最坏。
- **适用**：更新多，getTopK少。

其他解法如用树（红黑树，set底层就是），或分桶排序（如果分数范围小），但以上够用。

### C++实现

下面是完整代码，每个解法一个类。假设同分按userId升序排（小ID在前）。我加了main测试，输入如：
- updateScore(1, 10)
- updateScore(2, 20)
- getTopK(1) -> [2]
- getRank(1) -> 2

编译运行：g++ file.cpp -o out && ./out

#### 解法1: Vector + Sort

```cpp
#include <bits/stdc++.h>
using namespace std;

// 用户类，存ID和分数
class User {
public:
    int id;
    int score;
    User(int _id, int _score) : id(_id), score(_score) {}  // 构造函数
};

class Leaderboard {
public:
    vector<User*> board;  // 存所有用户指针
    map<int, int> uid2score;  // map快速查用户分数

    // 更新分数
    void updateScore(int userId, int score) {
        if (uid2score.find(userId) == uid2score.end()) {
            // 新用户，添加
            board.push_back(new User(userId, score));
        } else {
            // 旧用户，更新分数
            for (auto u : board) {
                if (u->id == userId) {
                    u->score = score;
                    break;
                }
            }
        }
        uid2score[userId] = score;
        
        // 排序：分数降序，同分ID升序
        sort(board.begin(), board.end(), [](User* a, User* b) {
            if (a->score != b->score) return a->score > b->score;
            return a->id < b->id;
        });
    }

    // 获取前K名ID
    vector<int> getTopK(int K) {
        vector<int> res;
        for (int i = 0; i < min(K, (int)board.size()); i++) {
            res.push_back(board[i]->id);
        }
        return res;
    }

    // 获取排名，从1开始
    int getRank(int userId) {
        for (int i = 0; i < board.size(); i++) {
            if (board[i]->id == userId) return i + 1;
        }
        return -1;  // 没找到
    }
};

int main() {
    Leaderboard lb;
    lb.updateScore(1, 10);
    lb.updateScore(2, 20);
    lb.updateScore(1, 15);  // 更新1的分数
    vector<int> top = lb.getTopK(2);
    cout << "Top 2: ";
    for (int id : top) cout << id << " ";
    cout << endl;  // 输出: 2 1
    cout << "Rank of 1: " << lb.getRank(1) << endl;  // 2
    return 0;
}
```

解释：board像一个列表，每次sort像重排座位。简单但慢。

#### 解法2: Multiset

```cpp
#include <bits/stdc++.h>
using namespace std;

class Leaderboard {
public:
    // multiset存{-score, id}，负分让高分在前，同分多允许
    multiset<pair<int, int>> scores;  
    // map存id到score，快速查
    unordered_map<int, int> uid2score;  

    void updateScore(int userId, int score) {
        if (uid2score.count(userId)) {
            // 删旧的
            scores.erase(scores.find({-uid2score[userId], userId}));
        }
        // 插新的
        scores.insert({-score, userId});
        uid2score[userId] = score;
    }

    vector<int> getTopK(int K) {
        vector<int> res;
        auto it = scores.begin();
        for (int i = 0; i < K && it != scores.end(); ++i, ++it) {
            res.push_back(it->second);
        }
        return res;
    }

    int getRank(int userId) {
        if (!uid2score.count(userId)) return -1;
        auto target = make_pair(-uid2score[userId], userId);
        // lower_bound找第一个不小于target的位置
        auto it = scores.lower_bound(target);
        // 计算距离，即排名
        return distance(scores.begin(), it) + 1;
    }
};

int main() {
    Leaderboard lb;
    lb.updateScore(1, 10);
    lb.updateScore(2, 20);
    lb.updateScore(1, 15);
    vector<int> top = lb.getTopK(2);
    cout << "Top 2: ";
    for (int id : top) cout << id << " ";
    cout << endl;  // 2 1
    cout << "Rank of 1: " << lb.getRank(1) << endl;  // 2
    return 0;
}
```

解释：multiset像自动排序的队列，插删都快。像魔法盒子，东西进去就按规则排好。getRank用“距离”算位置。

#### 解法3: Priority_queue + Lazy Delete

```cpp
#include <bits/stdc++.h>
using namespace std;

class Leaderboard {
public:
    // 大顶堆，{score, id}
    priority_queue<pair<int, int>> pq;  
    // map存最新score
    unordered_map<int, int> uid2score;  
    // set存无效的{score, id}
    set<pair<int, int>> invalid;  

    void updateScore(int userId, int score) {
        if (uid2score.count(userId)) {
            // 标记旧的无效
            invalid.insert({uid2score[userId], userId});
        }
        uid2score[userId] = score;
        pq.push({score, userId});
    }

    vector<int> getTopK(int K) {
        vector<int> res;
        while (!pq.empty() && res.size() < K) {
            auto top = pq.top();
            pq.pop();
            if (invalid.count(top) || top.first != uid2score[top.second]) {
                continue;  // 无效，跳过
            }
            res.push_back(top.second);
        }
        // 放回堆（因为pop了）
        for (auto id : res) {
            pq.push({uid2score[id], id});
        }
        return res;
    }

    int getRank(int userId) {
        if (!uid2score.count(userId)) return -1;
        int rank = 1;
        set<pair<int, int>> seen;  // 避免重复
        priority_queue<pair<int, int>> temp = pq;  // 复制堆
        while (!temp.empty()) {
            auto top = temp.top();
            temp.pop();
            if (invalid.count(top) || top.first != uid2score[top.second]) continue;
            if (seen.count(top)) continue;
            seen.insert(top);
            if (top.second == userId) return rank;
            rank++;
        }
        return -1;
    }
};

int main() {
    Leaderboard lb;
    lb.updateScore(1, 10);
    lb.updateScore(2, 20);
    lb.updateScore(1, 15);
    vector<int> top = lb.getTopK(2);
    cout << "Top 2: ";
    for (int id : top) cout << id << " ";
    cout << endl;  // 2 1
    cout << "Rank of 1: " << lb.getRank(1) << endl;  // 2
    return 0;
}
```

解释：堆像一个金字塔，顶上总是最高。更新不删旧的，而是标记“垃圾”，查询时扫垃圾。getRank需遍历（慢点），但简单。


