class Solution {
public:

    bool solve(int i,vector<int>&nums,int target,int sum,vector<vector<int>>&dp){

        if(target==sum) return true;
        if(sum>target || i>=nums.size()) return false;

        if(dp[i][sum]!=-1) return dp[i][sum];

        bool inc=solve(i+1,nums,target,sum+nums[i],dp);
        bool exc=solve(i+1,nums,target,sum,dp);

        return dp[i][sum]=inc||exc;
    }

    bool find(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return solve(0, nums, target,0, dp);
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
         
        
        if (sum % 2 != 0) {
            return false;
        }

            int target = sum / 2;
        return find(nums, target);
    
    }
};