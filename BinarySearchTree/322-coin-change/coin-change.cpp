class Solution {
public:
    int coinChange(vector<int>& nums, int amount) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INT_MAX));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        // start the loop
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                int notake = dp[i-1][j];
                int same=INT_MAX;
                if(j>=nums[i-1]){
                    same=dp[i][j-nums[i-1]];
                    if(same!=INT_MAX){
                        same+=1;
                    }
                }
                dp[i][j]=min(same,notake);
            }
        }

        int ans=dp[n][amount];
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};