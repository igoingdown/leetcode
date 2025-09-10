#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode* pre;
    ListNode(int x): val(x), next(NULL), pre(NULL) {}
};

ListNode* createListTable(int m);
void deleteAndPrint(ListNode* head, int n, int k) ;


int main() {
    int m, n, k;
    cin >> m >> n >> k;
    ListNode *head = createListTable(m);
    deleteAndPrint(head, n, k);
    return 0;
}

void deleteAndPrint(ListNode* head, int n, int k) {
    while (head->next != head->pre) {
        ListNode *cur = head;
        for (int i = 0; i < n; i++) cur = cur->next;
        if (head == cur) head = head->next;
        cur->pre->next = cur->next;
        cur->next->pre = cur->pre;
        cout << cur->val << endl;
        delete cur;
        cur = head;
        if (head->next == head->pre) {
            cout << head->val << endl;
            delete head;
            head = NULL;
            break;
        } else {
            for (int i = 0; i < k; i++) cur = cur->pre;
            if (head == cur) head = head->next;
            cur->pre->next = cur->next;
            cur->next->pre = cur->pre;
            cout << cur->val << endl;
            delete cur;
        }
    }
    if (head) {
        cout << head->val << endl;
        delete head;
    }
}



ListNode* createListTable(int m) {
    ListNode* head = new ListNode(0), *tmp = head;
    for (int i = 1; i <= m; i++) {
        auto node = new ListNode(i);
        tmp->next = node;
        node->pre = tmp;
        tmp = node;
    }
    tmp->next = head->next;
    head->next->pre = tmp;
    return head->next;
}

