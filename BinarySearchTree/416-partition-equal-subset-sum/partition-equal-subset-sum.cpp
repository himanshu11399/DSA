class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                // Exclude
                dp[i][j] = dp[i - 1][j];
                
                if (arr[i - 1] <= j) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - arr[i - 1]];
                }
            }
        }
        return dp[n - 1][target];
    }

    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int i = 0; i < nums.size(); i++) {
            total += nums[i];
        }

        if (total % 2 != 0)
            return false;

        int find = total / 2;
        return isSubsetSum(nums, find);
    }
};