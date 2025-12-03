class Solution {
public:
vector<int>dp;
int solve(int i,vector<int>&nums){
    if(i>=nums.size()){
        return 0;
    }
    if(dp[i]!=-1) return dp[i];

    //take
    int left=nums[i]+solve(i+2,nums);

    //not take
    int right=solve(i+1,nums);

    return dp[i]= max(left,right);
}
    int rob(vector<int>& nums) {
        dp.assign(nums.size()+1,-1);
       return solve(0,nums); 
    }
};