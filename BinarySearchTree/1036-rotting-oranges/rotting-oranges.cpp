class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        queue<pair<int, int>> q;

        // Find the rooten orange
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        // Apply the BFS
        while (!q.empty()) {
            int sz = q.size();
            bool isroot = false;

            for (int i = 0; i < sz; i++) {
                auto [row, col] = q.front();
                q.pop();
                for (auto& it : dir) {
                    int nrow = row + it[0];
                    int ncol = col + it[1];
                    if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                        grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0) {
                        q.push({nrow, ncol});
                        vis[nrow][ncol] = 1;
                        grid[nrow][ncol] = 2;
                        isroot = true;
                    }
                }
            }
            if (isroot)
                count++;
        }

        // Check if any fresh orange is remain

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }

        return count;
    }
};