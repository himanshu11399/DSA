class Solution {
public:
void dfs(int index,vector<vector<int>>&stones,vector<bool>&vis){
    vis[index]=true;

    int r=stones[index][0];
    int c=stones[index][1];

    for(int i=0;i<stones.size();i++){
        if(!vis[i] && (stones[i][0]==r || stones[i][1]==c)){
           dfs(i,stones,vis);
        }
    }
}
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<bool>vis(n,false);
        int group=0;
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            dfs(i,stones,vis);
            group++;
        }return (n-group);
    }
};