#include <iostream>
using namespace std;

struct Base {
    int x;
    Base(int v=0) : x(v) { cout << "Base(" << x << ") ctor\n"; }
};

struct Left : public Base {
    Left(int v=0) : Base(v) { cout << "Left ctor\n"; }
};

struct Right : public Base {
    Right(int v=0) : Base(v) { cout << "Right ctor\n"; }
};

struct MostDerived : public Left, public Right {
    MostDerived() {
        cout << "MostDerived ctor\n";
    }
};

int main() {
    MostDerived md;
    // md has TWO Base subobjects: Left::Base and Right::Base
    // md.x = 10; // Error: ambiguous
    cout << "md.Left::x = " << md.Left::x << "\n";
}