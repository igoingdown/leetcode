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
    ListNode *detectCycle(ListNode *head) {
        ListNode *new_head = new ListNode(0), *fast = new_head, *slow = new_head;
        new_head->next = head;
        while (fast && fast->next) {
            if (slow == fast && slow != new_head) {
                break;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        if (slow == new_head || !slow || !fast || !fast->next) {
            return NULL;
        }
        fast = new_head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
