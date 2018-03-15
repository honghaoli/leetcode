class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) return tasks.size();
        int const C = 26;
        vector<int> freq(C, 0);
        for (char &c : tasks) {
            freq[c - 'A']++;
        }
        sort(freq.rbegin(), freq.rend());
        int max_ = freq[0];
        int num_max = 1;
        while (num_max < C && freq[num_max] == max_)
            num_max++;
        
        int size = tasks.size();
        return max(size, (max_ - 1) * (n + 1) + num_max);
    }
};
