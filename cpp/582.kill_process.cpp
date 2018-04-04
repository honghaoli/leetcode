class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        // store parent, children hashmap
        unordered_map<int, vector<int>> children;
        for (int i = 0; i < pid.size(); i++) {
            if (children.count(ppid[i]) == 0) {
                children[ppid[i]] = vector<int>{pid[i]};
            } else {
                children[ppid[i]].push_back(pid[i]);
            }
        }
        // find all the children
        vector<int> kills;
        queue<int> toKill;
        toKill.push(kill);
        while (!toKill.empty()) {
            int k = toKill.front();
            toKill.pop();
            kills.push_back(k);
            for (auto &i : children[k])
                toKill.push(i);
        }
        return kills;
    }
};