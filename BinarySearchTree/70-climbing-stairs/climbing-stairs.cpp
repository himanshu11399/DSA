class Solution {
public:
    vector<int> dp;
    int solve(int n) {
        if (n < 0)
            return 0;
        if (n == 0 || n == 1) {
            return 1;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        // take 1
        int take = solve(n - 1);

        int notake = solve(n - 2);

        return dp[n] = take + notake;
    }
    int climbStairs(int n) {
        dp.assign(n + 1, -1);
        return solve(n);
    }
};