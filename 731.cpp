class MyCalendarTwo {
public:
    class MyCalendar{
    public:
        vector<pair<int, int>> books;
        MyCalendar() {}
        bool book(int s, int e) {
            for (auto p : books) {
                if (max(s, p.first) < min(e, p.second)) return false;
            }
            books.push_back({s, e});
            return true;
        }
    };
    
    vector<pair<int, int>> books;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        MyCalendar overlaps;
        for (auto p : books) {
            if (max(p.first, start) < min(p.second, end)) {
                if (!overlaps.book(max(p.first, start), min(p.second, end))) return false;
            }
        }
        books.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */