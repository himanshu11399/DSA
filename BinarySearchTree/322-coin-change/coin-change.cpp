class Solution {
public:
vector<vector<int>>dp;
int solve(vector<int>&nums,int i,int amount){
    if(amount==0){
        return 0;
    }
    if(i>=nums.size() || amount<0){
        return INT_MAX;
    }
    if(dp[i][amount]!=-1){
        return dp[i][amount];
    }

    int same=solve(nums,i,amount-nums[i]);
    if(same!=INT_MAX){
        same+=1;
    }
    int notake=solve(nums,i+1,amount);

    return dp[i][amount]=min(same,notake);
}
    int coinChange(vector<int>& nums, int amount) {
      int n=nums.size();
      dp.assign(n+1,vector<int>(amount+1,-1));
      int ans=solve(nums,0,amount);
      if(ans==INT_MAX){
        return -1;
      } 
      return ans; 
    }
};