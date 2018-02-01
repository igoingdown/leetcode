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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        int len = 0;
        for (auto tmp = head; tmp; tmp = tmp->next, len++);
        k %= len;
        ListNode *new_head = new ListNode(0), *fast = new_head, *slow = new_head;
        new_head->next = head;
        while(k-- && fast) fast = fast->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = new_head->next;
        auto res = slow->next;
        slow->next = NULL;
        return res;
    }
};