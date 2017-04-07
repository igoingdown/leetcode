#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head);

int main(void) {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    ListNode *h = deleteDuplicates(head);
    while (h) {
        cout << h->val << endl;
        h = h->next;
    }
    return 0;
}

ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode *newHead = new ListNode(0);
    newHead->next = head;
    ListNode *pre = newHead, *cur = head;
    while (cur) {
        int dupNum;
        for (dupNum = 1; cur && cur->next && cur->val == cur->next->val; dupNum++) {
            cur = cur->next;
        }
        if (dupNum == 1) {
            pre = cur;
            cur = cur->next;
        } else {
            pre->next = cur->next;
            cur = cur->next;
        }
    }
    return newHead->next;
}
