class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(vector<int>& prices, int idx, int buy, int limit) {
        if (idx >= prices.size() || limit == 0) {
            return 0;
        }
        if (dp[idx][buy][limit] != -1) {
            return dp[idx][buy][limit];
        }
        int profit = 0;
        if (buy == 1) {
            int take = -prices[idx] + solve(prices, idx + 1, 0, limit);
            int notake = solve(prices, idx + 1, 1, limit);
            profit = max(take, notake);
        } else {
            int take = prices[idx] + solve(prices, idx + 1, 1, limit-1);
            int notake = solve(prices, idx + 1, 0, limit);
            profit= max(take, notake);
        }
        return dp[idx][buy][limit] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.assign(prices.size()+1, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(prices, 0, 1, 2);
    }
};