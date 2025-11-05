class Solution {
public:
int solve(int i,vector<int>&nums,int target){
   if(i==nums.size() && target==0){
    return 1;
   }
   if(i>=nums.size() && target<0 ){
    return 0;
   }
   if(i>=nums.size()) return 0;

   //Assign +
   int add=solve(i+1,nums,target-nums[i]);
   //Assign -
   int sub=solve(i+1,nums,target+nums[i]);

   return add+sub; 
}
    int findTargetSumWays(vector<int>& nums, int target) {
       return solve(0,nums,target); 
    }
};