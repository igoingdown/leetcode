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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* new_head = new ListNode(0), *pre = head, *cur = head, *end = new_head;;
        while (cur) {
            int i = k;
            while(i-- && cur) cur = cur->next;
            if (i == -1) {
                while (pre != cur) {
                    ListNode* next = pre->next;
                    pre->next = end->next;
                    end->next = pre;
                    pre = next;
                }
                while (end && end->next) end = end->next;
            } else end->next = pre;
        }
        return new_head->next;
    }
};