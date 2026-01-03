/*
 * 无锁队列实现详解
 * 
 * 当前代码存在的问题：
 * 1. tail 不是原子的，多线程同时 push 会有数据竞争
 * 2. push 中的 tail->next = node 和 tail = node 不是原子操作
 * 3. pop 中读取 head 和更新 head 之间可能有其他线程修改
 * 4. head == tail 的比较在多线程环境下不可靠
 * 
 * 无锁队列实现方案：Michael & Scott 算法
 * 核心思想：
 * 1. 使用 dummy node 简化边界条件处理
 * 2. head 和 tail 都是原子类型
 * 3. 使用 CAS (Compare-And-Swap) 循环确保原子性
 * 4. push 操作只修改 tail，pop 操作只修改 head
 */

#include <iostream>
#include <atomic>
#include <thread>
#include <vector>
#include <chrono>
using namespace std;

struct Node {
    atomic<Node*> next;  // next 指针也必须是原子的
    int value;
    
    Node(int val = 0) : value(val), next(nullptr) {}
};

class LockFreeQueue {
private:
    atomic<Node*> head;  // 指向 dummy node
    atomic<Node*> tail;  // 指向最后一个节点（可能是 dummy node）
    
public:
    LockFreeQueue() {
        // 初始化时创建一个 dummy node
        // head 和 tail 都指向它，这样队列永远不为空
        Node* dummy = new Node();
        head.store(dummy);
        tail.store(dummy);
    }
    
    ~LockFreeQueue() {
        // 清理所有节点
        while (Node* old_head = head.load()) {
            head.store(old_head->next.load());
            delete old_head;
        }
    }
    
    // 入队操作
    void push(int value) {
        Node* new_node = new Node(value);
        Node* prev_tail = nullptr;
        Node* null_node = nullptr;
        
        // CAS 循环：确保原子地更新 tail
        while (true) {
            // 1. 读取当前的 tail
            prev_tail = tail.load();
            
            // 2. 读取 tail->next（应该是 nullptr，除非有其他线程正在更新）
            Node* next = prev_tail->next.load();
            
            // 3. 验证 tail 是否还是我们读取的那个（防止其他线程已经修改）
            if (prev_tail != tail.load()) {
                continue;  // tail 被其他线程修改了，重试
            }
            
            // 4. 如果 tail->next 不为空，说明其他线程正在更新 tail，帮助它完成
            if (next != nullptr) {
                // 尝试将 tail 推进到实际的最后一个节点
                tail.compare_exchange_weak(prev_tail, next);
                continue;
            }
            
            // 5. 尝试将新节点链接到 tail
            // CAS: 如果 prev_tail->next 是 nullptr，则设置为 new_node
            if (prev_tail->next.compare_exchange_weak(null_node, new_node)) {
                // 成功链接新节点
                break;
            }
        }
        
        // 6. 尝试更新 tail 指向新节点（可能失败，但没关系，其他线程会帮忙）
        tail.compare_exchange_weak(prev_tail, new_node);
    }
    
    // 出队操作
    bool pop(int& value) {
        while (true) {
            // 1. 读取当前的 head 和 tail
            Node* old_head = head.load();
            Node* old_tail = tail.load();
            
            // 2. 读取 head->next（实际的数据节点）
            Node* next = old_head->next.load();
            
            // 3. 验证 head 是否还是我们读取的那个
            if (old_head != head.load()) {
                continue;  // head 被其他线程修改了，重试
            }
            
            // 4. 如果 head == tail，需要判断队列是否为空
            if (old_head == old_tail) {
                // 如果 next 为空，说明队列为空（只有 dummy node）
                if (next == nullptr) {
                    return false;  // 队列为空
                }
                // 否则，tail 落后了，帮助它推进
                tail.compare_exchange_weak(old_tail, next);
            } else {
                // 5. 队列不为空，尝试取出数据
                if (next == nullptr) {
                    continue;  // 异常情况，重试
                }
                
                // 6. 读取要返回的值
                value = next->value;
                
                // 7. 尝试将 head 推进到下一个节点（即删除 dummy node，next 成为新的 dummy）
                if (head.compare_exchange_weak(old_head, next)) {
                    // 成功，删除旧的 dummy node
                    delete old_head;
                    return true;
                }
                // CAS 失败，重试
            }
        }
    }
    
    bool empty() {
        // 队列为空当且仅当 head->next == nullptr
        Node* h = head.load();
        return h->next.load() == nullptr;
    }
};

// 全局统计变量
atomic<int> push_count(0);
atomic<int> pop_count(0);
atomic<bool> producers_done(false);

// 生产者函数：每个线程 push 固定数量的数据
void producer(LockFreeQueue& q, int thread_id, int items_per_thread) {
    for (int i = 0; i < items_per_thread; i++) {
        int value = thread_id * 10000 + i;  // 唯一标识每个值
        q.push(value);
        push_count.fetch_add(1, memory_order_relaxed);
    }
}

// 消费者函数：持续 pop 直到队列为空且生产者完成
void consumer(LockFreeQueue& q, int& local_pop_count) {
    int value;
    while (true) {
        if (q.pop(value)) {
            local_pop_count++;
            pop_count.fetch_add(1, memory_order_relaxed);
        } else {
            // 队列为空，检查生产者是否完成
            if (producers_done.load(memory_order_acquire)) {
                // 再试一次，确保没有遗漏
                if (!q.pop(value)) {
                    break;  // 确实为空，退出
                } else {
                    local_pop_count++;
                    pop_count.fetch_add(1, memory_order_relaxed);
                }
            } else {
                // 生产者还在工作，稍等片刻
                this_thread::yield();
            }
        }
    }
}

int main() {
    cout << "========== 单线程测试 ==========" << endl;
    LockFreeQueue q1;
    
    // 单线程测试
    q1.push(1);
    q1.push(2);
    q1.push(3);
    
    int value;
    while (q1.pop(value)) {
        cout << "Pop: " << value << endl;
    }
    
    cout << "Queue is empty: " << q1.empty() << endl;
    cout << endl;
    
    cout << "========== 多线程测试 ==========" << endl;
    
    // 重置统计变量
    push_count.store(0);
    pop_count.store(0);
    producers_done.store(false);
    
    // 测试参数
    const int NUM_PRODUCERS = 4;      // 生产者线程数
    const int NUM_CONSUMERS = 4;      // 消费者线程数
    const int ITEMS_PER_PRODUCER = 1000;  // 每个生产者 push 的数量
    
    LockFreeQueue q;
    vector<thread> producer_threads;
    vector<thread> consumer_threads;
    vector<int> consumer_counts(NUM_CONSUMERS, 0);  // 每个消费者 pop 的数量
    
    auto start_time = chrono::high_resolution_clock::now();
    
    // 启动消费者线程
    for (int i = 0; i < NUM_CONSUMERS; i++) {
        consumer_threads.emplace_back([&q, &consumer_counts, i]() {
            consumer(q, consumer_counts[i]);
        });
    }
    
    // 启动生产者线程
    for (int i = 0; i < NUM_PRODUCERS; i++) {
        producer_threads.emplace_back([&q, i]() {
            producer(q, i, ITEMS_PER_PRODUCER);
        });
    }
    
    // 等待所有生产者完成
    for (auto& t : producer_threads) {
        t.join();
    }
    
    // 标记生产者完成
    producers_done.store(true, memory_order_release);
    
    // 等待所有消费者完成
    for (auto& t : consumer_threads) {
        t.join();
    }
    
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);
    
    // 输出统计信息
    cout << "测试配置:" << endl;
    cout << "  生产者线程数: " << NUM_PRODUCERS << endl;
    cout << "  消费者线程数: " << NUM_CONSUMERS << endl;
    cout << "  每个生产者 push 数量: " << ITEMS_PER_PRODUCER << endl;
    cout << "  总 push 数量: " << NUM_PRODUCERS * ITEMS_PER_PRODUCER << endl;
    cout << endl;
    
    cout << "测试结果:" << endl;
    cout << "  实际 push 数量: " << push_count.load() << endl;
    cout << "  实际 pop 数量: " << pop_count.load() << endl;
    cout << "  队列是否为空: " << (q.empty() ? "是" : "否") << endl;
    cout << "  执行时间: " << duration.count() << " ms" << endl;
    cout << endl;
    
    // 输出每个消费者的 pop 数量
    cout << "各消费者 pop 数量:" << endl;
    int total_consumer_pop = 0;
    for (int i = 0; i < NUM_CONSUMERS; i++) {
        cout << "  消费者 " << i << ": " << consumer_counts[i] << endl;
        total_consumer_pop += consumer_counts[i];
    }
    cout << "  消费者总计: " << total_consumer_pop << endl;
    cout << endl;
    
    // 验证结果
    cout << "========== 验证结果 ==========" << endl;
    bool all_passed = true;
    
    int expected_push = NUM_PRODUCERS * ITEMS_PER_PRODUCER;
    if (push_count.load() != expected_push) {
        cout << "❌ 失败: push 数量不匹配! 期望: " << expected_push 
             << ", 实际: " << push_count.load() << endl;
        all_passed = false;
    } else {
        cout << "✅ 通过: push 数量正确" << endl;
    }
    
    if (pop_count.load() != expected_push) {
        cout << "❌ 失败: pop 数量不匹配! 期望: " << expected_push 
             << ", 实际: " << pop_count.load() << endl;
        all_passed = false;
    } else {
        cout << "✅ 通过: pop 数量正确" << endl;
    }
    
    if (push_count.load() != pop_count.load()) {
        cout << "❌ 失败: push 和 pop 数量不一致! push: " << push_count.load()
             << ", pop: " << pop_count.load() << endl;
        all_passed = false;
    } else {
        cout << "✅ 通过: push 和 pop 数量一致" << endl;
    }
    
    if (!q.empty()) {
        cout << "❌ 失败: 队列不为空!" << endl;
        all_passed = false;
    } else {
        cout << "✅ 通过: 队列为空" << endl;
    }
    
    if (total_consumer_pop != pop_count.load()) {
        cout << "❌ 失败: 消费者统计不一致! 总计: " << total_consumer_pop
             << ", pop_count: " << pop_count.load() << endl;
        all_passed = false;
    } else {
        cout << "✅ 通过: 消费者统计一致" << endl;
    }
    
    cout << endl;
    if (all_passed) {
        cout << "🎉 所有测试通过！无锁队列实现正确。" << endl;
    } else {
        cout << "⚠️  部分测试失败，请检查实现。" << endl;
    }
    
    return all_passed ? 0 : 1;
}
