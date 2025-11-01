class Solution {
public:
int solve(int i,int j,int n,int m,vector<vector<int>>&grid,vector<vector<int>>&dp){
    if(i>=m || j>=n) return 0;
    if(grid[i][j]==1) return 0;
    if(i==m-1 && j==n-1) return 1;
    if(dp[i][j]!=-1) return dp[i][j];

    int R=solve(i,j+1,n,m,grid,dp);
    int d=solve(i+1,j,n,m,grid,dp);

    return dp[i][j]=R+d;
}
    int uniquePathsWithObstacles(vector<vector<int>>grid) {
       int m= grid.size();
       int n=grid[0].size();

       vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
       return solve(0,0,n,m,grid,dp);
    }
};