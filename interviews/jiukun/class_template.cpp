#include <iostream>
using namespace std;

#define ATTRIBUTE(name, type) \
    private:\
        type name##_;  \
    public:\
        bool has_##name() {return true;} 

// has(name) {
// return name_is_in_fields
// }


template <typename T>
class Foo {
    ATTRIBUTE(bar, T)
};


int main() {
    Foo<int> foo;
    cout << foo.has_bar() << endl;
    return 0;
}
