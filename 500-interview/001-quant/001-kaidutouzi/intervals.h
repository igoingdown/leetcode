#pragma once
#include<vector>



class interval{
public:
    interval(){};
    interval(size_t s,size_t e):start(s), end(e){};
    size_t start, end;
};


class interval_node{
public:
    interval_node():val(NULL), next(NULL){};
    interval_node(interval *ptr):val(ptr), next(NULL){};
    interval *val;
    interval_node *next;
};

 
class intervals{
public:
    intervals(){
        head = new(interval_node);
    };
    void insert(interval &i);
    interval* pop_front();
    interval_node *head;
    size_t intervals_first_point, intervals_last_point;
};
