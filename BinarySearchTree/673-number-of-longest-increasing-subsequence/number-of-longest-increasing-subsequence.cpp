class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
       int n = nums.size();
        vector<int> dp(n, 1);
        vector<int>count(n,1);
        int ans = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if(dp[j]+1==dp[i]){
                        count[i]+=count[j];
                    }else if(dp[i]<dp[j]+1){
                        count[i]=count[j];
                        dp[i]=dp[j]+1;
                    }
                    ans = max(ans, dp[i]);
                }
                
            }
        }
        
        int res=0;
        for(int i=0;i<n;i++){
            if(dp[i]==ans){
                res+=count[i];
            }
        }
        return res;
    }
};