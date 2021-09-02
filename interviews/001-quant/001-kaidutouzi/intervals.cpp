#include "intervals.h"


void intervals::insert(interval &newInterval){
    this->intervals_first_point = std::min(this->intervals_first_point, newInterval.start);
    this->intervals_last_point = std::max(this->intervals_last_point, newInterval.end);

    if (!head->next) {
        head->next = new interval_node(&newInterval);
        this->intervals_first_point = newInterval.start;
        this->intervals_last_point = newInterval.end;
        return;
    }

    if (head->next->val->start > newInterval.end)  {
        head->next = new interval_node(&newInterval);
        return;
    }

    if (head->next->val->start == newInterval.end)  {
        head->next->val->start = newInterval.start;
        return;
    }


    interval_node *pre = this->head->next;
    while (pre->next) {
        if (pre->next->val->start >= newInterval.end && pre->val->end <= newInterval.start) {
            break;
        }
        pre = pre->next;
    }

    if (!pre->next) {
        if (pre->val->end == newInterval.start) {
            pre->val->end = newInterval.end;
            return;
        }
        pre->next = new interval_node(&newInterval);
        return;
    }

    if (pre->val->end == newInterval.start && pre->next->val->start == newInterval.end) {
        pre->val->end = pre->next->val->end;
        interval_node *tmp = pre->next;
        pre->next = pre->next->next;
        delete tmp;
        return;
    }

    if (pre->val->end < newInterval.start && pre->next->val->start > newInterval.end) {
         interval_node *tmp = pre->next;
         pre->next = new interval_node(&newInterval);
         pre->next->next = tmp;
         return;
    }

    if (pre->val->end == newInterval.start) {
        pre->val->end = newInterval.end;
        return;
    }

    if (pre->next->val->start == newInterval.end) {
        pre->next->val->start = newInterval.start;
        return;
    }
}

interval* intervals::pop_front(){
    if (!this->head->next) {
        return NULL;
    }
    interval *result = this->head->next->val;
    this->head->next = this->head->next->next;
    return result;
}
