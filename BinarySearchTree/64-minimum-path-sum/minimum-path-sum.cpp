class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 1e9));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i==1 && j==1){
                    dp[i][j]=grid[i-1][j-1];
                    continue;
                }
                int right=dp[i][j-1];
                int bottom=dp[i-1][j];
                dp[i][j]=min(right,bottom)+grid[i-1][j-1];
            }
        }
        return dp[n][m];
    }
};