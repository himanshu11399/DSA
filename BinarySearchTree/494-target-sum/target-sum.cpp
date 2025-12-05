class Solution {
public:
    vector<vector<int>> dp;
    int offset;

    int solve(int i, vector<int>& nums, int target) {
        if(target>offset) return 0;
        if (i==nums.size()) {
            return target==0 ? 1 : 0;
        }

        if (dp[i][target+offset] != -1)
            return dp[i][target+offset];

        
        int add = solve(i + 1, nums, target - nums[i]);
        int subs = solve(i + 1, nums, target + nums[i]);

        return dp[i][target + offset] = add + subs;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
         
        if(sum<abs(target)) return 0;
        offset=sum;
        dp.assign(n + 1, vector<int>(2*sum+1, -1));

        return solve(0, nums, target);
    }
};