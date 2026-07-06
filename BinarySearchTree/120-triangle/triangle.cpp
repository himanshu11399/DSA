class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& triangle, int row, int col) {
        if(row==triangle.size()-1){
            return dp[row][col]=triangle[row][col];
        }
        if (dp[row][col] != INT_MAX) {
            return dp[row][col];
        }
        int same = solve(triangle, row + 1, col);
        int diff = solve(triangle, row + 1, col + 1);
        return dp[row][col]= min(same, diff) + triangle[row][col];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        dp.assign(n+1,vector<int>(n+1,INT_MAX));
        return solve(triangle, 0, 0);
    }
};