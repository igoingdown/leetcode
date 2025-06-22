/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *h = new(ListNode), *tmp = h;
        int n = 0;
        while (l1 || l2 || n > 0) {
            if (l1) {
                n += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                n += l2->val;
                l2 = l2->next;
            }
            tmp->next = new ListNode(n%10);
            n /= 10;
            tmp = tmp->next;
        }
        return h->next;
    }
};