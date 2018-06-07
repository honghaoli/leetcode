class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> group;
        for (auto &s : strings) {
            string identifier = calculate_intervals(s);
            group[identifier].push_back(s);
        }
        //
        vector<vector<string>> result;
        for (auto iter = group.begin(); iter != group.end(); ++iter) {
            result.push_back(iter->second);
        }
        return result;
    }

private:
    // calculate distance between nearby char,
    // convert into string form:
    // abc  ==>  1-1-,  a and b is 1, b and c is 1
    // az   ==>  25-
    // adf  ==>  3-2-,
    string calculate_intervals(string &s) {
        string result;
        for (int i = 1; i < s.size(); ++i) {
            int dist = s[i] - s[i - 1];
            if (dist < 0) dist += 26;
            result += to_string(dist) + "-";
        }
        return result;
    }
};