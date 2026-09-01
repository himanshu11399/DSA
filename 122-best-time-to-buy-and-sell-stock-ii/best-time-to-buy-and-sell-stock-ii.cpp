class Solution {
public:
    int ans = INT_MIN;
    vector<vector<int>> dp;

    int solve(vector<int>&nums, int i, bool buy) {
        if (i >= nums.size()) {
            return 0;
        }
        if (dp[i][buy] != -1) {
            return dp[i][buy];
        }
        int profit = 0;
        if (buy) {
            int take = -nums[i] + solve(nums, i + 1, 0);
            int notake = solve(nums, i + 1, 1);
            profit = max(take, notake);
        } else {
            int take = nums[i] + solve(nums, i + 1, 1);
            int notake = solve(nums, i + 1, 0);
            profit = max(take, notake);
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.assign(n, vector<int>(2, -1));
        return solve(prices, 0, 1);
    }
};