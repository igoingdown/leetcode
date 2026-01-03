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

int main() {
    LockFreeQueue q;
    
    // 单线程测试
    q.push(1);
    q.push(2);
    q.push(3);
    
    int value;
    while (q.pop(value)) {
        cout << "Pop: " << value << endl;
    }
    
    cout << "Queue is empty: " << q.empty() << endl;
    
    return 0;
}
