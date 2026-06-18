class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& vis, int src) {
        vis[src] = true;

        for(int i=0;i<adj[src].size();i++){
            int v=adj[src][i];
            if(!vis[v]){
                dfs(adj,vis,v);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& nums) {
        vector<vector<int>> adj(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                if (nums[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> vis(nums.size() + 1, 0);

        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (!vis[i]) {
                dfs(adj, vis, i);
                count++;
            }
        }
        return count;
    }
};