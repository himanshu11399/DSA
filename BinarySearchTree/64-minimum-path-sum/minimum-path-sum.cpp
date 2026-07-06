class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& grid, int row, int col) {
        if (row == grid.size() - 1 && col == grid[0].size() - 1) {
            return grid[row][col];
        }
        if (row >= grid.size() || col >= grid[0].size()) {
            return INT_MAX;
        }
        if (dp[row][col] != -1) {
            return dp[row][col];
        }
        int down = solve(grid, row + 1, col);
        int right = solve(grid, row, col + 1);
        return dp[row][col] = min(down, right) + grid[row][col];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        dp.assign(n + 1, vector<int>(m + 1, -1));
        return solve(grid, 0, 0);
    }
};