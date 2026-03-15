class Solution {
public:
    void solve(vector<vector<char>>& mat) {
       int n=mat.size();
       int m=mat[0].size();

       vector<vector<int>>vis(n,vector<int>(m,0));
       vector<vector<int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
       queue<pair<int,int>>q;


       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           if(i==0 || i==n-1 || j==0 || j==m-1){
            if(mat[i][j]=='O'){
                q.push({i,j});
                vis[i][j]=1;
            }
           }
        }
       }

       while(!q.empty()){
        auto [row,col]=q.front();
        q.pop();

        for(auto it:dir){
            int nrow=row+it[0];
            int ncol=col+it[1];

            if(nrow<n && nrow>=0 && ncol<m && ncol>=0 
             && vis[nrow][ncol]==0 && mat[nrow][ncol]=='O'){
               vis[nrow][ncol]=1;
               q.push({nrow,ncol});
             }
        }
       }

       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==0 && mat[i][j]=='O'){
                mat[i][j]='X';
                vis[i][j]=1;
            }
        }
       }
    }
};