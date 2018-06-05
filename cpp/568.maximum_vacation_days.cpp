// DP
// totals[i][j]: at week j, ending staying at city i, what is the max vacation days.
class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int N = flights.size();
        int K = days.at(0).size();
        vector<vector<int>> totals(N, vector<int>(2, 0));

        // first week
        for (int n = 0; n < N; ++n ) {
            totals[n][0] = days[n][0];
            if (flights[0][n] == 0 && n != 0) {
                totals[n][0] = -1;      // -1 means this point is unaccessable.
            }
        }
        //
        int max_days = 0;
        for (int i = 1; i < K; ++i) {
            // for each week
            for (int k = 0; k < N; ++k) {
                // for each ending city
                int day = -1;
                for (int n = 0; n < N; ++n) {
                    // from each other city
                    if ((totals[n][(i - 1) % 2] >= 0 && flights[n][k] == 1) || n == k) {
                        day = max(day, totals[n][(i - 1) % 2]);
                    }
                }
                if (day < 0) 
                    totals[k][i % 2] = -1;
                else
                    totals[k][i % 2] = day + days[k][i];
                max_days = max(max_days, totals[k][i % 2]);
                // cout << totals[k][i % 2] << ", ";
            }
            // cout << endl;
        }
        return max_days;
    }
};