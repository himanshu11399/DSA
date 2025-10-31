class Solution {
public:
int find(int i,vector<int>&nums,vector<int>&dp,int n){
   if(i>=n ) return 0;
   if(dp[i]!=-1) return dp[i];

   int inc=nums[i]+find(i+2,nums,dp,n);
   int exc=find(i+1,nums,dp,n);

   return dp[i]=max(inc,exc);
}

int robrange(vector<int>&nums,int start,int end){
    vector<int>dp(nums.size(),-1);
    vector<int>sub(nums.begin()+start,nums.begin()+end+1);
    return find(0,sub,dp,sub.size());
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int ans1=robrange(nums,0,n-2);
        int ans2=robrange(nums,1,n-1);
        return max(ans1,ans2);
    }
};