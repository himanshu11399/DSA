class Solution {
public:
    void bfs(vector<vector<int>>& adj, vector<int>& vis, int& src) {
        vis[src] = 1;

        for (int i = 0; i < adj[src].size(); i++) {
            int v = adj[src][i];
            if (vis[v] == 0) {
                bfs(adj, vis, v);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (nums[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(n, 0);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                bfs(adj, vis, i);
                count++;
            }
        }
        return count;
    }
};