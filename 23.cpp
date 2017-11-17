#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL) {}
};

class Comparison
{
public:
	bool operator() (ListNode* a, ListNode* b) {
		return a->val > b->val;
	}
};

ListNode* mergeKLists(vector<ListNode*>& lists);

int main(int argc, char const *argv[])
{
	ListNode* a = new ListNode(1);
	ListNode* b = new ListNode(0);
	vector<ListNode*> v(2, a);
	v[1] = b;
	auto head = mergeKLists(v);
	while (head) {
		cout << head->val << endl;
		head = head->next;
	}
	return 0;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, Comparison> q(lists.begin(), lists.end());
    ListNode* head = new ListNode(0), *last = head;
    while (!q.empty()) {
        auto cur = q.top();
        q.pop();
        if (cur->next) q.push(cur->next);
        ListNode* tmp = last->next;
        last->next= cur;
        cur->next = tmp;
        last = cur;
    }
    return head->next;
}



