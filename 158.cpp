class MinStack {
public:
    stack<int> s, min;
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if (min.empty() || min.top() >= x) min.push(x);
        s.push(x);
    }
    
    void pop() {
        if (min.top() == s.top()) min.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */