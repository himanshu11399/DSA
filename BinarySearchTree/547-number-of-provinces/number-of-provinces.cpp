class Solution {
public:
    void Dfs(vector<vector<int>>& Adj, vector<int>& visited, int src) {
        visited[src] = true;
        for (int i = 0; i < Adj[src].size(); i++) {
            int v = Adj[src][i];
            if (!visited[v]) {
                Dfs(Adj, visited, v);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> Adj(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 1) {
                    Adj[i].push_back(j);
                }
            }
        }

        int count = 0;
        vector<int> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                Dfs(Adj, visited, i);
                count++;
            }
        }

        return count;
    }
};