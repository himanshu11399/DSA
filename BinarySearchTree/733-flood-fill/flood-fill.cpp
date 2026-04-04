class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& nums, int sr, int sc,
                                  int color) {
        int n = nums.size();
        int m = nums[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int originalColor=nums[sr][sc];
        nums[sr][sc] = color;
        vis[sr][sc] = 1;

        while (!q.empty()) {
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                auto [row, col] = q.front();
                q.pop();

                for (auto it : dir) {
                    int nrow = row + it[0];
                    int ncol = col + it[1];
                    if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                        vis[nrow][ncol] == 0 && nums[nrow][ncol] == originalColor) {
                        nums[nrow][ncol] = color;
                        vis[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
        return nums;
    }
};