// solution 1
// greedy solution
// if arr[i] > i, it means this chunk's end is at least at index = arr[i];
// then we check arr[j] from i to index, see what is the really end of this chunk
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int start = 0, end = 0;
        int num = 0;
        while (end < arr.size()) {
            for (int i = start; i <= end; ++i) {
                end = max(end, arr[i]);
            }
            ++num;
            ++end;
            start = end;
        }
        return num;
    }
};

