#include <iostream>
#include <vector>
#include <sstream>

using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL){}
};

int get_length(ListNode *head);
ListNode *reverse_list(ListNode *head);
ListNode *get_common_head(ListNode *head1, ListNode *head2);
ListNode *get_last(ListNode *head);
ListNode *create_list(istringstream &in);
ListNode *get_common_head_two_pointers(ListNode *head1, ListNode *head2);

int main() {
	string s1,s2,s3; 
	cin >> s1; istringstream in1(s1);
	ListNode *head1 = create_list(in1);
	cin >> s2; istringstream in2(s2);
	ListNode *head2 = create_list(in2);
	cin >> s3; istringstream in3(s3);
	ListNode *common_head = create_list(in3);
	ListNode *last1 = get_last(head1), *last2 = get_last(head2);
	last1->next = common_head; last2->next = common_head;
	ListNode *c = get_common_head_two_pointers(head1, head2);
	if (c) cout << c->val << endl;
	c = NULL; c = get_common_head(head1, head2);
	if (c) cout << c->val << endl;
	return 0;
}

ListNode *get_common_head_two_pointers(ListNode *head1, ListNode *head2) {
	int l1 =get_length(head1), l2 = get_length(head2), diff = l1 > l2 ? l1 - l2 : l2 - l1;
	if (l2 > l1) {
		ListNode *tmp = head2; head2 = head1, head1 = tmp;
	}
	cout << "diff: " << diff << endl;
	while (diff--) head1 = head1->next;
	while (head1 && head2 && head1 != head2) {
		head1 = head1->next; head2 = head2->next;
	}
	return head1;
}


ListNode *create_list(istringstream &in) {
	int x;
	ListNode *head = new ListNode(0);
	while (in >> x) {
		in.get();
		ListNode *tmp = new ListNode(x); tmp->next = head->next; head->next = tmp;
	}
	return head->next;
}


ListNode *get_last(ListNode *head) {
	ListNode *pre = NULL, *cur = head;
	while(cur) {
		pre = cur; cur = cur->next;
	}
	return pre;
}

int get_length(ListNode *head) {
	ListNode *tmp = head; int l = 0;
	while (tmp) {
		tmp = tmp->next; ++l;
	}
	return l;
}

ListNode * reverse_list(ListNode *head) {
	ListNode *new_head = new ListNode(0), *tmp;
	while (head) {
		tmp = head->next; head->next = new_head->next; new_head->next = head; head = tmp;
	}
	return new_head->next;
}

ListNode *get_common_head(ListNode *head1, ListNode *head2) {
	if (get_last(head1) != get_last(head2)) return NULL;
	int l1 = get_length(head1), l2 = get_length(head2);
	ListNode *reverse_head = NULL;
	reverse_head = reverse_list(head1);
	int reverse_len = get_length(head2);
	int count = (l1 + l2 - reverse_len + 1) >> 1;
	ListNode *res = reverse_head;
	while (--count && reverse_head) reverse_head = reverse_head->next;
	return reverse_head;
}










