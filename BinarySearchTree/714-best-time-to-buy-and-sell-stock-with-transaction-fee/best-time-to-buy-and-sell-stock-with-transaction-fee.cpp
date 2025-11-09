class Solution {
public:
    // vector<vector<int>> dp;
    // int solve(int i, int buy, vector<int>& prices, int charge) {
    //     if (i == prices.size())
    //         return 0;
    //     if (dp[i][buy] != -1)
    //         return dp[i][buy];
    //     int profit = 0;
    //     if (buy) {
    //         int buyStock =
    //             -(prices[i] + charge) + solve(i + 1, 0, prices, charge);
    //         int ignoreBuy = solve(i + 1, 1, prices, charge);
    //         profit = max(buyStock, ignoreBuy);
    //     } else {
    //         int sellStock = +prices[i] + solve(i + 1, 1, prices, charge);
    //         int ignoresell = solve(i + 1, 0, prices, charge);
    //         profit = max(sellStock, ignoresell);
    //     }
    //     return dp[i][buy] = profit;
    // }

    int optimal(vector<int>& prices,int charges) {
        int n = prices.size();
        vector<int> curr(2, 0);
        vector<int> next(2, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if (buy) {
                    int buyStock =
                        -(prices[i] + charges) + next[0];
                    int ignoreBuy = next[1];
                    profit = max(buyStock, ignoreBuy);
                } else {
                    int sellStock =
                        +prices[i] + next[1];
                    int ignoresell = next[0];
                    profit = max(sellStock, ignoresell);
                }
                curr[buy] = profit;
            }
            next=curr;
        }
        return next[1];
    }


    int maxProfit(vector<int>& prices, int fee) {
        // int n = prices.size();
        // dp.assign(n + 1, vector<int>(2, -1));
        // return solve(0, 1, prices, fee);
        return optimal(prices,fee);
    }
};