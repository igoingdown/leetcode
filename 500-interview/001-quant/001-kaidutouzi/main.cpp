#include <iostream>
#include "data_buffer.h"

int main() {
    data_buffer *b  = new(data_buffer);
    unsigned char str[] = "hello";
    b->put(str, 5, 2);
    unsigned char x[1025];
    b->get(x);
    std::cout << x << std::endl;
    return 0;
}
