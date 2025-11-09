class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int buy, vector<int>& prices) {
        if (i >= prices.size())
            return 0;
        if (dp[i][buy] != -1)
            return dp[i][buy];

        int profit = 0;
        if (buy) {
            int buyStock = -prices[i] + solve(i + 1, 0, prices);
            int ignoreBuy = solve(i + 1, 1, prices);
            profit = max(buyStock, ignoreBuy);
        } else {
            int sellStock = +prices[i] + solve(i + 1, 1, prices);
            int ignoreSell = solve(i + 1, 0, prices);
            profit = max(sellStock, ignoreSell);
        }
        return dp[i][buy] = profit;
    }

    int tabulation(vector<int>& prices) {
        int n = prices.size();

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if (buy) {
                    int buyStock = -prices[i] + dp[i+1][0];
                    int ignoreBuy = dp[i+1][1];
                    profit = max(buyStock, ignoreBuy);
                } else {
                    int sellStock = +prices[i] + dp[i+1][1];
                    int ignoreSell = dp[i+1][0];
                    profit = max(sellStock, ignoreSell);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
    int maxProfit(vector<int>& prices) {
        dp.assign(prices.size() + 1, vector<int>(2, 0));
        return tabulation(prices);
    }
};