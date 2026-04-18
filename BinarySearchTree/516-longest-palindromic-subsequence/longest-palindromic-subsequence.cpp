class Solution {
public:
    vector<vector<int>> dp;
    int solve(string& str, int i, int j) {
        if (i >= str.size() || j < 0 || i > j) {
            return 0;
        }
        if (i == j) {
            return 1;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int notake = 0;
        if (str[i] == str[j]) {
            return dp[i][j] = solve(str, i + 1, j - 1) + 2;
        }
        int left = solve(str, i + 1, j);
        int right = solve(str, i, j-1);
        return dp[i][j] = max(left, right);
    }
    int longestPalindromeSubseq(string str) {
        int n = str.size();
        dp.assign(n + 2, vector<int>(n + 2, -1));
        return solve(str, 0, n - 1);
    }
};