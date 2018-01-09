/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Comparison{
public:
    bool operator() (ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Comparison> q;
        for (auto n : lists) {
            if (n) q.push(n);
        }
        ListNode* head = new ListNode(0), *tmp = head;
        while (!q.empty()) {
            auto cur = q.top();
            q.pop();
            tmp->next = cur;
            tmp = cur;
            if (cur->next) q.push(cur->next);
        }
        tmp->next = NULL;
        return head->next;
    }
};