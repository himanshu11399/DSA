class Solution {
public:
vector<vector<int>>dp;
int solve(vector<vector<int>>&nums,int i,int j){
    if(i>=nums.size() || j>=nums[0].size()){
        return INT_MAX;
    }
    if(i==nums.size()-1 && j==nums[0].size()-1){
        return nums[i][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int right=solve(nums,i,j+1);
    int bottom=solve(nums,i+1,j);

    return dp[i][j]=min(right,bottom)+nums[i][j];
}
    int minPathSum(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       dp.assign(n,vector<int>(m,-1));
       return solve(grid,0,0);
    }
};