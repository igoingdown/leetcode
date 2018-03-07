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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return; //链表少于两个节点直接返回
        ListNode *slow = head, *fast = head, *pre = NULL;
        while (fast && fast->next) { // 快慢指针将链表对半分
            pre = slow; slow = slow->next; fast = fast->next->next;
        }
        if (!fast) slow = pre;  //节点为偶数，slow向前进一个，将正中间的节点归到左侧
        ListNode *right_head = NULL, *cur = slow->next, *left_head = head, *tmp; // cur为当前右侧链表的开头
        cout << slow->val << endl;
        slow->next = NULL; //将左、右侧链表分离
        while(cur) { // 将右侧链表使用头插法倒置
            tmp = cur->next; cur->next = right_head; right_head = cur; cur = tmp; 
        }
        while (right_head) { // 将右侧链表逐个插入左侧链表
            tmp = right_head->next; right_head->next = left_head->next; left_head->next = right_head; right_head = tmp; left_head = left_head->next->next;
        }
    }
};