struct MyPoint {
    int val, i, j;
    MyPoint(int val, int i, int j) : val(val), i(i), j(j) {}
};


// solution 1
// priority queue, has max n elements (diagonal)
// time O(k * log n)
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        auto compare = [](MyPoint &p1, MyPoint &p2) { return p1.val > p2.val; };
        priority_queue<MyPoint, vector<MyPoint>, decltype(compare)> pq(compare);
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = true;
        pq.push(MyPoint(matrix[0][0], 0, 0));
        while (--k > 0) {
            MyPoint p = pq.top();
            pq.pop();
            if (p.i < n - 1 && !visited[p.i + 1][p.j]) {
                visited[p.i + 1][p.j] = true;
                pq.push(MyPoint(matrix[p.i + 1][p.j], p.i + 1, p.j));
            }
            if (p.j < n - 1 && !visited[p.i][p.j + 1]) {
                visited[p.i][p.j + 1] = true;
                pq.push(MyPoint(matrix[p.i][p.j + 1], p.i, p.j + 1));
            }
        }

        return pq.top().val;
    }
};


// slightly improved version, 
// at first add a whole row into the priority queue, without visited matrix
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        auto compare = [](MyPoint &p1, MyPoint &p2) { return p1.val > p2.val; };
        priority_queue<MyPoint, vector<MyPoint>, decltype(compare)> pq(compare);

        for (int i = 0; i < n; i++)
            pq.push(MyPoint(matrix[i][0], i, 0));

        while (--k > 0) {
            MyPoint p = pq.top();
            pq.pop();
            if (p.j < n - 1) {
                pq.push(MyPoint(matrix[p.i][p.j + 1], p.i, p.j + 1));
            }
        }

        return pq.top().val;
    }
};