class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        int count = 0;

        while (!q.empty()) {
            int lvl = q.size();
            int isroot=false;

            for (int i = 0; i < lvl; i++) {
                auto [row, col] = q.front();
                q.pop();

                for (auto it : dir) {
                    int nrow = row + it[0];
                    int ncol = col + it[1];
                    if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                        vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                        vis[nrow][ncol] = 1;
                        grid[nrow][ncol]=2;
                        q.push({nrow, ncol});
                        isroot=true;
                    }
                }
            }
            if(isroot){
                count++;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return count;
    }
};