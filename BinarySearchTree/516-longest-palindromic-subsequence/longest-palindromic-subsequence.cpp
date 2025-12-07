class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, string& s) {
        if (i > j)
            return 0;
        if (i == j)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == s[j]) {
            return dp[i][j] = solve(i + 1, j - 1, s) + 2;
        }

        int left = solve(i + 1, j, s);
        int right = solve(i, j - 1, s);

        return dp[i][j] = max(left, right);
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        dp.assign(n + 1, vector<int>(n + 1, -1));
        return solve(0, n - 1, s);
    }
};