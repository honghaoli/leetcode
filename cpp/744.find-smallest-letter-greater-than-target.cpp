class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if (target < letters.at(0) || target >= letters.back()) return letters.at(0);
        int lo = 0, hi = letters.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (letters[mid] <= target) {
                lo = mid + 1;
            } else if (letters[mid] > target) {
                if (mid == 0 || letters[mid - 1] <= target)
                    return letters[mid];
                else
                    hi = mid - 1;
            }
        }
        // this line can be deleted.
        return letters.at(0);
    }
};
