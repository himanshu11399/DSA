class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& nums, int i, int j) {
        if (i >= nums.size() || j >= nums[0].size() || nums[i][j]==1) {
            return 0;
        }
        if (i == nums.size() - 1 && j == nums[0].size() - 1) {
            return 1;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int right = solve(nums, i, j + 1);
        int bottom = solve(nums, i + 1, j);

        return dp[i][j] = right + bottom;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        dp.assign(n, vector<int>(m, -1));
        return solve(nums, 0, 0);
    }
};