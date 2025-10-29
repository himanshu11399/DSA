class Solution {
public:
   int fun(int n,vector<int>&dp){
    if(n==0 || n==1) return 1;
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];

    int left=fun(n-1,dp);
    int right=fun(n-2,dp);

    return dp[n]=left+right;
   }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return fun(n,dp);
    }
};