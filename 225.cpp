class MyStack {
private:
    deque<int> s;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        s.push_back(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res = s.back();
        s.pop_back();
        return res;
    }
    
    /** Get the top element. */
    int top() {
        return s.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return s.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */