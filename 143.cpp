#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void reorderList(ListNode* head);

int main(void) {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    reorderList(head);
    while (head) {
        cout << head->val << endl;
        head = head->next;
    }
}

void reorderList(ListNode* head) {
    if (!head || !head->next) {
        return;
    }
    ListNode *pre = NULL;
    ListNode *slow = head, *fast = head, *temp = head;
    while (fast && fast->next) {
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (pre) {
        pre->next = NULL;
    }
    pre = NULL;
    while (slow) {
        fast = slow->next;
        slow->next = pre;
        pre = slow;
        slow = fast;
    }
    ListNode *r = head;
    while (pre && temp) {
        r = pre;
        slow = temp->next;
        fast = pre->next;
        temp->next = pre;
        pre->next = slow;
        pre = fast;
        temp = slow;
    }
    ListNode *temp_head = head;
    while (temp_head) {
        temp_head = temp_head->next;
    }
    if (pre) {
        r->next = pre;
        
    }
}















