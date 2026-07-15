class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {1, 1}};
    int solve(vector<vector<char>>& matrix, int i, int j) {
        if (i >= matrix.size() || j >= matrix[0].size()) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int maxans = INT_MAX;
        for (auto it : dir) {
            int nrow = i + it[0];
            int ncol = j + it[1];
            if (nrow >= 0 && ncol >= 0 && nrow < matrix.size() && ncol < matrix[0].size() &&
                matrix[nrow][ncol] == '1') {
                maxans = min(maxans, solve(matrix, nrow, ncol));
            }else{
                maxans=min(maxans,0);
            }
        }
        if (maxans == INT_MAX) {
            maxans = 0;
        }
        return dp[i][j] = maxans + 1;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        dp.assign(n + 1, vector<int>(m + 1, -1));
        int maxans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    maxans = max(maxans, solve(matrix, i, j));
                }
            }
        }
        return maxans*maxans;
    }
};