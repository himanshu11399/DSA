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
            int buyit = -prices[i] + solve(i + 1, 0, prices);
            int ignoreit = solve(i + 1, 1, prices);
            profit = max(buyit, ignoreit);
        } else {
            int sellit = prices[i] + solve(i + 1, 1, prices);
            int ignoreit = solve(i + 1, 0, prices);
            profit = max(sellit, ignoreit);
        }

        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.assign(n + 1, vector<int>(2, -1));
        return solve(0, 1, prices);
    }
};