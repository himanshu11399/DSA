class Solution {
public:
    vector<int> dp;
    int solve(vector<int>& nums, int idx) {
        if (idx == nums.size() - 1) {
            return 0;
        }
        if (idx >= nums.size()) {
            return 1e9;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }
        int steps = 1e9;
        for (int i = 1; i <= nums[idx]; i++) {
            steps = min(steps, solve(nums, idx + i)+1);
        }
        return dp[idx] = steps;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n + 1, -1);
        int ans=solve(nums, 0);
        return ans!=-1?ans:0;
    }
};