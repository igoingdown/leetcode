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
        if (m >= n || !head || !head->next) return head;
        ListNode* new_head = new ListNode(0);
        new_head->next = head;
        ListNode* cur = new_head, * part_pre = new_head, * part_end = new_head;
        for (int i = 0; i < n + 1 && cur; i++) {
            if (i < m) {
                part_pre = part_end = cur;
                cur = cur->next;
            } else if (i > m) {
                ListNode* tmp = cur->next;
                cur->next = part_pre->next;
                part_pre->next = cur;
                part_end->next = tmp;
                cur = tmp;
            } else {
                part_end = cur;
                cur = cur->next;
            }
        }
        return new_head->next;
    }
};