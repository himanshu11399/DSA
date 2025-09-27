class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc,
                                  int color) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m, -1));
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        q.push({sr, sc});
        ans[sr][sc] = color;

        while (!q.empty()) {
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                auto [row, col] = q.front();
                q.pop();
                for (auto& it : dir) {
                    int nrow = row + it[0];
                    int ncol = col + it[1];
                    if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                        vis[nrow][ncol] == 0 &&
                        grid[row][col] == grid[nrow][ncol]) {
                        q.push({nrow, ncol});
                        vis[nrow][ncol]=1;
                        ans[nrow][ncol] = color;
                    }
                }
            }
        }

        // copy the remaining colors
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (ans[i][j] != color) {
                    ans[i][j] = grid[i][j];
                }
            }
        }

        return ans;
    }
};