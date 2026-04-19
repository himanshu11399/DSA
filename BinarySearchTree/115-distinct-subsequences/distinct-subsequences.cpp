class Solution {
public:
    vector<vector<int>> dp;
    int solve(string& str1, string& str2, int i, int j) {
        if (i >= str1.size()) {
            return 1;
        }
        if (j >= str2.size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (str1[i] == str2[j]) {
            int take = solve(str1, str2, i + 1, j + 1);
            int notake = solve(str1, str2, i, j + 1);
            return dp[i][j] = take+notake;
        }
        return dp[i][j] = solve(str1, str2, i, j + 1);
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        dp.assign(m + 1, vector<int>(n + 1, -1));
        return solve(t, s, 0, 0);
    }
};