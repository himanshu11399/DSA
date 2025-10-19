class Solution {
public:
int func(int idx,vector<int>&coins,int amount,vector<vector<int>>&dp){
    if(amount==0) return 1;
    if(idx==coins.size()) return 0;
    if(dp[idx][amount]!=-1) return dp[idx][amount];

    int ways=0;
    if(coins[idx]<=amount){
        ways+=func(idx,coins,amount-coins[idx],dp);
        
    }
    ways+=func(idx+1,coins,amount,dp);
    return dp[idx][amount]=ways;
}
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        return func(0,coins,amount,dp);
    }
};