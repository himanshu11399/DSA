class Solution {
public:
    // vector<vector<int>> dp;
    // int solve(int i,int j,int& m,int& n,vector<vector<int>>&grid){
    //      if(i>=m || j>=n) return 1e9;
    //      if(i==m-1 && j==n-1) return grid[i][j];
    //      if(dp[i][j]!=-1) return dp[i][j];
    //      int bottom=solve(i+1,j,m,n,grid);
    //      int right=solve(i,j+1,m,n,grid);
    //      return dp[i][j]=grid[i][j]+min(bottom,right);
    // }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        dp[0][0] = grid[0][0];

        for (int i = 1; i < m; i++) {
            dp[i][0] = grid[i][0] + dp[i - 1][0];
        }

        for (int j = 1; j < n; j++) {
            dp[0][j] = grid[0][j] + dp[0][j - 1];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                int left = dp[i][j - 1];
                int upper = dp[i - 1][j];
                dp[i][j] = grid[i][j]+min(left, upper);
            }
        }
        return dp[m-1][n-1];
    }
};