class Solution {
private:
    bool dfs(int node, vector<int>& vis, vector<int>& pathvis, vector<vector<int>>& adj) {
        vis[node] = 1;
        pathvis[node] = 1;

        for (auto adjNode : adj[node]) {
            if (!vis[adjNode]) {
                if (dfs(adjNode, vis, pathvis, adj)) return true;
            } else if (pathvis[adjNode]) {
                return true;
            }
        }

        pathvis[node] = 0;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<vector<int>> adj(V);
        
        // Build the adjacency list: b → a
        for (auto& pre : prerequisites) {
            int a = pre[0];
            int b = pre[1];
            adj[b].push_back(a);
        }

        vector<int> vis(V, 0);
        vector<int> pathvis(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, pathvis, adj)) return false; // cycle => can't finish
            }
        }

        return true; // no cycle
    }
};
