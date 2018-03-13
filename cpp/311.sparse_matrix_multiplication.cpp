class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int N = A.size();
        int K = A.at(0).size();
        int M = B.at(0).size();
        vector<vector<int>> rowA(N, vector<int>());
        vector<vector<int>> colB(M, vector<int>());
        // O(N * K) for A
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < K; j++) {
                if (A[i][j] != 0)
                    rowA[i].push_back(j);
            }
        }
        // O(K * M) for B
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < M; j++) {
                if (A[i][j] != 0)
                    colB[j].push_back(i);
            }
        }
        // A*B  is  N * M size
        vector<vector<int>> result(N, vector<int>(M, 0));
        // multiplication
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int ka = 0, kb = 0;
                int sum = 0;
                while (ka < rowA[i].size() && kb < colB[j].size()) {
                    if (rowA[i][ka] == colB[j][kb]) {
                        int k = rowA[i][ka];
                        sum += A[i][k] * B[k][m];
                        ka++;
                        kb++;
                    } else if (rowA[i][ka] > colB[j][kb]) {
                        kb++;
                    } else if (rowA[i][ka] < colB[j][kb]) {
                        ka++;
                    }
                }
                result[i][j] = sum;
            }
        }
    }
};