class Solution {
public:
    /*
     * @param A: Given an integer array
     * @return: nothing
     */
    void heapify(vector<int> &A) {
        if (A.size() < 2) return;
        // from right to left, sink
        int i = (A.size() - 1) / 2;
        while (i >= 0) {
            sink(A, i);
            i--;
        }
    }
    
    
private:
    void sink(vector<int> &A, int i) {
        while (i*2 + 1 < A.size()) {
            int j = i*2 + 1;
            if (i*2 + 2 < A.size() && A[i*2 + 2] < A[j])
                j++;
            if (A[i] > A[j])
                swap(A[i], A[j]);
            i = j;
        }
    }
};