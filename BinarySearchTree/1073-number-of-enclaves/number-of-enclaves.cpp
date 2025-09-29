class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis,
             int n, int m) {
        vis[i][j] = 1;

        for (auto it : dir) {
            int nrow = i + it[0];
            int ncol = j + it[1];
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0) {
                dfs(nrow, ncol, grid, vis, n, m);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    if (grid[i][j] == 1 && vis[i][j] == 0) {
                        dfs(i, j, grid, vis, n, m);
                    }
                }
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    count++;
                }
            }
        }

        return count;
    }
};