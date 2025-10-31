class Solution {
public:

     //Memoization
    // int find(int i, vector<int>& nums, vector<int>& dp) {
    //     if (i >= nums.size())
    //         return 0;
    //     if (dp[i] != -1)
    //         return dp[i];

    //     int robnow = nums[i] + find(i + 2, nums,dp);
    //     int skipnow = find(i + 1, nums,dp);

    //     return dp[i] = max(robnow, skipnow);
    // }
    int rob(vector<int>& nums) {
        // vector<int> dp(nums.size() + 1, -1);
        // return find(0, nums, dp);

        //Tabulation
        int n=nums.size();
        vector<int>dp(n+2,0);
        for(int i=n-1;i>=0;i--){
          dp[i]=max(nums[i]+dp[i+2],dp[i+1]);
        }
        return dp[0];
    }
};