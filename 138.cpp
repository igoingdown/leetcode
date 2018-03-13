/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return head;
        RandomListNode *new_head = new RandomListNode(head->label), *tmp = new_head;
        unordered_map<RandomListNode*, RandomListNode*> visit;
        visit[head] = new_head;
        while (head) {
            if (head->next) {
                if (visit.find(head->next) == visit.end()) {
                    tmp->next = new RandomListNode(head->next->label);
                    visit[head->next] = tmp->next;
                } else tmp->next = visit[head->next];
            }
            if (head->random) {
                if (visit.find(head->random) == visit.end()) {
                    tmp->random = new RandomListNode(head->random->label);
                    visit[head->random] = tmp->random;
                } else tmp->random = visit[head->random];
            }
            head = head->next; tmp = tmp->next;
        }
        return new_head;
    }
};