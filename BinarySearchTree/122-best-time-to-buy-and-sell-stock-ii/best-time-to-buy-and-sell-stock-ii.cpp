class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& prices, int buy, int i) {
        if (i >= prices.size()) {
            return 0;
        }
        if (dp[i][buy] != -1) {
            return dp[i][buy];
        }

        int profit = 0;
        if (buy==1) {
            int take = -prices[i]+solve(prices, 0, i + 1);
            int notake = solve(prices, 1, i + 1);
            profit = max(take, notake);
        } else {
            int take = prices[i] + solve(prices, 1, i + 1);
            int notake = solve(prices, 0, i + 1);
            profit = max(take, notake);
        }
        return dp[i][buy] = max(profit,0);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.assign(n + 1, vector<int>(2, -1));
        return solve(prices, 1, 0);
    }
};