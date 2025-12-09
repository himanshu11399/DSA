class Solution {
public:
    int maxProfit(int& k,vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(k+1, 0)));

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int limit = 1; limit <= k; limit++) {
                    int profit = 0;
                    if (buy) {
                        int buyit = -prices[i] + dp[i + 1][0][limit];
                        int ignoreit = dp[i + 1][1][limit];
                        profit = max(buyit, ignoreit);
                    } else {
                        int sellit = prices[i] + dp[i + 1][1][limit-1];
                        int ignoreit = dp[i + 1][0][limit];
                        profit = max(sellit, ignoreit);
                    }
                    dp[i][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][k];
    }
};