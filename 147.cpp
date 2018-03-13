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
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return head;
        ListNode *h = new ListNode(0), *temp, *pre;
        while (head) {
            pre = h; temp = h->next;
            while (temp && temp->val < head->val) {
                pre = temp; temp = temp->next;
            }
            ListNode *head_next = head->next;
            pre->next = head;
            head->next = temp;
            head = head_next;
        }
        return h->next;
    }
};