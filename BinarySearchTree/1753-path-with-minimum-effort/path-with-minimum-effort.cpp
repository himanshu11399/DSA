class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();

        vector<vector<int>> diff(n, vector<int>(m, INT_MAX));
        vector<vector<int>> dis = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;

        pq.push({0, 0, 0});
        diff[0][0] = 0;

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int wt = it[0];
            int row = it[1];
            int col = it[2];

            for (auto it : dis) {
                int u = row + it[0];
                int v = col + it[1];

                if(u>=0 && u<n && v>=0 && v<m){

                int totalmax =
                    max(wt, abs(nums[row][col] - nums[u][v]));
                if (diff[u][v] > totalmax) {
                    diff[u][v] = totalmax;
                    pq.push({totalmax, u, v});
                }
                }
            }
        }
        return diff[n - 1][m - 1];
    }
};