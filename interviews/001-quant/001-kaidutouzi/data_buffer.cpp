#include <iostream>
#include "data_buffer.h"


void data_buffer::get(unsigned char* dest) {
    // dest_index < front.begin return []
    if (!this->interval_list->head->next) {
        return;
    }
    if (this->interval_list->head->next->val->start > this->expected_seq_id) {
        return;
    }
            
    // else 读底层数据[front.begin, front.end)，更新 dest_index，更新 intervals
    auto aInterval = this->interval_list->pop_front();
    this->ring_buffer->get(aInterval->start,aInterval->end - aInterval->start, dest);
    this->expected_seq_id = aInterval->end + 1;
}

void data_buffer::put(unsigned char* str, size_t n, size_t seq_id){
    // 合法性校验
    if(seq_id + n <= this->expected_seq_id) {
        return;
    }
    if(seq_id <= this->expected_seq_id) {
        str += (this->expected_seq_id - seq_id);
    }

    // 写ring buffer
    this->ring_buffer->set(seq_id, n, str);

    // 更新 intervals
    interval x(seq_id, seq_id + n);
    this->interval_list->insert(x);

    // 更新 dest_index 
    this->expected_seq_id = std::min(this->interval_list->intervals_first_point, this->interval_list->intervals_first_point - 8 * 1024);
}
