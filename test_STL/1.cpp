#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class C {
public:
    static int data;
};

//int C<int>::data = 1;
//int C<float>::data = 2;

template <typename T, typename O>
class C1 {
public:
    C1() {
        cout << "none" << endl;
    }
};

template <typename T>
class C1<T*, T*> {
public:
    C1() {
        cout << "specialization" << endl;
    }
};

int test_func(int) {
    cout << "param name is not important" << endl;
}

int main() {
    # if defined(__sgi)
        cout << "__sgi" << endl;
    # endif
    # if defined(__GNUC__)
        cout << "__GNUC__" << endl;
        cout << __GNUC__ << " " << __GNUC_MINOR__ << endl;
    //    cout << __GLIBC__ << endl;
    # endif
    
    # ifdef __STL_CLASS_PARTIAL_SPECIALIZATION
        cout << "partial specialization supported" << endl;
    # else
        cout << "partial specialization undefined" << endl;
    # endif
    
    //    cout << C<int>::data << " " << C<float>::data << endl;
    
    C1<int, char> x;
    C1<int*, int*> y;
    test_func(1);
    return 0;
}
