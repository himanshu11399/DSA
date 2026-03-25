class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& nums) {
        int n = nums.size();
        if (nums[0][0] == 1 || nums[n - 1][n - 1] == 1) {
            return -1;
        }

        if (n == 1) {
            return 1;
        }

        vector<vector<int>>vis(n, vector<int>(n,1e9));
        vector<vector<int>> dir = {{0, 1},  {1, 0},  {-1, 0},
                                   {0, -1}, {-1, 1}, {1, -1},{-1,-1},{1,1}};

        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0][0] = 1;

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (auto it : dir) {
                int nrow = row + it[0];
                int ncol = col + it[1];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&
                    nums[nrow][ncol] == 0) {
                    if (vis[nrow][ncol] > vis[row][col] + 1) {
                        vis[nrow][ncol] = vis[row][col] + 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
        if (vis[n - 1][n - 1] == 1e9) {
            return -1;
        }
        return vis[n - 1][n - 1];
    }
};