class Solution {
    private:
    void dfs(int node,vector<vector<int>>&isConnected,vector<int>&vis){
        vis[node]=1;
   
            for (int j = 0; j < isConnected.size(); j++) { 
            if (isConnected[node][j] == 1 && !vis[j]) { // Check adjacency matrix
                dfs(j, isConnected, vis);
            
        }
    }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>vis(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                count++;
                dfs(i,isConnected,vis);
            }
        }
return count;
    }
};