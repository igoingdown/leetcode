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
        ListNode *res = new ListNode(0), *cur = res;
        int s = 0, c = 0;
        while (l1 || l2 || c > 0) {
            s += c;
            if (l1) {
                s += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                s += l2->val;
                l2 = l2->next;
            }
            c = s/10;
            cur->next = new ListNode(s%10);
            cur = cur->next;
            s = 0;
        }
        return res->next;
    }
};
