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
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *h1 = new ListNode(0);
        ListNode *h2 = new ListNode(0);
        ListNode *tail1 = h1, *tail2 = h2;;
        while (head) {
            ListNode *temp = head->next;
            if (head->val < x) {
                head->next = tail1->next;
                tail1->next = head;
                tail1 = head;
            } else {
                head->next = tail2->next;
                tail2->next = head;
                tail2 = head;
            }
            head = temp;
        }
        tail1->next = h2->next;
        return h1->next;
    }
};
