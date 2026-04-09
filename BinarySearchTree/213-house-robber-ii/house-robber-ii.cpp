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

    int robber(vector<int>&nums,int start,int end){
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(nums,start,end,dp);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        return max(robber(nums,0,n-2),robber(nums,1,n-1));
    }
};