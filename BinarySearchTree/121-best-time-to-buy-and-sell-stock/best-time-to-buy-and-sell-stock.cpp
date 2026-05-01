class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxans = 0;
        int i = 0;
        for (int j = 1; j < n; j++) {
            if (prices[i] > prices[j]) {
                i=j;
            }else{
                maxans=max(maxans,prices[j]-prices[i]);
            }
        }
        return maxans;
    }
};