class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc,
                                  int color) {
        int n = grid.size();
        int m = grid[0].size();
        int pixel = grid[sr][sc];

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dir = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        queue<pair<int, int>> q;
        q.push({sr, sc});
        vis[sr][sc] = 1;
        grid[sr][sc] = color;

        while (!q.empty()) {
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                auto [row, col] = q.front();
                q.pop();
                for (auto it : dir) {
                    int nrow = it[0] + row;
                    int ncol = it[1] + col;
                    if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                        grid[nrow][ncol] == pixel && vis[nrow][ncol] == 0) {
                        q.push({nrow, ncol});
                        vis[nrow][ncol] = 1;
                        grid[nrow][ncol] = color;
                    }
                }
            }
        }
        return grid;
    }
};