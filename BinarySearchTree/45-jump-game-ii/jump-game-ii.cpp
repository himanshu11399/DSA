class Solution {
public:
    vector<int> dp;
    int solve(vector<int>&nums, int idx) {
        if (idx == nums.size() - 1) {
            return 0;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }
        int minJumps = INT_MAX;
        for (int i = 1; i <= nums[idx]; i++) {
            if (idx+i < nums.size()) {
                int next=solve(nums,idx+i);
                if(next!=INT_MAX){
                minJumps = min(minJumps, 1+next);
                }
            }
        }
        return dp[idx] = minJumps;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n + 1,-1);
        return solve(nums, 0);
    }
};