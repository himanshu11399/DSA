class Solution {
public:
    int tabulation(vector<int>& prices,int limit) {
        int n = prices.size();

        vector<vector<int>> curr(2, vector<int>(limit+1, 0));
        vector<vector<int>> next(2, vector<int>(limit+1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= 1; j++) {
                for (int k = 1; k <= limit; k++) {
                    int profit = 0;
                    if (j) {
                        int buyStock = -prices[i] + next[0][k];
                        int ignorebuy = next[1][k];
                        profit = max(buyStock, ignorebuy);
                    } else {
                        int sellStock = +prices[i] + next[1][k - 1];
                        int ignoresell = next[0][k];
                        profit = max(sellStock, ignoresell);
                    }
                    curr[j][k] = profit;
                }
            }
            next = curr;
        }
        return next[1][limit];
    }
    int maxProfit(int k, vector<int>& prices) {
        return tabulation(prices,k);
    }
};