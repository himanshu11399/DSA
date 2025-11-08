class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, string& s1, string& s2, int n, int m) {
        if (i == n)
            return m - j;
        if (j == m)
            return n - i;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s1[i] == s2[j]) {
            return dp[i][j] = solve(i + 1, j + 1, s1, s2, n, m);
        }
        // insert
        int insert = 1 + solve(i, j + 1, s1, s2, n, m);
        int del = 1 + solve(i + 1, j, s1, s2, n, m);
        int update = 1 + solve(i + 1, j + 1, s1, s2, n, m);
        return dp[i][j] = min({insert, del, update});
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        dp.assign(n + 1, vector<int>(m + 1, -1));
        return solve(0,0, word1, word2, n, m);
    }
};