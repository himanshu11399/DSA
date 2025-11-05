class Solution {
public:
vector<vector<int>>dp;
int solve(int i,vector<int>&nums,int amount){
    if(amount==0) return 0;
    if(i>=nums.size() || amount<0) return 1e9;
    if(dp[i][amount]!=-1) return dp[i][amount];
    //take same
    int same=1+solve(i,nums,amount-nums[i]);
    int diff=solve(i+1,nums,amount);
    
    return dp[i][amount]=min(same,diff);
}
    int coinChange(vector<int>& coins, int amount) {
        dp.assign(coins.size()+1,vector<int>(amount+1,-1));
        int ans= solve(0,coins,amount);
        return ans>=1e9?-1 :ans;
    }
};