class Solution {
public:
    vector<vector<vector<int>>> dp;
    // int solve(int i, int buy, vector<int>& prices, int limit) {
    //     if (i >= prices.size() || limit <= 0)
    //         return 0;
    //     if (dp[i][buy][limit] != -1)
    //         return dp[i][buy][limit];

    //     int profit = 0;
    //     if (buy) {
    //         int buyStock = -prices[i] + solve(i + 1, 0, prices, limit);
    //         int ignorebuy = solve(i + 1, 1, prices, limit);
    //         profit = max(buyStock, ignorebuy);
    //     } else {
    //         int sellStock = +prices[i] + solve(i + 1, 1, prices, limit - 1);
    //         int ignoresell = solve(i + 1, 0, prices, limit);
    //         profit = max(sellStock, ignoresell);
    //     }
    //     return dp[i][buy][limit] = profit;
    // }

    int tabulation(vector<int>& prices) {
        int n = prices.size();
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= 1; j++) {
                for (int k = 1; k <= 2; k++) {
                    int profit = 0;
                    if (j) {
                        int buyStock =
                            -prices[i] + dp[i+1][0][k];
                        int ignorebuy =dp[i+1][1][k];
                        profit = max(buyStock, ignorebuy);
                    } else {
                        int sellStock =
                            +prices[i] + dp[i+1][1][k-1];
                        int ignoresell = dp[i+1][0][k];
                        profit = max(sellStock, ignoresell);
                    }
                    dp[i][j][k] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.assign(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        // return solve(0, 1, prices, 2);
        return tabulation(prices);
    }
};