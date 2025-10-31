class Solution {
public:
    int find(int i, vector<int>& nums, vector<int>& dp) {
        if (i >= nums.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];

        int robnow = nums[i] + find(i + 2, nums,dp);
        int skipnow = find(i + 1, nums,dp);

        return dp[i] = max(robnow, skipnow);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, -1);
        return find(0, nums, dp);
    }
};