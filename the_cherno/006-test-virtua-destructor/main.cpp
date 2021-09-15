#include <iostream>


class Base {
    public:
        Base() {std::cout << "base constructor\n";};
        ~Base() {std::cout << "base destructor\n";};
};


class BaseWithVirtualDestructor {
    public:
        BaseWithVirtualDestructor () {std::cout << "base with virtual constructor\n";};
        virtual ~BaseWithVirtualDestructor () {std::cout << "base with virtual destructor\n";};
};


class Derived : public Base, public BaseWithVirtualDestructor {
    public:
        Derived() {std::cout << "derived constructor\n";};
        ~Derived() {std::cout << "derived destructor\n";};
};


int main() {
    Base *b = new Base();
    delete b;
    std::cout << "----------------------\n";

    
    Derived *d = new Derived();
    delete d;
    std::cout << "----------------------\n";

    Base *p = new Derived();
    delete p;
    std::cout << "----------------------\n";

    BaseWithVirtualDestructor *p_v = new Derived();
    delete p_v; 
    std::cout << "----------------------\n";
}

