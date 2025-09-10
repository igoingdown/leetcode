#include <iostream>
#include <string>
#include <vector>


using namespace std;


string convert(string s, int numRows);


int main(void) {
    string s = "AB";
    cout << convert(s, 1) << endl;
    return 0;
}




string convert(string s, int numRows) {
    if (numRows == 1) {
        return s;
    }
    vector<string> vec(numRows, "");
    for (int i = 0; i * (numRows * 2 - 2) < s.size(); i++) {
        cout << i << endl;
        if (i > 30) {
            break;
        }
        int start = i * (numRows * 2 - 2);
        int tempSize = 0;
        if (s.size() >= (i + 1) * (numRows * 2 - 2) ) {
            tempSize = numRows * 2 - 2;
        } else {
            tempSize = s.size() - start;
        }
        for (int j = 0; j < numRows && j < tempSize; j++) {
            vec[j] += s[start + j];
            cout << "bb" << endl;
        }
        for (int j = 0; j + numRows < tempSize; j++) {
            vec[numRows - 2 - j] += s[start + j + numRows];
            cout << "cc" << endl;
        }
    }
    string res;
    for (auto str: vec) {
        res += str;
    }
    return res;
}