class Solution {
public:
    vector<vector<int>> dp;
    int solve(string& s1, string& s2, int i, int j) {
        if (i >= s1.size() || j >= s2.size()) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ispos = 0;
        int row = 0;
        int col = 0;
        if (s1[i] == s2[j]) {
            ispos = solve(s1, s2, i + 1, j + 1) + 1;
        } else {
            // Increse i
            row = solve(s1, s2, i + 1, j);

            // Increase J
            col = solve(s1, s2, i, j + 1);
        }
        return dp[i][j] = max(ispos, max(row, col));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        dp.assign(n, vector<int>(m, -1));
        return solve(text1, text2, 0, 0);
    }
};