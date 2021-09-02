#pragma once
#include "ring.h"
#include "intervals.h"

class data_buffer {
public:
    data_buffer(){
        ring_buffer = new(ring);
        interval_list = new(intervals);
    };
    void get(unsigned char* ptr);
    void put(unsigned char* str, size_t n, size_t seq_id);
private:
    size_t expected_seq_id;
    ring *ring_buffer;  
    intervals *interval_list;
};
