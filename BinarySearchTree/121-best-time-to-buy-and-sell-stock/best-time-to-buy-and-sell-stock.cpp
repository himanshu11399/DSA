class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxprofit = 0;
        int i = 0;
        int j=1;
        while(j<n){
            if (prices[j] <= prices[i]) {
                i=j;
            } else {
                maxprofit = max(maxprofit, prices[j] - prices[i]);
            }
            j++;
        }
        return maxprofit;
    }
};