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
    ListNode* swapPairs(ListNode* head) {
        ListNode* new_head = new ListNode(0), *tmp = new_head;
        while (head && head->next) {
            ListNode* next = head->next->next;
            tmp->next = head->next;
            tmp = tmp->next;
            tmp->next = head;
            tmp = tmp->next;
            tmp->next = next;
            head = next;
        }
        return new_head->next ? new_head->next : head;
    }
};