class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, -1));
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (auto it : dir) {
                int nrow = row + it[0];
                int ncol = col + it[1];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    ans[nrow][ncol] == -1) {
                    ans[nrow][ncol] = ans[row][col] + 1;
                    q.push({nrow, ncol});
                }
            }
        }
        return ans;
    }
};