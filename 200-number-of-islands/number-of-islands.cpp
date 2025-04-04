class Solution {
    private:
    void bfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&grid){
        vis[row][col]=1;

        queue<pair<int,int>>q;
        q.push({row,col});

        int n=grid.size();
        int m=grid[0].size();

        // vector<int>drow={-1,-1,0,1,1,1,0,-1};
        // vector<int>dcol={0,1,1,1,0,-1,-1,-1};
         vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};

        while(!q.empty()){
            int row1=q.front().first;
            int col1=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nrow=row1+drow[i];
                int ncol=col1+dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    count++;
                    bfs(i,j,vis,grid);
                }
            }
        }return count;
    }
};