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
        if (!head || !head->next) return NULL;
        ListNode *newHead = new ListNode(0), *slow = newHead, *fast = newHead;
        newHead->next = head;
        while (fast && fast->next) {
            if (slow != newHead && slow == fast) break;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (!fast || !fast->next) return NULL;
        else {
            fast = newHead;
            while (slow != fast) {
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        }
    }
};