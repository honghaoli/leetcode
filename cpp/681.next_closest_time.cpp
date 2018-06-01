// simulation method, time = 24 * 60
class Solution {
public:
    string nextClosestTime(string time) {
        int minute = stoi(time.substr(3, 2));
        int hour = stoi(time.substr(0, 2));
        digits = getDigits(time);

        for (int i = 1; i <= 24 * 60; ++i) {
            vector<int> new_time = getTime(hour, minute, i);
            if (containAllDigits(new_time))
                return buildString(new_time);
        }
        // should never happen.
        return "";
    }

private:
    unordered_set<int> digits;

    unordered_set<int> getDigits(string &time) {
        unordered_set<int> digits;
        for (int i : {0, 1, 3, 4}) {
            digits.insert(time[i] - '0');
        }
        return digits;
    }

    bool containAllDigits(vector<int> nums) {
        for (int n : nums) {
            if (digits.count(n / 10) == 0) return false;
            if (digits.count(n % 10) == 0) return false;
        }
        return true;
    }

    vector<int> getTime(int hour, int minute, int interval) {
        hour += interval / 60;
        minute += interval % 60;
        if (minute >= 60) {
            minute -= 60;
            hour++;
        }
        hour %= 24;
        return {hour, minute};
    }

    string buildString(vector<int> &time) {
        int hour = time[0];
        int minute = time[1];
        string result;
        if (hour < 10) 
            result += "0";
        result += to_string(hour);
        result += ":";
        if (minute < 10) 
            result += "0";
        result += to_string(minute);
        return result;
    }

};




// clean logic but dirty implementation

// class Solution {
// public:
//     string nextClosestTime(string time) {
//         int minute = stoi(time.substr(3, 2));
//         int hour = stoi(time.substr(0, 2));

//         vector<int> digits = getDigits(time);

//         int next_minute = nextMinute(minute, digits);
//         if (next_minute <= minute) {
//             hour = nextHour(hour, digits);
//         }

//         return buildString(hour, next_minute);
//     }

// private:
//     // get all the digits into an vector, sorted
//     vector<int> getDigits(string &time) {
//         const int N = 10;
//         vector<int> freq(N, 0);
//         for (int i : {0, 1, 3, 4}) {
//             int d = time[i] - '0';
//             freq[d]++;
//         }
//         vector<int> digits;
//         for (int i = 0; i < N; ++i)
//             if (freq[i] != 0) 
//                 digits.push_back(i);
//         return digits;
//     }

//     int nextMinute(int minute, vector<int> &digits) {
//         // 0X
//         auto iter = upper_bound(digits.begin(), digits.end(), minute % 10);
//         if (iter != digits.end()) {
//             return (minute / 10) * 10 + *iter;
//         }
//         // X0, largest value is 5!
//         iter = upper_bound(digits.begin(), digits.end(), minute / 10);
//         if (iter != digits.end() && (*iter) <= 5) {
//             return (*iter) * 10 + digits.at(0); 
//         }
//         return 11 * digits.at(0);       // all smallest digits 
//     }

//     int nextHour(int hour, vector<int> &digits) {
//         // d1 d2 :
//         int d1 = hour / 10;     // can only be 0, 1, 2
//         int d2 = hour % 10;     // can only be 0 ~ 3 if d1 == 2
//         if (d1 < 2) {
//             auto iter = upper_bound(digits.begin(), digits.end(), d2);
//             if (iter != digits.end()) {
//                 return d1 * 10 + *iter;
//             }
//             iter = upper_bound(digits.begin(), digits.end(), d1);
//             if (iter != digits.end() && (*iter) <= 2) {
//                 return (*iter) * 10 + digits.at(0); 
//             }
//             return 11 * digits.at(0);
//         } else {
//             auto iter = upper_bound(digits.begin(), digits.end(), d2);
//             if (iter != digits.end() && (*iter) <= 3) {
//                 return d1 * 10 + *iter;
//             }
//             return 11 * digits.at(0);
//         }
//     }

//     string buildString(int hour, int minute) {
//         string result;
//         if (hour < 10) 
//             result += "0";
//         result += to_string(hour);
//         result += ":";
//         if (minute < 10) 
//             result += "0";
//         result += to_string(minute);
//         return result;
//     }
// };