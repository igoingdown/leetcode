#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotateRight(ListNode* head, int k);

int main(void) {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    ListNode *h = rotateRight(head, 2);
    while (h) {
        cout << h->val << endl;
        h = h->next;
    }
    return 0;
}

ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next || k == 0) {
        return head;
    }
    ListNode *temp = head;
    int length = 0;
    while (temp) {
        length++;
        temp = temp->next;
    }
    if (k % length == 0) {
        return head;
    }
    k = k % length;
    ListNode *newHead = new ListNode(0);
    newHead->next = head;
    ListNode *cur = newHead, *pre = newHead;
    for (int i = 0; i < length + 1 && cur; i++) {
        if (i < length - k) {
            cur = cur->next;
        } else if (i == length - k) {
            ListNode *tempNext = cur->next;
            cur->next = NULL;
            cur = tempNext;
        } else {
            ListNode *tempNext = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            pre = cur;
            cur = tempNext;
        }
    }
    return newHead->next;
}
