class Solution {
public:
    int minimumTotal(vector<vector<int>>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0][0];
        }
        vector<vector<int>>dp(n+1,vector<int>(n+1,1e9));
        dp[0][0]=0;


        for(int i=1;i<=n;i++){
            for(int j=1;j<=nums[i-1].size();j++){
                int left=dp[i-1][j-1];
                int right=dp[i-1][j];
                dp[i][j]=min(left,right)+nums[i-1][j-1];
            }
        }
        int minans=INT_MAX;
        for(int i=0;i<=n;i++){
          minans=min(minans,dp[n][i]);
        }
        return minans;
    }
};