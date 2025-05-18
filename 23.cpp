/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class myCmp {
public:
    bool operator() (ListNode *a, ListNode *b) {
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 使用函数模版类，实例化之后出来的就是入参 2 个指针，出参为 bool 的函数对象
        priority_queue<ListNode*, vector<ListNode*>, myCmp> q;
        for (auto n : lists) {
            if (n) {
                q.push(n);
            }
        }
        ListNode *head = new ListNode(), *tmp = head;
        while (!q.empty()) {
            tmp->next = q.top();
            tmp = tmp->next;
            q.pop();
            if (tmp->next) {
                q.push(tmp->next);
            }
        }
        return head->next;
    }
};