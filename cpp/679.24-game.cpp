// A straightforward recursive method
// This method can be easily extended to input array larger than 4, or extra operators.

// Key idea:
// Given an array of numbers, we remove two numbers a and b, calculate the possible outcome number ( operator(a, b) );
// make a new array containing all the rest numbers and the new outcome number.
// then recursively solve the sub-problem.
// each time, the array size would decrease by 1, since we remove two numbers and insert back one.
// So eventually, there will be only one number in the array, then we compare this number to target.
// If this number == target, then we can find a way to calculate the target
// If all the possible outcome single-number-array != target, we cannot find a way.

// Complexity:
// suppose we have an array with N numbers.
// Each step, we select two numbers, which ~O(N^2) possibilities.
// for each pair, we can generate K outcomes, ( for + - * /, roughly K = 4 ~ 6, see all_op() function)
// So after the first step, we have O(N^2 * K) arrays with size N - 1
// For each of them, we would generate another O( (N-1) ^ 2 * K) arrays.
// It increases exponentially!!!   ~ O(2 ^ (K * N^2))
// Both for time and space, so this can not be used to tackle large array input.

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> values;
        for (int n : nums)
            values.push_back(n * 1.0);
        return isPossible(values, 24.0);
    }

private:
    // is it possible for a vector of values to make the target value?
    bool isPossible(vector<double> &values, double target) {
        if (values.size() == 1) return compare(values[0], target);
        for (size_t i = 0; i < values.size(); ++i) {
            for (size_t j = i + 1; j < values.size(); ++j) {
                for (double input : all_op(values[i], values[j])) {
                    vector<double> new_values = newVector(values, i, j, input);
                    if (isPossible(new_values, target)) return true;
                }
            }
        }
        return false;
    }

    // get new vector copied from values, but delete ith and jth values, insert all combination of op(a, b) as the new input;
    vector<double> newVector(vector<double> &values, int i, int j, double input) {
        vector<double> result;
        for (int k = 0; k < values.size(); ++k) {
            if (k == i || k == j) continue;
            result.push_back(values[k]);
        }
        result.push_back(input);
        return result;
    }

    // all result by operation between two values.
    vector<double> all_op(double d1, double d2) {
        vector<double> result{d1 + d2, d1 - d2, d2 - d1, d1 * d2};
        if (!compare(d1, 0))
            result.push_back(d2 / d1);
        if (!compare(d2, 0))
            result.push_back(d1 / d2);
        return result;
    }

    const double Error = 1E-6;

    bool compare(double d1, double d2) {
        if (abs(d1 - d2) < Error) return true;
        return false;
    }
};
