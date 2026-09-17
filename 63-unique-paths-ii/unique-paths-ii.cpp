class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& nums, int row, int col) {
        if (row == nums.size() - 1 && col == nums[0].size() - 1) {
            return 1;
        }
        if (row >= nums.size() || col >= nums[0].size() ||
            nums[row][col] == 1) {
            return 0;
        }
        if (dp[row][col] != -1)
            return dp[row][col];

        int take = solve(nums, row + 1, col);
        int notake = solve(nums, row, col + 1);

        return dp[row][col] = take + notake;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        if (nums[0][0] == 1 || nums[n - 1][m - 1] == 1) {
            return 0;
        }
        dp.assign(n + 1, vector<int>(m + 1, -1));
        return solve(nums, 0, 0);
    }
};