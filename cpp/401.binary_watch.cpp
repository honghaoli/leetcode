class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        // hour has 0-3 bits
        // minute has 0-5 bits
        vector<string> result;
        if (num > 8 || num < 0) return result;
        // pre calculate
        vector<vector<int>> bits_number(6, vector<int>());
        for (int i = 0; i < 60; i++) {
            int count = count1s(i);
            bits_number[count].push_back(i);
        }
        // add all combinations
        for (int h = 0; h < 4; h++) {
            int m = num - h;
            if (m < 6 && m >= 0) {
                for (int hour : bits_number[h]) {
                    if (hour < 12)
                        for (int minute : bits_number[m]) {
                            result.push_back(convert(hour, minute));
                        }
                }
            }
        }
        return result;
    }

private:
    int count1s(int n) {
        int count = 0;
        for (int i = 0; i < 6; i++) {   // 6 is enough for 64
            if ((n >> i) & 1)
                count++;
        }
        return count;
    }

    string convert(int hour, int minute) {
        string result = to_string(hour);
        result += ":";
        if (minute < 10)
            result += "0";
        result += to_string(minute);
        return result;
    }
};