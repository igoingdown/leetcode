/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *new_head = new ListNode(0), *pre = new_head, *end = new_head;
        new_head->next = head;
        for (int i = 0; i <= n; i++) {
            if (i < m - 1) pre = pre->next;
            end = end->next;
        }
        auto tmp = pre->next; pre->next = end;
        while (tmp != end) {
            auto next = tmp->next;
            tmp->next = pre->next;
            pre->next = tmp;
            tmp = next;
        }
        return new_head->next;
    }
};