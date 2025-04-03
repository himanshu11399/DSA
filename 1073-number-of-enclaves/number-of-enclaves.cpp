class Solution {
      private:
    void dfs(int row,int col,vector<vector<int>>&vis,
    vector<vector<int>>&board,vector<int>&drow,vector<int>&dcol){
        int n=board.size();
        int m=board[0].size();
      vis[row][col]=1;
      for(int i=0;i<4;i++){
        int nrow=row+drow[i];
        int ncol=col+dcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] &&
         board[nrow][ncol]==1){
            dfs(nrow,ncol,vis,board,drow,dcol);
         }
      }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
          int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector(m,0));

        vector<int>drow={-1,0,1,0};
        vector<int>dcol={0,1,0,-1};

        //traverse the 1st and the last row
        for(int j=0;j<m;j++){
            //traverse the first row
            if(!vis[0][j] && grid[0][j]==1){
                dfs(0,j,vis,grid,drow,dcol);
            }
            //traverse the last row
            if(!vis[n-1][j] && grid[n-1][j]==1){
                dfs(n-1,j,vis,grid,drow,dcol);
            }
        }

        //teraverse the first and the last col
        for(int i=0;i<n;i++){
            //traverse the first col
            if(!vis[i][0] && grid[i][0]==1){
                dfs(i,0,vis,grid,drow,dcol);
            }
            //traverse the last col
            if(!vis[i][m-1] && grid[i][m-1]==1){
                dfs(i,m-1,vis,grid,drow,dcol);
            }
        }
       int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                  count++;
                }
            }
        }return count;
    }
};