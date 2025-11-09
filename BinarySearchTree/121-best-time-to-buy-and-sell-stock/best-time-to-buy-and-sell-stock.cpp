class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = prices[0];
        int maxprofit = 0;
        for (int j = 1; j < prices.size(); j++) {
            maxprofit=max(maxprofit,prices[j]-minprice);
            minprice=min(minprice,prices[j]);
        }
        return maxprofit;
    }
};