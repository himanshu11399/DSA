class Solution {
public:
    // vector<vector<int>>dp;
    // int solve(int i,int j,string& t1,string& t2){
    //     if(i>=t1.size() || j>=t2.size()) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];

    //     int take=0;
    //     if(t1[i]==t2[j]){
    //       take=1+solve(i+1,j+1,t1,t2);
    //     }
    //     int notake=max(solve(i+1,j,t1,t2),solve(i,j+1,t1,t2));

    //     return dp[i][j]=max(take,notake);

    // }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= m; j++) {

                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }

                dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
            }
        }
        return dp[n][m];
    }
};