class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int i = 0;
        for (int j = 1; j < prices.size(); j++) {
            if (prices[i] > prices[j]) {
                i = j;
            } else {
                maxprofit = max(maxprofit, prices[j] - prices[i]);
            }
        }
        return maxprofit;
    }
};