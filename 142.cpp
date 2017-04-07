#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head);


int main(void) {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = head;
    ListNode *h = detectCycle(head);
    cout << h->val << endl;
    return 0;
}

ListNode *detectCycle(ListNode *head) {
    if (!head || !head->next) {
        return NULL;
    } else if (head == head->next) {
        return head;
    }
    ListNode *temp = new ListNode(0);
    temp->next = head;
    ListNode *slow = temp, *fast = temp;
    while (fast && fast->next) {
        cout << "fast: " << fast->val << endl;
        cout << "slow: " << slow->val << endl;
        if (fast == slow && !(slow == temp)) {
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    if (!fast || !fast->next) {
        return NULL;
    } else {
        slow = temp;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
}















