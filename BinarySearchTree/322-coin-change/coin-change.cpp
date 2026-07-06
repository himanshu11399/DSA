class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& coins, int amount, int idx) {
        if (amount == 0) {
            return 0;
        }
        if (idx >= coins.size() || amount < 0) {
            return INT_MAX;
        }
        if (dp[idx][amount] != -1) {
            return dp[idx][amount];
        }
        int take = solve(coins, amount - coins[idx], idx);
        if (take != INT_MAX) {
            take += 1;
        }
        int notake = solve(coins, amount, idx + 1);
        return dp[idx][amount] = min(take, notake);
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.assign(coins.size(), vector<int>(amount+1, -1));
        int ans= solve(coins, amount, 0);
        return ans==INT_MAX?-1:ans;
    }
};