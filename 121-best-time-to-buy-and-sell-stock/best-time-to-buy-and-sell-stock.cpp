class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int i = 0;
        for (int j = 1; j < prices.size(); j++) {
            if (prices[i] > prices[j]) {
                i=j;
            } else {
                max_profit = max(max_profit, prices[j] - prices[i]);
            }
        }
        return max_profit;
    }
};