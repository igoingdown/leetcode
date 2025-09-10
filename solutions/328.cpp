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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd_head = new ListNode(0);
        ListNode *even_head = new ListNode(0);
        ListNode *odd = odd_head;
        ListNode *even = even_head;
        for (int i = 1; head; i++) {
            if (i % 2 == 1) {
                odd->next = head;
                odd = odd->next;
            } else {
                even->next = head;
                even = even->next;
            }
            head = head->next;
        }
        odd->next = even_head->next;
        even->next = NULL;
        return odd_head->next;
    }
};
