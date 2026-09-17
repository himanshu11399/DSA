class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& nums, int row, int col) {
        if (row == nums.size() - 1 && col == nums[0].size() - 1) {
            return nums[row][col];
        }
        if (row >= nums.size() || col >= nums[0].size()) {
            return INT_MAX;
        }
        if (dp[row][col] != -1) {
            return dp[row][col];
        }

        int take = solve(nums, row + 1, col);
        int notake = solve(nums, row, col + 1);
        int ans = min(take, notake);
        if (ans != INT_MAX) {
            ans += nums[row][col];
        }
        return dp[row][col] = ans;
    }
    int minPathSum(vector<vector<int>>& grid) {
        dp.assign(grid.size(), vector<int>(grid[0].size(), -1));
        return solve(grid, 0, 0);
    }
};