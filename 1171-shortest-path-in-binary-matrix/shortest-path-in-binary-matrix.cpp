class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1) return -1;
        if(n==1 || m==1) return 1;

        vector<vector<int>>dis(n,vector<int>(m,1e9));
        queue<pair<int,pair<int,int>>>q;

        q.push({1,{0,0}});
        dis[0][0]=1;

        int drow[8]={-1,-1,0,1,1,1,0,-1};
        int dcol[8]={0,1,1,1,0,-1,-1,-1};

        while(!q.empty()){
            auto it=q.front();
            int row=it.second.first;
            int col=it.second.second;
            int wt=it.first;
            q.pop();

            for(int i=0;i<8;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0 && 
                wt+1<dis[nrow][ncol]){
                    dis[nrow][ncol]=wt+1;
                    if(nrow==n-1 && ncol==m-1){
                        return wt+1;
                    }q.push({wt+1,{nrow,ncol}});
                }
            }
        }
      return -1;  
    }
};