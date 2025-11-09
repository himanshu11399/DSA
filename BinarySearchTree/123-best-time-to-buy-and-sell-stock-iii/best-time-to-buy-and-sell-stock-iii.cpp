class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(int i, int buy, vector<int>& prices, int limit) {
        if (i >= prices.size() || limit <= 0)
            return 0;
        if (dp[i][buy][limit] != -1)
            return dp[i][buy][limit];

        int profit = 0;
        if (buy) {
            int buyStock = -prices[i] + solve(i + 1, 0, prices, limit);
            int ignorebuy = solve(i + 1, 1, prices, limit);
            profit = max(buyStock, ignorebuy);
        } else {
            int sellStock = +prices[i] + solve(i + 1, 1, prices, limit - 1);
            int ignoresell = solve(i + 1, 0, prices, limit);
            profit = max(sellStock, ignoresell);
        }
        return dp[i][buy][limit] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.assign(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(0, 1, prices, 2);
    }
};