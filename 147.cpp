#include <iostream>
#include <stdio.h>

using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* insertionSortList(ListNode* head);

int main(void) {
    cout << "hello world" << endl;
    ListNode *head = new ListNode(0);
    head->next = new ListNode(0);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(0);
    head->next->next->next->next = new ListNode(0);
    ListNode* l = insertionSortList(head);
    while (l) {
        cout << l->val << endl;
        l = l->next;
    }
    return 0;
}



ListNode* insertionSortList(ListNode* head) {
    ListNode *h = new ListNode(0);
    ListNode *temp;
    ListNode *maxNode = h;
    while (head) {
        ListNode *pre = h;
        temp = h->next;
        while (temp && temp->val < head->val) {
            pre = temp;
            temp = temp->next;
            cout << "b" << endl;
        }
        cout << "a" << endl;
        ListNode *head_next = head->next;
        pre->next = head;
        head->next = temp;
        head = head_next;
    }
    return h->next;
}





















