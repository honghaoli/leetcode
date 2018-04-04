
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // count all strings freq
        unordered_map<string, int> hash;
        for (int i = 0; i < words.size(); i++) {
            if (hash.count(words[i]) == 0) {
                hash[words[i]] = 1;
            } else {
                hash[words[i]]++;
            }
        }
        // priority queue, minHeap.
        auto cmp = [&hash](const string &s1, const string &s2) { 
            if (hash[s1] > hash[s2])
                return true; 
            else if (hash[s1] == hash[s2] && s1 < s2)
                return true;
            return false;
        };
        priority_queue<string, vector<string>, decltype(cmp)> pq(cmp);
        for (auto iter = hash.begin(); iter != hash.end(); iter++) {
            const string &s = iter->first;
            if (pq.size() < k) {
                pq.push(s);
            } else {
                if (cmp(s, pq.top())) {
                    pq.pop();
                    pq.push(s);
                }
            }
        }
        // result
        vector<string> result;
        while (!pq.empty()) {
            result.push_back(pq.top());
            pq.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};



