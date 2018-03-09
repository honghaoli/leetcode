class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        items.push(x);
        if (mins.empty() || x <= mins.top())
            mins.push(x);
    }
    
    void pop() {
        if (items.top() == mins.top())
            mins.pop();
        items.pop();
    }
    
    int top() {
        return items.top();
    }
    
    int getMin() {
        return mins.top();
    }

private:
    stack<int> items;
    stack<int> mins;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
