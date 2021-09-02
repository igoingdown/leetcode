#pragma once
#include <vector>
 
class ring {
public:
    ring():cap(1024 * 10) {
        memset(m_data, 0, sizeof(unsigned char));
    };
	void get(size_t start, size_t n, unsigned char* dest); // 读数据，直接拷贝内存
	void set(size_t start, size_t n, unsigned char *src); // 写数据，直接进行内存操作
	size_t cap;
	unsigned char m_data[1024*10];
};
