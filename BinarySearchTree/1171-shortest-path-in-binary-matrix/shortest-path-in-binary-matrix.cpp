class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        if (n == 1)
            return 1;

        vector<vector<int>> dis(n, vector<int>(n, 1e9));
        // pair<wt<row,col>>
        queue<pair<int, pair<int, int>>> q;
        dis[0][0] = 1;
        q.push({1, {0, 0}});

        vector<vector<int>> dir = {{-1, 0},  {1, 0}, {0, 1},  {0, -1},
                                   {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};

        while (!q.empty()) {
            auto it = q.front();
            int wt = it.first;
            int row = it.second.first;
            int col = it.second.second;
            q.pop();

            for (auto it : dir) {

                int nrow = row + it[0];
                int ncol = col + it[1];

                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < n &&
                    grid[nrow][ncol] == 0 && wt + 1 < dis[nrow][ncol]) {

                    if (nrow == n - 1 && ncol == n - 1) {
                        return wt + 1;
                    }
                    dis[nrow][ncol] = wt + 1;
                    q.push({wt + 1, {nrow, ncol}});
                }
            }
        }
        return -1;
    }
};