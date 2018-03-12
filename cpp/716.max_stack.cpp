class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {
    }
    
    // O(log n), sort in map when adding new number;  O(1) for already exist number
    void push(int x) {
        nums.push_front(x);
        hash[x].push_back(nums.begin());
    }
    
    // O(1)
    int pop() {
        int tmp = nums.front();
        hash[tmp].pop_back();
        // this is very important since peekMax depends on the key 
        if (hash[tmp].size() == 0)
            hash.erase(tmp);
        nums.pop_front();
        return tmp;
    }
    
    // O(1)
    int top() {
        return nums.front();
    }
    
    // O(1)
    int peekMax() {
        return hash.rbegin()->first;
    }
    
    // O(1)
    int popMax() {
        int tmp = peekMax();

        auto iter = hash[tmp].back();
        nums.erase(iter);

        hash[tmp].pop_back();
        // this is very important since peekMax depends on the key 
        if (hash[tmp].size() == 0)
            hash.erase(tmp);

        return tmp;
    }

private:
    list<int> nums;
    map<int, vector<list<int>::iterator>> hash;
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