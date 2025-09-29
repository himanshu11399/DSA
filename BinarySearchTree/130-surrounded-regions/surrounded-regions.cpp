class Solution {
public:
vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(int row,int col,vector<vector<char>>&board,vector<vector<int>>&vis,int n,int m){
       vis[row][col]=1;

       for(auto it:dir){
        int nrow=row+it[0];
        int ncol=col+it[1];
        if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && board[nrow][ncol]=='O' && vis[nrow][ncol]==0){
            dfs(nrow,ncol,board,vis,n,m);
        }
       } 
    }

    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        //mark the edges
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1 ){
                   if(board[i][j]=='O' && vis[i][j] == 0){
                    dfs(i,j,board,vis,n,m);
                   }
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && vis[i][j]==0){
                    board[i][j]='X';
                }
            }
        }

    }
};