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
    ListNode *h = detectCycle(head);
    if (!h) {
        cout << "no cycle" << endl;
    }
    return 0;
}

ListNode *detectCycle(ListNode *head) {
    if (!head || !head->next) {
        return NULL;
    }
    ListNode *newHead = new ListNode(0);
    newHead->next = head;
    ListNode *slow = newHead, *fast = newHead;
    while (fast && fast->next) {
        if (slow != newHead && slow == fast) {
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    if (!fast || !fast->next) {
        return NULL;
    } else {
        fast = newHead;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
}










