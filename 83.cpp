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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *new_head = new ListNode(0), *pre = new_head, *cur = head;
        new_head->next = head;
        while (cur) {
            for (; cur && cur->next && cur->val == cur->next->val; cur = cur->next);
            pre->next = cur;
            pre = pre->next;
            cur = cur->next;
        }
        return new_head->next;
    }
};