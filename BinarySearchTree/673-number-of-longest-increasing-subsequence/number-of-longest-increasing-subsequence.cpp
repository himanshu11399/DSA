class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {

        int n = nums.size();
        if(n==0) return 0;
        vector<int> dp(n, 1);
        vector<int> count(n, 1);
        int lis = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {

                if (nums[i] > nums[j]) {
                    if (dp[j] + 1 == dp[i]) {
                        count[i] += count[j];
                    } else if (dp[j] + 1 > dp[i]) {
                        count[i] = count[j];
                        dp[i] = dp[j] + 1;
                    }
                }
            }
            lis = max(lis, dp[i]);
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == lis) {
                result += count[i];
            }
        }

        return result==0?1:result;
    }
};