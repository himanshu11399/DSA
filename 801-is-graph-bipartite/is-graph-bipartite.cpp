class Solution {
    private:
    bool dfs(int i,int col,vector<int>&color,vector<vector<int>>&graph){
        color[i]=col;

        for(auto j:graph[i]){
            if(color[j]==-1){
                if(!dfs(j,!col,color,graph)) return false;
            }else if(color[j]==col){
                 return false;
            }
        }return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(dfs(i,0,color,graph)==false) return false;
                
            }
        }return true;
    }
};