class Solution {
public:
    vector<vector<int>> dp;
    bool isValid(string& s, int i, int j) {
        if (i >= j) {
            return true;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s[i] != s[j]) {
            return false;
        }
        return dp[i][j] = isValid(s, i + 1, j - 1);
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int len = 0;
        int start=0;
        dp.assign(n + 1, vector<int>(n + 1, -1));
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {

                if (isValid(s, i, j)) {
                    if (len < j - i + 1) {
                        len = j - i + 1;
                        start=i;
                    }
                }
            }
        }

        return s.substr(start,len);
    }
};