class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> result{};
        for (int i = 0; i < nums.size() - 3; i++) {
            int &ni = nums[i];
            if (ni >= 0 && ni > target) break;
            if (i > 0 && ni == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size() - 2; j++) {
                int &nj = nums[j];
                int tmp = ni + nj;
                if (nj >= 0 && tmp > target) break;
                if (j > i + 1 && nj == nums[j - 1]) continue;
                int p1 = j + 1, p2 = nums.size() - 1;
                while (p1 < p2) {
                    int &np1 = nums[p1], &np2 = nums[p2];
                    if (p1 > j + 1 && np1 == nums[p1 - 1]) {
                        p1++;
                        continue;
                    }
                    if (np1 + np2 == target - tmp) {
                        result.push_back({ni, nj, np1, np2});
                        p1++;
                    } else if (np1 + np2 < target - tmp) {
                        p1++;
                    } else { // np1 + np2 > target - tmp
                        p2--;
                    }
                }
            }
        }

        return result;
    }
};
