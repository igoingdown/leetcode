//
//  main.cpp
//  138
//
//  Created by 赵明星 on 2017/3/28.
//  Copyright © 2017年 赵明星. All rights reserved.
//

#include <iostream>
#include <unordered_map>


using namespace std;


struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode *copyRandomList(RandomListNode *head);

int main(int argc, const char * argv[]) {
    // insert code here...
    RandomListNode * head = new RandomListNode(-1);
    head->next = new RandomListNode(-1);
    head->random = NULL;
    RandomListNode *h = copyRandomList(head);
    std::cout << "Hello, World!\n";
    return 0;
}

RandomListNode *copyRandomList(RandomListNode *head) {
    if (!head) {
        return NULL;
    }
    RandomListNode *tmp = head;
    RandomListNode *h = new RandomListNode(head->label);
    RandomListNode *th = h;
    unordered_map<RandomListNode*, RandomListNode*> visited;
    while (tmp) {
        cout << tmp->label << endl;
        if (tmp->next) {
            if (visited.find(tmp->next) == visited.end()) {
                th->next = new RandomListNode(tmp->next->label);
                visited[tmp->next] = th->next;
            } else {
                th->next = visited[tmp->next];
            }
        }
        if (tmp->random) {
            if (visited.find(tmp->random) == visited.end()) {
                th->random = new RandomListNode(tmp->random->label);
                visited[tmp->random] = th->random;
            } else {
                th->random = visited[tmp->random];
            }
        }
        tmp = tmp->next;
        th = th->next;
    }
    return h;
}
