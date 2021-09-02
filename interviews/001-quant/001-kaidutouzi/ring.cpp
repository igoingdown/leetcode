#include "ring.h"


void ring::get(size_t start, size_t n, unsigned char* dest){
    size_t end = start + n;
    start %= cap;
    end %= cap;
    if (start < end) {
        std::memcpy(dest, m_data + start, n);
    } else {
        // 读 2 次
        // 先读 start -> cap
        std::memcpy(dest, m_data + start, cap - start);

        // 再读 0 -> end
        std::memcpy(dest + cap - start, m_data + 0, end - 0);
    }
}

void ring::set(size_t start, size_t n, unsigned char *ptr) {
    size_t end = start + n;
    start %= cap;
    end %= cap;
    if (start < end) {
        // 写 start -> end
        std::memcpy(m_data + start, ptr, n);
    } else {
        // 写 2 次
        // 先写 start -> cap
        std::memcpy(m_data + start, ptr, n);

        // 再写 0 -> end
        std::memcpy(m_data + 0, ptr + cap - start,  end - 0);
    }
}

