#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <algorithm>


using namespace std;
struct ComplexListNode {
    int val;
    ComplexListNode *next;
    ComplexListNode *sibling;
    ComplexListNode(int x):val(x), next(NULL), sibling(NULL){}
};

ComplexListNode *copyList(ComplexListNode *head);


int main() {
    ComplexListNode *head = new ComplexListNode(1);
    ComplexListNode *node2 = new ComplexListNode(2);
    ComplexListNode *node3 = new ComplexListNode(3);
    ComplexListNode *node4 = new ComplexListNode(4);
    ComplexListNode *node5 = new ComplexListNode(5);
    head->next = node2; head->sibling = node4;
    node2->next = node3; node2->sibling = head;
    node3->next = node4; node3->sibling = node5;
    node4->next = node5; node4->sibling = node2;
    node5->sibling = head;
    auto tmp = head;
    while (tmp) {
        cout << "val: " << tmp << "->" <<  tmp->val << " next: " << tmp->next << "->" << (tmp->next ? tmp->next->val : -1) << " sibling:  " << tmp->sibling << "->" << (tmp->sibling ? tmp->sibling->val : -1) << endl;
        tmp = tmp->next;
    }
    cout << endl;
    tmp = copyList(head);
    while (tmp) {
        cout << "val: " << tmp << "->" <<  tmp->val << " next: " << tmp->next << "->" << (tmp->next ? tmp->next->val : -1) << " sibling:  " << tmp->sibling << "->" << (tmp->sibling ? tmp->sibling->val : -1) << endl;
        tmp = tmp->next;
    }
    return 0;
}

ComplexListNode *copyList(ComplexListNode *head) {
    ComplexListNode *dummy = new ComplexListNode(0), *tmp = dummy;
    map<ComplexListNode *, ComplexListNode*> dict;
    dict[NULL] = NULL;
    while (head) {
        if (dict.find(head) == dict.end()) dict[head] = new ComplexListNode(head->val);
        ComplexListNode *head_copy = dict[head];
        if (head->next && dict.find(head->next) == dict.end()) dict[head->next] = new ComplexListNode(head->next->val);
        if (head->sibling && dict.find(head->sibling) == dict.end()) dict[head->sibling] = new ComplexListNode(head->sibling->val);
        head_copy->next = dict[head->next];
        head_copy->sibling = dict[head->sibling];
        tmp->next = head_copy;
        tmp = tmp->next;
        head = head->next;
    }
    return dummy->next;
}





