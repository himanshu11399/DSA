class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, vector<int>& nums, int target,int sum) {
        if(target>sum) return 0;
        if(i==nums.size()) return (target==0);
        if (dp[i][target+sum] != -1) {
            return dp[i][target+sum];
        }

        // Assign +
        int add = solve(i + 1, nums, target - nums[i],sum);
        // Assign -
        int sub = solve(i + 1, nums, target + nums[i],sum);

        return dp[i][target+sum] = (add + sub);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalsum=accumulate(nums.begin(),nums.end(),0);
        if(totalsum<abs(target)) return 0;
        int n = nums.size();
        dp.assign(n, vector<int>(2*totalsum+1, -1));
        return solve(0, nums,target,totalsum);
    }
};