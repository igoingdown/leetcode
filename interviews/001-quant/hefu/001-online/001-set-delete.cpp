#include <iostream>
#include <set>

using namespace std;

void delete_set_num(set<int> &numbers) {
    auto iter = numbers.begin();
    while (iter == numbers.begin() && ((*iter) % 5) == 1) {
        numbers.erase(iter);
        iter = numbers.begin();
    }
    while (iter != numbers.end()) {
        if ((*iter) % 5 == 1) {
            auto tmp = iter;
            iter--;
            numbers.erase(tmp);
        }
        iter++;
    }
}

int main() {
    set<int> s;
    for(int i = 1; i < 10000; i++)  {
        s.insert(i);
    }
    delete_set_num(s);
    for (auto iter = s.begin(); iter != s.end(); iter++) {
        if ((*iter) % 5 == 1) {
            cout << "NO" << endl;
            return 0;
        } else {
            cout << *iter << "\t";
        }
    }
    cout << endl;
    cout << "YES" << endl;
    return 0;
}
