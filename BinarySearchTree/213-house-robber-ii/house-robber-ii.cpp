class Solution {
public:
    int solve(vector<int>& nums, int i, int n,vector<int>&dp) {
        if (i >n) {
            return 0;
        }
        
        if (dp[i] != -1) {
            return dp[i];
        }

        int take = solve(nums, i + 2, n,dp) + nums[i];

        int notake = solve(nums, i + 1, n,dp);

        return dp[i] = max(take, notake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        vector<int>dp(n,-1);
        int first=solve(nums,0,n-2,dp);
        dp.assign(n,-1);
        int second=solve(nums,1,n-1,dp);
        return max(first,second);
    }
};