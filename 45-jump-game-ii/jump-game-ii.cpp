class Solution {
public:
    vector<int> dp;

    int solve(vector<int>& nums, int idx) {
        int n = nums.size();
        if (idx == n - 1) {
            return 0;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }
        int minSteps=1e9;

        for (int i = 1; i <= nums[idx]; i++) {
            if(idx+i<n){
                minSteps=min(minSteps,solve(nums,idx+i)+1);
            }
        }
        return dp[idx]=minSteps;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n + 1, -1);
        return solve(nums, 0);
    }
};