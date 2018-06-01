// O(NlogN) time, O(N) extra space
// Key idea:
// Use merge sort, count the number of inversion during the sort process.
// ref:
// https://www.cs.princeton.edu/~wayne/kleinberg-tardos/pdf/05DivideAndConquerI.pdf (Page 20)
// https://www.geeksforgeeks.org/counting-inversions/ 
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();

        aux = vector<pair<int, int>>(n, {0, 0});      // aux array for merge sort extra space
        arr = vector<pair<int, int>>(n, {0, 0});      // duplicate nums with index
        for (int i = 0; i < n; i++) {
            arr[i] = {i, nums[i]};                  // (index, value) pair
        }

        counts = vector<int>(n, 0);                   
        sort(arr, 0, n - 1);
        return counts;
    }

private:
    vector<pair<int, int>> aux;
    vector<pair<int, int>> arr;
    vector<int> counts;

    void sort(vector<pair<int, int>> &arr, int lo, int hi) {
        if (hi <= lo) return;
        int mid = (hi - lo) / 2 + lo;
        sort(arr, lo, mid);
        sort(arr, mid + 1, hi);
        merge(arr, lo, mid, hi);
    }

    void merge(vector<pair<int, int>> &arr, int lo, int mid, int hi) {
        // copy to aux array
        for (int k = lo; k <= hi; k++)
            aux[k] = arr[k];
        int i = lo, j = mid + 1;
        for (int k = lo; k <= hi; k++) {
            if (i > mid) {
                arr[k] = aux[j++];
            } else if (j > hi) {
                counts[aux[i].first] += j - 1 - mid;       // everytime add a[i], the inversion number for a[i] is the number of pre used numbers in b array.
                arr[k] = aux[i++];
            } else if (aux[i].second <= aux[j].second) {
                counts[aux[i].first] += j - 1 - mid;
                arr[k] = aux[i++];
            } else {
                arr[k] = aux[j++];
            }
        }
    }
};


