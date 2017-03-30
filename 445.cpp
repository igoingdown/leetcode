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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *h1 = NULL;
        ListNode *h2 = NULL;
        while (l1) {
            ListNode *temp = new ListNode(l1->val);
            temp->next = h1;
            h1 = temp;
            l1 = l1->next;
        }
        while (l2) {
            ListNode *temp = new ListNode(l2->val);
            temp->next = h2;
            h2 = temp;
            l2 = l2->next;
        }
        ListNode *h3 = NULL;
        int m = 0;
        while (h1 || h2 || m) {
            int sum = 0;
            if (h1 && h2) {
                sum = h1->val + h2->val + m;
                h1 = h1->next;
                h2 = h2->next;
            } else if (h1) {
                sum = h1->val + m;
                h1 = h1->next;
            } else if (h2) {
                sum = h2->val + m;
                h2 = h2->next;
            } else {
                sum = m;
            }
            ListNode *temp = new ListNode(sum % 10);
            m = sum / 10;
            temp->next = h3;
            h3 = temp;
        }
        return h3;
    }
};
