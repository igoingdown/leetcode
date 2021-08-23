#include <iostream>
#include <limits>

using namespace std;


int main() {
    cout << "\t最大值：" << (numeric_limits<unsigned int>::max)();
    cout << "\t\t最小值：" << (numeric_limits<unsigned int>::min)() << endl;
    return 0;
}

