class Solution {
public:
int m,n;
vector<vector<vector<int>>>dp;

int solve(vector<vector<int>>&grid,int row,int c1,int c2){
    if(row>=m) return 0;
    int cherry=grid[row][c1];
    if(c1!=c2){
        cherry+=grid[row][c2];
    }
    if(dp[row][c1][c2]!=-1) return dp[row][c1][c2];
    
    int ans=0;
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            int nrow=row+1;
            int nc1=c1+i;
            int nc2=c2+j;

            if(nc1>=0 && nc1<n && nc2>=0 && nc2<n){
                ans=max(ans,solve(grid,nrow,nc1,nc2));
            }
        }
    }
    cherry+=ans;
    return dp[row][c1][c2]=cherry;
}
    int cherryPickup(vector<vector<int>>& grid) {
      m=grid.size();
      n=grid[0].size();
      dp.assign(m,vector<vector<int>>(n,vector<int>(n,-1)));
      return solve(grid,0,0,n-1);  
    }
};