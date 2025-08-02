class Solution {
public:
int sum(vector<int>&nums){
    int ans=0;
    for(int i=0;i<nums.size();i++){
        ans+=nums[i];
    }
    return ans;
}

bool ispossible(vector<int>&nums,int k,int mid){
    int count=1;
    int sum=0;
    for(int i=0;i<nums.size();i++){
       if(nums[i]+sum<=mid){
        sum+=nums[i];
       }else{
        count++;
        if(count>k || nums[i]>mid) return false;
        sum=nums[i];
       }
    }
    return true;
}

    int splitArray(vector<int>& nums, int k) {
      int low=0;
      int high= sum(nums);
      int ans=-1;
      while(low<=high){
        int mid=(low+high)/2;
        if(ispossible(nums,k,mid)){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
      }
    return ans;
    }
};