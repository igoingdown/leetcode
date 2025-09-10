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
    ListNode* swapPairs(ListNode* head) {
        ListNode *tmpHead = new(ListNode), *tmp = tmpHead;
        tmp->next = head;
        while (tmp && tmp->next) {
            if (tmp->next && tmp->next->next) {
                ListNode *a = tmp, *b = a->next, *c = b->next, *d = c->next;
                b->next = d;
                c->next = b;
                a->next = c;
                tmp = tmp->next->next;
            } else {
                break;
            }
        }
        return tmpHead->next;
    }
};