class Solution {
public:
    vector<int> dp;
    bool solve(vector<int>& nums, int idx) {
        if (idx == nums.size() - 1) {
            return true;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }
        if(nums[idx]==0){
            return false;
        }
        bool take;
        for (int i = 1; i <= nums[idx]; i++) {
            // take
            take = solve(nums, idx + i);
            if (take==1) {
                return dp[idx] = 1;
            }
        }
        return dp[idx] = 0;
    }
    bool canJump(vector<int>& nums) {
        dp.assign(nums.size() + 1, -1);
        return solve(nums, 0);
    }
};