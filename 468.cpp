#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string validIPAddress(string IP);

int main(int argc, char const *argv[]) {
  /* code */
  string s("1.1.1.01");
  cout << validIPAddress(s) << endl;
  return 0;
}


string validIPAddress(string IP) {
    int dotCount = count(IP.begin(), IP.end(), '.');
    int echoCount = count(IP.begin(), IP.end(), ':');
    if (dotCount > 0) {
        if (dotCount != 3) {
            return "Neither";
        }
        int begin = 0, end = IP.find(".", 0, 1);
        while (end != string::npos) {
          cout << begin << " " << end << endl;
          // cout << begin << endl;
            if (end - begin > 3 || end - begin == 0) {
                return "Neither";
            }
            for (int i = begin; i < end; i++) {
                if (IP[i] < '0' || IP[i] > '9') {
                    return "Neither";
                }
            }
            int num = stoi(IP.substr(begin, end - begin));
            int len = to_string(num).size();
            printf("len: %d\n", len);
            if (num > 255 || num < 0 || len < end - begin) {
                return "Neither";
            }
            begin = end + 1;
            if (begin == IP.size()) {
              return "Neither";
            }
            end = IP.find(".", end + 1, 1);
        }
        end = IP.size();
        if (end - begin > 3 || end - begin == 0) {
            return "Neither";
        }
        for (int i = begin; i < end; i++) {
            if (IP[i] < '0' || IP[i] > '9') {
                return "Neither";
            }
        }
        int num = stoi(IP.substr(begin, end - begin));
        int len = to_string(num).size();
        printf("len: %d\n", len);
        if (num > 255 || num < 0 || len < end - begin) {
            return "Neither";
        }
        return "IPv4";

    } else if (echoCount > 0) {
        if (echoCount < 7) {
            if (IP.find("::", 0, 2) != string::npos) {
                int begin = 0, end = IP.find(":", 0, 1);
                while (end != string::npos) {
                    if (end - begin > 4) {
                        return "Neither";
                    }
                    begin = end + 1;
                    end = IP.find(":", end + 1, 1);
                }
                return "IPv6";
            } else {
                return "Neither";
            }
        } else if (echoCount == 7) {
            int begin = 0, end = IP.find(":", 0, 1);
            while (end != string::npos) {
                if (end - begin > 4) {
                    return "Neither";
                }
                begin = end + 1;
                end = IP.find(":", end + 1, 1);
            }
            return "IPv6";
        } else {
            return "Neither";
        }
    } else {
        return "Neither";
    }
}
