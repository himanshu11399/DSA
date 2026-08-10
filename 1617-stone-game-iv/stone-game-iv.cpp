class Solution {
public:
    vector<int> sqr;
    vector<int> dp;
    bool solve(int n) {
        if (n == 0)
            return false;
        if (dp[n] != -1)
            return dp[n];
        for (auto it : sqr) {
            if (it > n)
                break;
            if (!solve(n - it)) {
                return dp[n] = true;
            }
        }
        return dp[n] = false;
    }
    bool winnerSquareGame(int n) {
        for (int i = 1; i <= n; i++) {
            int sq = i * i;
            if (sq > n)
                break;
            sqr.push_back(sq);
        }
        dp.assign(n + 1, -1);
        return solve(n);
    }
};