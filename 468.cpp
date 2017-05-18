class Solution {
private:
    bool validIPv4(string &s) {
        if (!isdigit(s.back())) {
            return false;
        }
        stringstream ss(s);
        string buf;
        int count = 0;
        while (getline(ss, buf, '.')) {
            if (buf.size() == 0) {
                return false;
            }
            if ((buf[0] == '0' && buf.size() > 1) || buf.size() > 3) {
                return false;
            }
            for (auto c: buf) {
                if (!isdigit(c)) {
                    return false;
                }
            }
            int n = stoi(buf);
            if (n > 255 || n < 0) {
                return false;
            }
            count++;
        }
        return count == 4;
    }

    bool validIPv6(string &s) {
        if (s.back() == ':') {
            return false;
        }
        stringstream ss(s);
        int count = 0;
        string buf;
        while (getline(ss, buf, ':')) {
            if(buf.size() == 0 || buf.size() > 4) {
                return false;
            }
            for (auto c: buf) {
                c = tolower(c);
                if (!isalnum(c)) {
                    return false;
                } else if (!isdigit(c) && !(c <= 'f' && c >= 'a')) {
                    return false;
                }
            }
            count++;
        }
        return count == 8;
    }

public:
    string validIPAddress(string IP) {
        string res;
        if (IP.size() == 0) {
            return "Neither";
        }
        bool isv4 = false, isv6 = false;
        int firstDot = IP.find_first_of('.');
        int firstCol = IP.find_first_of(':');
        if (firstDot > 0) {
            isv4 = validIPv4(IP);
        } else if (firstCol > 0) {
            isv6 = validIPv6(IP);
        }
        if (!isv4 && !isv6) {
            res = "Neither";
        } else if (isv4) {
            res = "IPv4";
        } else {
            res = "IPv6";
        }
        return res;
    }
};
