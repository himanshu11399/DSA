class Solution {
public:
    vector<int> dp;
    int solve(vector<int>& nums, int idx) {
        if (idx >= nums.size()) {
            return 0;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }
        int take = nums[idx] + solve(nums, idx + 2);
        int notake = solve(nums, idx + 1);
        return dp[idx] = max(take , notake);
    }
    int rob(vector<int>& nums) {
        dp.assign(nums.size(), -1);
        return solve(nums, 0);
    }
};