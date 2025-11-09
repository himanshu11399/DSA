class Solution {
public:
vector<vector<int>>dp;
int solve(int i,int buy,vector<int>&prices){
    if(i>=prices.size()) return 0;
    if(dp[i][buy]!=-1) return dp[i][buy];

    int profit=0;
    if(buy){
        int buyStock=-prices[i]+solve(i+1,0,prices);
        int ignoreBuy=solve(i+1,1,prices);
        profit=max(buyStock,ignoreBuy);
    }else{
        int sellStock=+prices[i]+solve(i+1,1,prices);
        int ignoreSell=solve(i+1,0,prices);
        profit=max(sellStock,ignoreSell);
    }
    return dp[i][buy]= profit;
}
    int maxProfit(vector<int>& prices) {
     dp.assign(prices.size()+1,vector<int>(2,-1));
      return solve(0,1,prices);  
    }
};