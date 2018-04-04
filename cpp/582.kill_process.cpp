class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        // store parent, children hashmap
        for (int i = 0; i < pid.size(); i++) {
            if (children.count(ppid[i]) == 0) {
                children[ppid[i]] = vector<int>{pid[i]};
            } else {
                children[ppid[i]].push_back(pid[i]);
            }
        }
        // find all the children
        unordered_set<int> kills;
        stack<int> toKill;
        toKill.push(kill);
        while (!toKill.empty()) {
            int k = toKill.top();
            toKill.pop();
            if (kills.count(k) == 0)
                kills.insert(k);
            for (auto &i : children[k])
                toKill.push(i);
        }
        // convert to vector
        vector<int> result;
        for (auto iter = kills.begin(); iter != kills.end(); iter++) {
            result.push_back(*iter);
        }
        return result;
    }

private:
    unordered_map<int, vector<int>> children;
};