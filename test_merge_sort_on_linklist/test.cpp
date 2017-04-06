#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* merge(ListNode* l1, ListNode* l2);
ListNode* sortList(ListNode* head);


int main(void) {
    cout << "hello word" << endl;
    ListNode *head = new ListNode(2);
    head->next = new ListNode(1);
    ListNode *h = sortList(head);
    cout << "bb" << endl;
    while (h) {
        cout << h->val << " ";
        h = h->next;
    }
    cout << endl;
    return 0;
}

 
ListNode* sortList(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode *prev = NULL;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (prev) {
        prev->next = NULL;
    }
    cout << "prev:" << prev->val << endl;
    ListNode *l1 = sortList(head);
    ListNode *l2 = sortList(slow);
    return merge(l1, l2);
}

ListNode* merge(ListNode* l1, ListNode* l2) {
    ListNode *head = new ListNode(0);
    ListNode *h = head;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            h->next = l1;
            l1 = l1->next;
        } else {
            h->next = l2;
            l2 = l2->next;
        }
        h = h->next;
    }
    if (l2) {
        cout << "l2:" << l2->val << endl;
        h->next = l2;
    }else {
        cout << "l1:" << l1->val << endl;
        h->next = l1;
    }
    ListNode *t = head->next;
    while (t) {
        cout <<"aaa\nt: " << t->val << endl;
        t = t->next;
    }
    return head->next;
}