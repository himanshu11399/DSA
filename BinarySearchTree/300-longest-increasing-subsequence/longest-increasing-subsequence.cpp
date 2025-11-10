class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int prev, vector<int>& nums) {
        if (i >= nums.size())
            return 0;
        if (dp[i][prev+1] != -1)
            return dp[i][prev+1];
        // Take
        int take = 0;
        if (prev == -1 || nums[i] > nums[prev]) {
            take = 1 + solve(i + 1, i, nums);
        }
        int notake = solve(i + 1, prev, nums);
        return dp[i][prev+1] = max(take, notake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n + 1, vector<int>(n + 1, -1));
        return solve(0, -1, nums);
    }
};