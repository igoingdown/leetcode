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
        int c = 0;
        ListNode* sum = new ListNode(0), *tmp = sum;
        while (l1 || l2) {
            int s = c;
            if (l1) {
                s += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                s += l2->val;
                l2 = l2->next;
            }
            ListNode* cur = new ListNode(s % 10);
            c = s / 10;
            tmp->next = cur;
            tmp = cur;
        }
        if (c) {
            ListNode* cur = new ListNode(c);
            tmp->next = cur;
        }
        return sum->next;
    }
};