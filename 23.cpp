#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists);

int main() {
    ListNode* a = new ListNode(0);
    ListNode* b = new ListNode(2);
    vector<ListNode*> v = {a, b};
    auto h = mergeKLists(v);
    cout << h->val << endl;
    return 0;
}



class Comparison{
public:
    bool operator() (ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};


ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, [](const ListNode* a, const ListNode* b) {return a->val > b->val;}> q;
    for (auto n : lists) {
        if (n) q.push(n);
    }
    ListNode* head = new ListNode(0), *tmp = head;
    while (!q.empty()) {
        auto cur = q.top();
        q.pop();
        tmp->next = cur;
        tmp = cur;
        if (cur->next) q.push(cur->next);
    }
    return head->next;
}