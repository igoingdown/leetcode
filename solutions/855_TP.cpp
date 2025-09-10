class ExamRoom {
private:
    set<int> s;
    int N;
public:
    ExamRoom(int n) {
        N = n;
    }
    
    int seat() {
        int res = 0, dis = 0;
        set<int>::iterator b = s.begin();
        for (auto b = s.begin(); b != s.end(); b++) {
            auto e = b;
            e++;
            if (e != s.end()) {
                int c = (*b + *e) / 2;
                if (c - *b > dis) {
                    dis = c - *b;
                    res = c;
                }
            } 
        }
        if (s.size() > 0 && *(s.begin()) >= dis) {
            res = 0; dis = *(s.begin());
        }
        auto e = s.end();
        if (s.size() > 0 && N - 1 - *(--e) > dis) {
            res = N - 1; dis = N - 1 - *e;
        }
        s.insert(res);
        return res;
    }
    
    void leave(int p) {
        s.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */