class Solution {
public:

   void DFS(int src,vector<int>&vis,vector<vector<int>>&adj){
     vis[src]=1;
     for(int& it:adj[src]){
        if(vis[it]==0){
            DFS(it,vis,adj);
        }
     }
   }

    int findCircleNum(vector<vector<int>>& matrix) {
       int n=matrix.size();
       vector<vector<int>>adj(n);

       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==1){
                adj[i].push_back(j);
            }
        }
       }
       
       int count=0;
       vector<int>vis(n,0);
       
       for(int i=0;i<n;i++){
        if(!vis[i]){
            DFS(i,vis,adj);
            count+=1;
        }
       }
       return count;
    }
};