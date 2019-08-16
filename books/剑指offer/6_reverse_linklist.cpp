#include <iostream>
#include <vector>
#include <stack>


using namespace std;

struct ListNode{
	ListNode *next;
	int val;
	ListNode(int x):val(x), next(NULL) {}
};


void reverse_link_recursion(ListNode *head) {
	if (!head) return;
	reverse_link_recursion(head->next);
	cout << head->val << endl;
}


void reverse_link_stack(ListNode *head) {
	stack<int> s;
	while (head) {
		s.push(head->val); head = head->next;
	}
	while (!s.empty()) {
		cout << s.top() << endl; s.pop();
	}
}


void reverse_link(ListNode *head) {
	ListNode *new_head = new ListNode(0);
	while (head) {
		auto tmp = new_head->next;
		new_head->next = head;
		head = head->next;
		new_head->next->next = tmp;
	}
	new_head = new_head->next;
	while (new_head) {
		cout << new_head->val << endl; new_head = new_head->next;
	}
}

int main() {
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	reverse_link_recursion(head);
	cout << endl;
	reverse_link_stack(head);
	cout << endl;
	reverse_link(head);
	return 0;
}




