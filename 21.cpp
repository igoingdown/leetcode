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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *new_head = new ListNode(0), *tmp = new_head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tmp->next = l1; tmp = l1; l1 = l1->next;
            } else {
                tmp->next = l2; tmp = l2; l2 = l2->next;
            }
        }
        if (l2) l1 = l2;
        while (l1) {
            tmp->next = l1; tmp = l1; l1 = l1->next;
        }
        return new_head->next;
    }
};