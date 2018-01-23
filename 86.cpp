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
        if (!head || !head->next) return head;
        ListNode *head1 = new ListNode(0), *head2 = new ListNode(0), *tail1 = head1, *tail2 = head2;
        while (head) {
            auto tmp = head->next;
            if (head->val < x) {
                tail1->next = head;
                tail1 = tail1->next;
            } else {
                tail2->next = head;
                tail2 = tail2->next;
            }
            head = tmp;
        }
        tail1->next = head2->next;
        tail2->next = NULL;
        return head1->next;
    }
};