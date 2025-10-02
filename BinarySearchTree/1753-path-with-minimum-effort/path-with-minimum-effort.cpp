class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        if (n == 1 && m == 1)
            return 0;

        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        dis[0][0] = 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            q;
        q.push({0, 0, 0});

        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            auto it = q.top();
            int effort = it[0];
            int row = it[1];
            int col = it[2];
            q.pop();

            for (auto it : dir) {
                int nrow = row + it[0];
                int ncol = col + it[1];
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m) {
                    int neweffort = max(
                        effort, abs(heights[row][col] - heights[nrow][ncol]));
                    if (neweffort < dis[nrow][ncol]) {
                        dis[nrow][ncol] = neweffort;
                        q.push({neweffort, nrow, ncol});
                    }
                }
            }
        }
        return dis[n - 1][m - 1];
    }
};