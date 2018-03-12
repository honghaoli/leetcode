class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {
    }
    
    void push(int x) {
        nums.push(x);
        addMax(x);
    }
    
    int pop() {
        int tmp = top();
        nums.pop();
        maxs.pop();
        return tmp;
    }
    
    int top() {
        return nums.top();
    }
    
    int peekMax() {
        return maxs.top();
    }
    
    int popMax() {
        int tmp = peekMax();
        maxs.pop();

        stack<int> t;
        while (nums.top() != tmp) {
            t.push(nums.top());
            nums.pop();
            maxs.pop();
        }
        nums.pop();
        while (!t.empty()) {
            nums.push(t.top());
            addMax(t.top());
            t.pop();
        }

        return tmp; 
    }

private:
    stack<int> nums;
    stack<int> maxs;

    void addMax(int x) {
        if (maxs.empty() || maxs.top() < x)
            maxs.push(x);
        else
            maxs.push(maxs.top());
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */