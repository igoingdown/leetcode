#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x), next(NULL){}
};

ListNode * delete_node(ListNode *head, ListNode *to_delete);

int main() {
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	ListNode *new_head = delete_node(head, head->next);
	while (new_head) {
		cout << new_head->val << endl; new_head = new_head->next;
	}
	return 0;
}

ListNode * delete_node(ListNode *head, ListNode *to_delete) {
	if (!to_delete || !head) return head;
	if (!to_delete->next) {
		ListNode *pre = NULL, *cur = head;
		while (cur->next) {
			pre = cur; cur = cur->next;
		}
		if (pre) {
			pre->next = NULL;
			delete cur; return head;
		} else {
			delete head; return NULL;
		}
	}
	ListNode *tmp = to_delete->next;
	to_delete->val = to_delete->next->val;
	to_delete->next = to_delete->next->next;
	delete tmp;
	return head;
}
