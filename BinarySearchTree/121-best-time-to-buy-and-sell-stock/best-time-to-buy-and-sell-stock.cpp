class Solution {
public:
  vector<vector<int>>dp;
//   int solve(vector<int>&prices,int i,int j){
//     if(j>=prices.size()){
//         return 0;
//     }
//     if(dp[i][j]!=-1){
//         return dp[i][j];
//     }

//     if(prices[i]>prices[j]){
//     return dp[i][j]=solve(prices,i+1,j+1);
//     }
//     int ans=prices[j]-prices[i];
//     return dp[i][j]=max(ans,solve(prices,i,j+1));
//   }
  
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxans=INT_MIN;
        int j=0;
        for(int i=1;i<n;i++){
            if(prices[j]>prices[i]){
              j=i;  
            }else{
                maxans=max(maxans,prices[i]-prices[j]);
            }
        }
        return maxans==INT_MIN?0:maxans;
    }
};