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
        ListNode* new_head = new ListNode(0), *pre = new_head, *cur = head;
        new_head->next = head;
        while (cur) {
            int dup;
            for (dup = 1; cur && cur->next && cur->val == cur->next->val; dup++) cur = cur->next;
            if (dup == 1) pre = cur;
            else pre->next = cur->next;
            cur = cur->next;
        }
        return new_head->next;
    }
};