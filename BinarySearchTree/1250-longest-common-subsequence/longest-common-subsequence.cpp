class Solution {
public:
    // vector<vector<int>>dp;
    //     int solve(string&s1,string&s2,int i,int j){
    //      if(i>=s1.size() || j>=s2.size()){
    //         return 0;
    //      }
    //      if(dp[i][j]!=-1){
    //         return dp[i][j];
    //      }
    //      if(s1[i]==s2[j]){
    //         return solve(s1,s2,i+1,j+1)+1;
    //      }

    //      int left=solve(s1,s2,i+1,j);
    //      int right=solve(s1,s2,i,j+1);

    //      return dp[i][j]=max(left,right);
    //     }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
};