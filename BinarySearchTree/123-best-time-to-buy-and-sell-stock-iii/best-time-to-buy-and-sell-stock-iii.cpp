class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(vector<int>& prices, int i, int buy, int maxbuy) {
        if (i >= prices.size() || maxbuy == 0) {
            return 0;
        }
        if (dp[i][buy][maxbuy] != -1) {
            return dp[i][buy][maxbuy];
        }
        int profit = 0;
        if (buy == 1) {
            int take = -prices[i] + solve(prices, i + 1, 0, maxbuy);
            int notake = solve(prices, i + 1, 1, maxbuy);
            profit = max(take, notake);
        } else {
            int take = +prices[i] + solve(prices, i + 1, 1, maxbuy - 1);
            int notake = solve(prices, i + 1, 0, maxbuy);
            profit = max(take, notake);
        }
        return dp[i][buy][maxbuy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.assign(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(prices, 0, 1, 2);
    }
};