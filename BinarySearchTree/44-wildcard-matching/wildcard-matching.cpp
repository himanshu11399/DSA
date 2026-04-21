class Solution {
public:
    vector<vector<int>> dp;
    bool solve(string& str1, string& str2, int i, int j) {
        if (i == str1.size() && j == str2.size()) {
            return 1;
        }
        if(i==str1.size()){
            while(j<str2.size()){
                if(str2[j]!='*') return false;
                j++;
            } return true;
        }
        if(j>=str2.size()) return 0;
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (str1[i] == str2[j] || str2[j] == '?') {
            return dp[i][j] = solve(str1, str2, i + 1, j + 1);
        }

        if (str2[j] == '*') {
            int take = solve(str1, str2, i + 1, j);
            int notake = solve(str1, str2, i, j + 1);
            return dp[i][j] = take || notake;
        }
        return dp[i][j] = 0;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        dp.assign(n + 1, vector<int>(m + 1, -1));
        return solve(s, p, 0, 0);
    }
};