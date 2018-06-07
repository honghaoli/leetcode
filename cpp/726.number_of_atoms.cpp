class Solution {
public:
    string countOfAtoms(string formula) {
        string result;
        auto counts = count(formula, 0, formula.size() - 1);
        map<string, int> freq;      // sorted
        for (auto iter = counts.begin(); iter != counts.end(); ++iter) {
            freq.insert({iter->first, iter->second});
        }
        for (auto iter = freq.begin(); iter != freq.end(); ++iter) {
            result += iter->first;
            if (iter->second > 1)
                result += to_string(iter->second);
        }
        return result;
    }

private:
    unordered_map<string, int> count(string &formula, int i, int j) {
        unordered_map<string, int> freq;
        int left = 0;      // number of left brackets
        int left_pos = -1;
        int k = i;
        while (k <= j) {
            if (formula[k] == '(') {
                ++left;
                if (left_pos < 0) left_pos = k;
                ++k;
            } else if (formula[k] == ')') {
                --left;
                // if there is still left bracket, directly find the paired right one.
                if (left > 0) {
                    ++k;
                    continue;
                }
                // if this is the paired one
                auto counts = count(formula, left_pos + 1, k - 1);
                ++k;    // move to the one after bracket
                int num = next_num(formula, k);     // this will also update k to the one after the brackets number
                for (auto iter = counts.begin(); iter != counts.end(); ++iter) {
                    freq[iter->first] += iter->second * num;
                }
                left_pos = -1;      // IMPORTANT!!! reset the left bracket to none.
            } else if (left > 0) {
                // if there is left bracket, directly find the paired right one.
                ++k;
                continue;
            } else if (left == 0) {
                // there is no brackets, do the statistics
                string elem = next_element(formula, k);     // updated k
                int num = next_num(formula, k);     // updated k
                freq[elem] += num;
            }
        }
        return freq;
    }

    int next_num(string &formula, int &i) {
        int num = 0;
        while (formula[i] >= '0' && formula[i] <= '9') {
            num = num * 10 + formula[i] - '0';
            ++i;
        }
        if (num == 0) num = 1;      // if no number found, it is one
        return num;
    }

    string next_element(string &formula, int &i) {
        string elem;
        elem.push_back(formula[i++]);
        while (formula[i] >= 'a' && formula[i] <= 'z') {
            elem.push_back(formula[i++]);
        }
        return elem;
    }
};