#include <iostream>

namespace apple {
    namespace functions {
        void log(int a) {
            std::cout << a << std::endl;
        }
    }
} 


int main() {
    apple::functions::log(1);
    namespace a = apple::functions;
    a::log(3);
}

