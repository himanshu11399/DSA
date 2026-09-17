class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& nums, int idx, int amount) {
        if (amount == 0)
            return 0;
        if (idx >= nums.size() || amount < 0)
            return INT_MAX;
        if (dp[idx][amount] != -1) {
            return dp[idx][amount];
        }
        int take = solve(nums, idx, amount - nums[idx]);
        if (take != INT_MAX) {
            take += 1;
        }
        int notake = solve(nums, idx + 1, amount);
        return dp[idx][amount] = min(take, notake);
    }
    int coinChange(vector<int>& nums, int amount) {
        dp.assign(nums.size() + 1, vector<int>(amount + 1, -1));
        int ans = solve(nums, 0, amount);
        return ans == INT_MAX ? -1 : ans;
    }
};