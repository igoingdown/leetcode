class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int, vector<int>, less<int>> max_heap;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (max_heap.empty()) {
            max_heap.push(num);
        } else {
            if (num <= max_heap.top()) {
                if (max_heap.size() == min_heap.size()) {
                    max_heap.push(num);
                } else {
                    min_heap.push(max_heap.top());
                    max_heap.pop();
                    max_heap.push(num);
                }
            } else {
                if (max_heap.size() == min_heap.size()) {
                    min_heap.push(num);
                    max_heap.push(min_heap.top());
                    min_heap.pop();
                } else {
                    min_heap.push(num);
                }
            }
        }
    }
    
    double findMedian() {
        if (max_heap.size() != min_heap.size()) return (int)max_heap.top();
        else return (max_heap.top() + min_heap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */