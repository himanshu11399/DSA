class Solution {
public:
vector<vector<int>>dp;
int solve(vector<int>&prices,int i,int buy){
    if(i>=prices.size()){
        return 0;
    }
    if(dp[i][buy]!=-1){
        return dp[i][buy];
    }
    int profit=0;
    if(buy){
      int take=-prices[i]+solve(prices,i+1,0);
      int notake=solve(prices,i+1,1);
      profit=max(take,notake);
    }else{
        int take=+prices[i]+solve(prices,i+1,1);
        int notake=solve(prices,i+1,0);
        profit=max(take,notake);
    }
    return dp[i][buy]=profit;
}
    int maxProfit(vector<int>& prices) {
       int n=prices.size();
       dp.assign(n+1,vector<int>(2,-1));
       return solve(prices,0,1); 
    }
};