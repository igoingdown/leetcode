class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int b = 0, e = 0, n = seats.size(), res = 1;
        while (seats[b] == 1) b++;
        e = b;
        while (b < n) {
            while (e < n && seats[e] == 0) e++;
            if (b == 0 || e == n) res = max(e - b, res);
            else res = max(res, (e - b + 1) / 2);
            while (e < n && seats[e] == 1) e++;
            b = e;
        }
        return res;
    }
};