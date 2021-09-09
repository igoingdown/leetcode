#include <iostream>

using namespace std;

template<typename T>
void log(T value) {
    cout << value << endl;
}

template<typename T, int N> 
class Array{
private:
    T m_Array[N];
public:
    int GetSize() const {
        return N;
    }
};

int main() {
    cout << "hello" << endl;
    Array<int,5> a;
    log<int>(4);
    log(a.GetSize());
}

