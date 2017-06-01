#include <iostream>
#include <vector>
#include <string>

using namespace std;

void restoreIpAddresses(vector<string>& res, string can, int idx, int count, string& ip);
vector<string> restoreIpAddresses(string s);

int main(void) {
  string s("0000");
  vector<string> res = restoreIpAddresses(s);
  for (auto s: res) {
    cout << s << endl;
  }
  return 0;
}

void restoreIpAddresses(vector<string>& res, string can, int idx, int count, string& ip) {
    if (count > 4) {
        return;
    }
    if (count == 4 && idx == ip.size()) {
        res.push_back(can);
    }
    for (int i = 1; i < 4; i++) {
        if (idx + i > ip.size()) {
            break;
        }
        string temp = ip.substr(idx, i);
        if ((temp.size() > 1 && temp[0] == '0') || (temp.size() == 3 && stoi(temp) > 255)) {
            continue;
        }
        restoreIpAddresses(res, can + temp + (count == 3 ? "" : "."), idx + i, count + 1, ip);
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    restoreIpAddresses(res, "", 0, 0, s);
    return res;
}
