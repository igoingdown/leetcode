#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(void) {
    string s("2001:0db8:85a3:0:0:8A2E:0370:7334:");
    stringstream ss(s);
    string buf;
    int count = 0;
    while (getline(ss, buf, ':')) {
        cout << ++count << endl;
        cout << buf.size() << "\t" << buf << endl;
    }
    return 0;
}
