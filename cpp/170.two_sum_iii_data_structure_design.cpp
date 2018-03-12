class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        if (hash.count(number) == 0)
            hash[number] = 1;
        else
            hash[number]++;
        nums.push_back(number);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (auto &n : nums) {
            if (hash.count(value - n) > 0) 
                if (value != 2 * n)
                    return true;
                else if (hash[n] > 1)
                    return true;
        }
        return false;
    }
    
private:
    unordered_map<int, int> hash;
    vector<int> nums;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */