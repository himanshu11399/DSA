class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int total=0;

        for(int i=0;i<prices.size();i++){
           if(prices[total]>prices[i]){
            total=i;
           } else{
            int profit=prices[i]-prices[total];
            maxProfit=max(maxProfit,profit);
           }
        }
      return maxProfit;  
    }
};