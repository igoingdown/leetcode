#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <set>

using namespace std;

struct node {
    int val;
    node* next;
    node* child;
    node(int x): val(x), next(NULL), child(NULL) {};
};

node* flattenList(struct node *head);

int main(int argc, char const *argv[])
{
	node* root = new node(10);
	root->next = new node(5);
	root->child = new node(4);
	root->child->next = new node(20);
	root->next->next = new node(7);
	root->next->next->child = new node(17);
	node* head = new node(-1);
	head->next = root;
	flattenList(head);
	while (head->next) {
		cout << head->next->val << endl;
		head = head->next;
	}
    return 0;
}

node* flattenList(struct node *head) {
    if (!head->next) return head;
    queue<node*> q, next;
    q.push(head->next);
    while (!q.empty()) {
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            node* pre = NULL, *tmp = cur;
            while (tmp) {
                if (tmp->child) {
                    q.push(tmp->child);
                    tmp->child = NULL; // 断开当前原始父节点到子女的链接
                }
                pre = tmp;
                tmp = tmp->next;
            }
            if (q.empty()) {
                // 没有兄弟看是否有下一层，如果没有，就返回，有的话就链接到后面
                if (!next.empty()) {
                    pre->next = next.front();
                }
                else return head;
            } else {
                // 有兄弟则链接到后面
                pre->next = q.front();
            }
        }
        swap(q, next);
    }
    return head;
}