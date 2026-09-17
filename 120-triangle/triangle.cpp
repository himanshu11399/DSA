class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& nums, int row, int col) {
        if (row >= nums.size()) {
            return 0;
        }
        if (dp[row][col] != INT_MIN) {
            return dp[row][col];
        }

        // same
        int take = solve(nums, row + 1, col);
        // diff
        int notake = solve(nums, row + 1, col + 1);
        return dp[row][col] = min(take, notake) + nums[row][col];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        dp.assign(triangle.size()+1, vector<int>(triangle.size()+1,INT_MIN));
        return solve(triangle, 0, 0);
    }
};