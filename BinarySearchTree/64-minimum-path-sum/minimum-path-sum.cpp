class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& nums, int row, int col) {
        if (row >= nums.size() || col >= nums[0].size()) {
            return 1e9;
        }
        if (row == nums.size() - 1 && col == nums[0].size() - 1) {
            return nums[row][col];
        }
        if (dp[row][col] != -1) {
            return dp[row][col];
        }

        int right = solve(nums, row, col + 1);
        int bottom = solve(nums, row + 1, col);

        return dp[row][col] = min(right, bottom)+nums[row][col];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        dp.assign(n, vector<int>(m, -1));
        return solve(grid, 0, 0);
    }
};