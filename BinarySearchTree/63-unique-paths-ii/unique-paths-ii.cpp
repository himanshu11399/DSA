class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& nums, int row, int col) {
        if (row == nums.size() - 1 && col == nums[0].size() - 1 && nums[row][col]==0) {
            return 1;
        }
        if (row >= nums.size() || col >= nums[0].size() ||
            nums[row][col] == 1) {
            return 0;
        }
        if (dp[row][col] != -1) {
            return dp[row][col];
        }
        int down = solve(nums, row + 1, col);
        int right = solve(nums, row, col + 1);
        return dp[row][col] =down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        dp.assign(n + 1, vector<int>(m + 1, -1));
        return solve(nums, 0, 0);
    }
};