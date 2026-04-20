class Solution {
public:
    vector<vector<int>> dp;
    int solve(string& s1, string& s2, int i, int j) {
        if (i == s1.size() && j == s2.size()) {
            return 0;
        }
        // if (i > s1.size() && j < s2.size()) {
        //     return INT_MAX;
        // }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s1[i] == s2[j]) {
            return dp[i][j] = solve(s1, s2, i + 1, j + 1);
        }

        int insert = INT_MAX;
        int update = INT_MAX;
        int del = INT_MAX;

        // Insert
        if (j < s2.size()) {
            insert = solve(s1, s2, i, j + 1) + 1;
        }

        // Update
        if (i < s1.size() && j < s2.size()) {
            update = solve(s1, s2, i + 1, j + 1) + 1;
        }

        // Delete
        if (i < s1.size()) {
            del = solve(s1, s2, i + 1, j) + 1;
        }

        return dp[i][j] = min(insert, min(update, del));
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        dp.assign(n + 1, vector<int>(m + 1, -1));
        return solve(word1, word2, 0, 0);
    }
};