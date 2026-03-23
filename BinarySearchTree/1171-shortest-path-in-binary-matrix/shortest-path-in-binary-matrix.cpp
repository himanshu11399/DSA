class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1]) {
            return -1;
        }

        if(n==1) return 1;

        vector<vector<int>> dis(n, vector<int>(n, 1e9));
        vector<vector<int>> dir = {{0, 1}, {1, 0},   {0, -1}, {-1, 0},
                                   {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};

        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            for (auto it : dir) {
                int nrow = u + it[0];
                int ncol = v + it[1];

                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < n &&
                    grid[nrow][ncol] == 0) {

                    if (dis[nrow][ncol] > wt + 1) {
                        dis[nrow][ncol] = min(dis[nrow][ncol],wt + 1);
                        q.push({wt + 1, {nrow, ncol}});
                    }
                }
            }
        }
        if (dis[n - 1][n - 1] == 1e9) {
            return -1;
        }
        return dis[n - 1][n - 1];
    }
};