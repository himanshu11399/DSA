class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, int& m, int& n) {
        if (i > m - 1 || j > n - 1)
            return 0;
        if (i == m - 1 && j == n - 1)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];

        // move down
        int down = solve(i + 1, j, m, n);

        // move right
        int right = solve(i, j + 1, m, n);

        return dp[i][j] = down + right;
    }

    int uniquePaths(int m, int n) {
        dp.assign(m + 1, vector<int>(n + 1, -1));
        return solve(0, 0, m, n);
    }
};