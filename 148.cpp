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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *prev = NULL, *slow = head, *fast = head;
        while (fast && fast->next) {
            prev = slow; slow = slow->next; fast = fast->next->next;
        }
        if (prev) prev->next = NULL;
        ListNode *l1 = sortList(head), *l2 = sortList(slow);
        return merge(l1, l2);
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0), *h = head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                h->next = l1; l1 = l1->next;
            } else {
                h->next = l2; l2 = l2->next;
            }
            h = h->next;
        }
        if (l2) h->next = l2;
        else h->next = l1;
        return head->next;
    }
};

