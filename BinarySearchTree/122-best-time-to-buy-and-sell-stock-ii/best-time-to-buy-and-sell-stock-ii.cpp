class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& nums, int idx, int buy) {
        if (idx >= nums.size())
            return 0;

        if (dp[idx][buy] != -1) {
            return dp[idx][buy];
        }

        int take = 0;
        int notake = 0;

        if (buy == 1) {
            take = -nums[idx] + solve(nums, idx + 1, 0);
            notake = solve(nums, idx + 1, 1);
        } else {
            take = nums[idx] + solve(nums, idx + 1, 1);
            notake = solve(nums, idx + 1, 0);
        }

        return dp[idx][buy] = max(take, notake);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.assign(n + 1, vector<int>(2, -1));
        return solve(prices, 0, 1);
    }
};