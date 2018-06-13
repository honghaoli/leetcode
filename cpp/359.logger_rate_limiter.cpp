class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if (times.count(message) != 0) {
            int last_time = times[message];
            if (timestamp - last_time >= 10) {
                times[message] = timestamp;
                return true;
            } else {
                return false;
            }
        } else {
            times[message] = timestamp;
            return true;
        }
    }

private:
    unordered_map<string, int> times;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */