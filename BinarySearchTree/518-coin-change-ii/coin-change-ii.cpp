class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>&nums,int i,int amount){
        if(amount==0){
            return 1;
        }
        if(i>=nums.size() || amount<0){
            return 0;
        }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }

        int same=solve(nums,i,amount-nums[i]);
        int notake=solve(nums,i+1,amount);
        return dp[i][amount]=same+notake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        dp.assign(n+1,vector<int>(amount+1,-1));
        return solve(coins,0,amount);
    }
};