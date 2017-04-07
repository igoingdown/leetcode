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
        if (m >= n) {
            return head;
        }
        if (!head || !head->next) {
            return head;
        }
        ListNode *temp = new ListNode(0);
        temp->next = head;
        ListNode *cur = temp, *pre = temp, *const_pre = temp;
        for (int i = 0; i < n + 1 && cur; i++) {
            if (i < m) {
                pre = cur;
                const_pre = cur;
                cur = cur->next;
            } else if (i > m) {
                ListNode *t = cur->next;
                cur->next = const_pre->next;
                const_pre->next = cur;
                pre->next = t;
                cur = t;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
        return temp->next;
    }
};
