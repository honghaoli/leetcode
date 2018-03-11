// this problem is in the Quant book
// the solution exist if total gas >= total cost
// The solution is:
// start with any index, set the tank to 0, then add the gas each time, and subtract the cost;
// the lowest value point, is the point where you should really start.
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.size() != cost.size()) return -1;
        int val = 0;
        int min_val = INT_MAX;
        int idx = 0;
        for (int i = 0; i < gas.size(); i++) {
            int tmp = gas[i] - cost[i];
            val += tmp;
            if (val < min_val) {
                min_val = val;
                idx = i;
            }
        }
        
        idx++;
        idx %= gas.size();

        if (val >= 0)
            return idx;
        else
            return -1;
    }
};
