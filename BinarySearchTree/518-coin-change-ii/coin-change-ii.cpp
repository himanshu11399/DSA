class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, vector<int>& coins, int target) {
        if (target == 0)
            return 1;
        if (i >= coins.size() || target < 0)
            return 0;
        if (dp[i][target] != -1)
            return dp[i][target];
        // take same
        int same = solve(i, coins, target - coins[i]);

        // take different
        int diff = solve(i + 1, coins, target);

        return dp[i][target] = same + diff;
    }
    int change(int amount, vector<int>& coins) { 
        int n = coins.size();
        dp.assign(n,vector<int>(amount+1,-1));
        return solve(0,coins,amount);
         }
};