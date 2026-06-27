class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void dfs(vector<vector<char>>& grid, int sr, int sc,
             vector<vector<bool>>& vis) {
        vis[sr][sc] = true;
        for (auto it : dir) {
            int nrow = sr + it[0];
            int ncol = sc + it[1];
            if (nrow >= 0 && ncol >= 0 && nrow < grid.size() &&
                ncol < grid[0].size() && !vis[nrow][ncol] &&
                grid[nrow][ncol] == '1') {
                dfs(grid, nrow, ncol, vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n + 1, vector<bool>(m + 1, false));
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    if (!vis[i][j]) {
                        dfs(grid, i, j, vis);
                        count++;
                    }
                }
            }
        }

        return count;
    }
};