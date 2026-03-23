class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    void dfs(vector<vector<char>>& nums, int row, int col,
             vector < vector<int>> & vis, int& n, int& m) {
        vis[row][col] = 1;

        // if (row ==  || col == m - 1) {
        //     return;
        // }
        for (int i = 0; i < 4; i++) {
            int nrow = row + dir[i][0];
            int ncol = col + dir[i][1];

            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                vis[nrow][ncol] == 0 && nums[nrow][ncol] == '1') {
                dfs(nums, nrow, ncol, vis, n, m);
            }
        }
    }
    int numIslands(vector<vector<char>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 0 && nums[i][j] == '1') {
                    dfs(nums, i, j, vis, n, m);
                    count++;
                }
            }
        }
        return count;
    }
};