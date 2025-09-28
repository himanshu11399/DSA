class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>res(n,vector<int>(m,-1));
        vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        queue<pair<int,int>>q;


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    res[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto [row,col]=q.front();
            q.pop();

            for(auto it:dir){
                int nrow=row+it[0];
                int ncol=col+it[1];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m 
                && res[nrow][ncol]==-1){
                    res[nrow][ncol]=res[row][col]+1;
                    q.push({nrow,ncol});
                }
            }
        }
       return res;
    }
};