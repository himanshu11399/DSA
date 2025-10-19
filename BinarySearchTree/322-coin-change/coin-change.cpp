class Solution {
public:

    int func(vector<int>& coins, int amount,vector<int>&dp) {
        if (amount == 0) return 0;
        if(dp[amount]!=-1) return dp[amount];

        int ans = INT_MAX;
        for (int coin : coins) {
            if (amount - coin >= 0) {
                ans = min(ans + 0LL, func(coins, amount - coin,dp) + 1LL);
            }
        }
        return dp[amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        int ans=func(coins,amount,dp);
        return ans==INT_MAX?-1:ans;
    }
};